import os
import tempfile, zipfile
import uuid
from flask import Flask, request, render_template_string, send_file, url_for
from werkzeug.utils import secure_filename
import pandas as pd
import plotly.express as px
from main import load_and_clean, fig_download_over_time, fig_upload_over_time, fig_ping_vs_download, fig_avg_download_by_isp, fig_box_ping_by_isp, fig_geo_scatter, fig_download_upload_over_time

# Add imports for session handling and cleanup
import time, shutil
from flask import session

app = Flask(__name__)
app.config['MAX_CONTENT_LENGTH'] = 16 * 1024 * 1024  # 16MB limit for uploads
# Secret key to enable Flask session cookies
app.secret_key = os.environ.get("FLASK_SECRET_KEY", os.urandom(24))

UPLOAD_FOLDER = tempfile.mkdtemp()
ALLOWED_EXTENSIONS = {'csv'}
zips = {}  # Store dicts with 'zip_path' and 'image_paths' with unique IDs
SESSION_TTL_SECONDS = int(os.environ.get("SESSION_TTL_SECONDS", "900"))  # 15 minutes

def allowed_file(filename):
    return '.' in filename and filename.rsplit('.', 1)[1].lower() in ALLOWED_EXTENSIONS

# Helpers for session-bound cleanup
def _get_sid():
    if 'sid' not in session:
        session['sid'] = str(uuid.uuid4())
    return session['sid']

def _is_expired(meta: dict) -> bool:
    return (time.time() - meta.get('created_at', 0)) > SESSION_TTL_SECONDS

def _cleanup(zip_id: str) -> bool:
    meta = zips.pop(zip_id, None)
    if not meta:
        return False
    temp_dir = meta.get('temp_dir')
    if temp_dir and os.path.isdir(temp_dir):
        try:
            shutil.rmtree(temp_dir, ignore_errors=True)
        except Exception:
            pass
    return True

def _prune_expired():
    now = time.time()
    to_delete = [zid for zid, meta in list(zips.items()) if (now - meta.get('created_at', 0)) > SESSION_TTL_SECONDS]
    for zid in to_delete:
        _cleanup(zid)

@app.route('/', methods=['GET', 'POST'])
def upload_file():
    # Prune old sessions/data on every request
    _prune_expired()
    if request.method == 'POST':
        if 'file' not in request.files:
            return 'No file part'
        file = request.files['file']
        if file.filename == '':
            return 'No selected file'
        if file and allowed_file(file.filename):
            filename = secure_filename(file.filename)
            filepath = os.path.join(UPLOAD_FOLDER, filename)
            file.save(filepath)
            
            # Process the CSV
            df = load_and_clean(filepath)
            
            # Create temp dir for images
            temp_dir = tempfile.mkdtemp()
            image_paths = [
                os.path.join(temp_dir, "01_download_over_time.png"),
                os.path.join(temp_dir, "02_upload_over_time.png"),
                os.path.join(temp_dir, "03_ping_vs_download.png"),
                os.path.join(temp_dir, "04_avg_download_by_isp.png"),
                os.path.join(temp_dir, "05_boxplot_ping_by_isp.png"),
                os.path.join(temp_dir, "06_geo_scatter.png"),
                os.path.join(temp_dir, "07_download_upload_over_time.png")
            ]
            
            # Generate PNG images for ZIP
            fig_download_over_time(df, image_paths[0])
            fig_upload_over_time(df, image_paths[1])
            fig_ping_vs_download(df, image_paths[2])
            fig_avg_download_by_isp(df, image_paths[3])
            fig_box_ping_by_isp(df, image_paths[4])
            fig_geo_scatter(df, image_paths[5])
            fig_download_upload_over_time(df, image_paths[6])
            
            # Create zip file
            zip_path = os.path.join(temp_dir, "results.zip")
            with zipfile.ZipFile(zip_path, 'w') as zipf:
                for img in image_paths:
                    if os.path.exists(img):
                        zipf.write(img, os.path.basename(img))
            
            # Generate unique ID for zip
            zip_id = str(uuid.uuid4())
            # Bind to current session and timestamp for TTL
            sid = _get_sid()
            zips[zip_id] = {
                'zip_path': zip_path,
                'image_paths': image_paths,
                'temp_dir': temp_dir,
                'sid': sid,
                'created_at': time.time()
            }
            
            # Generate interactive Plotly plots
            plots = []

            # Pre-compute y-axis ranges to ensure 0 is visible
            down_max = float(df['download_mbps'].max(skipna=True)) if 'download_mbps' in df else 0.0
            up_max = float(df['upload_mbps'].max(skipna=True)) if 'upload_mbps' in df else 0.0
            y_range_down = [0, max(1.0, down_max * 1.1)]
            y_range_up = [0, max(1.0, up_max * 1.1)]

            # Download over time
            fig1 = px.line(
                df, x='local_time', y='download_mbps', color='isp',
                title='Download speed over time by ISP (Mbps)',
                hover_data=['download_mbps', 'local_time'],
                range_y=y_range_down
            )
            plots.append(fig1.to_html(full_html=False))
            # Upload over time
            fig2 = px.line(
                df, x='local_time', y='upload_mbps', color='isp',
                title='Upload speed over time by ISP (Mbps)',
                hover_data=['upload_mbps', 'local_time'],
                range_y=y_range_up
            )
            plots.append(fig2.to_html(full_html=False))
            # Ping vs Download
            fig3 = px.scatter(df, x='download_mbps', y='ping_ms', title='Ping vs. Download speed', hover_data=['ping_ms', 'download_mbps'])
            plots.append(fig3.to_html(full_html=False))
            # Avg download by ISP
            all_isps = df['isp'].unique()
            avg_series = df.groupby('isp')['download_mbps'].mean().reindex(all_isps, fill_value=0)
            avg_df = avg_series.reset_index().sort_values('download_mbps', ascending=True)
            # Use a tiny epsilon for display so zero isn't invisible, keep the true value for hover/text
            avg_df['display_value'] = avg_df['download_mbps'].clip(lower=0.01)
            avg_df['label'] = avg_df['download_mbps'].round(2)
            fig4 = px.bar(
                avg_df, x='isp', y='display_value',
                title='Average download speed by ISP (Mbps)',
                hover_data=['download_mbps'], text='label',
                range_y=[0, max(1.0, float(avg_df['display_value'].max()) * 1.1)]
            )
            fig4.update_traces(textposition='outside')
            plots.append(fig4.to_html(full_html=False))
            # Box ping by ISP
            fig5 = px.box(df, x='isp', y='ping_ms', title='Ping distribution by ISP (ms)', hover_data=['ping_ms'])
            plots.append(fig5.to_html(full_html=False))
            # Geo scatter
            valid_geo = df.dropna(subset=['latitude', 'longitude', 'download_mbps']).copy()
            if not valid_geo.empty:
                valid_geo['size'] = (valid_geo['download_mbps'] + 1.0) * 0.5
                fig6 = px.scatter(valid_geo, x='longitude', y='latitude', size='size', title='Geographic scatter of tests (size ~ download Mbps)', hover_data=['latitude', 'longitude', 'download_mbps'])
            else:
                fig6 = px.scatter()  # Empty plot if no data
            plots.append(fig6.to_html(full_html=False))
            # Download and upload over time
            df_melt = df.melt(id_vars=['local_time', 'isp'], value_vars=['download_mbps', 'upload_mbps'], var_name='type', value_name='speed')
            y_max_speed = float(df_melt['speed'].max(skipna=True)) if not df_melt.empty else 0.0
            fig7 = px.line(
                df_melt, x='local_time', y='speed', color='isp', line_dash='type',
                title='Download and Upload speed over time by ISP (Mbps)',
                hover_data=['speed', 'local_time'],
                range_y=[0, max(1.0, y_max_speed * 1.1)]
            )
            plots.append(fig7.to_html(full_html=False))
            
            # Render page with interactive plots and download link
            return render_template_string('''
            <!doctype html>
            <html lang="en">
            <head>
                <meta charset="UTF-8">
                <meta name="viewport" content="width=device-width, initial-scale=1.0">
                <title>Results</title>
                <style>
                    body { font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif; background: linear-gradient(135deg, #667eea 0%, #764ba2 100%); color: #333; margin: 0; padding: 20px; }
                    .container { max-width: 1200px; margin: 0 auto; background: rgba(255, 255, 255, 0.95); padding: 30px; border-radius: 15px; box-shadow: 0 10px 30px rgba(0,0,0,0.3); }
                    h1 { text-align: center; color: #4a5568; margin-bottom: 20px; }
                    a { display: inline-block; background: linear-gradient(135deg, #667eea 0%, #764ba2 100%); color: white; padding: 12px 24px; text-decoration: none; border-radius: 8px; margin-bottom: 30px; transition: transform 0.2s; }
                    a:hover { transform: translateY(-2px); }
                    h2 { color: #4a5568; border-bottom: 2px solid #667eea; padding-bottom: 10px; }
                    .plot { margin: 20px 0; padding: 20px; background: #f7fafc; border-radius: 10px; box-shadow: 0 5px 15px rgba(0,0,0,0.1); }
                </style>
            </head>
            <body>
                <div class="container">
                    <h1>Network Speed Analysis Results</h1>
                    <a href="{{ url_for('download_zip', zip_id=zip_id) }}">Download ZIP</a>
                    <h2>Interactive Plots:</h2>
                    {% for plot in plots %}
                        <div class="plot">{{ plot|safe }}</div>
                    {% endfor %}
                </div>
                <script>
                    // Attempt cleanup when tab becomes hidden or is closing
                    (function() {
                        var url = "{{ url_for('cleanup', zip_id=zip_id) }}";
                        function sendCleanup() {
                            try {
                                if (navigator.sendBeacon) {
                                    navigator.sendBeacon(url, new Blob([], {type: 'text/plain'}));
                                } else {
                                    fetch(url, {method: 'POST', keepalive: true});
                                }
                            } catch (e) {}
                        }
                        document.addEventListener('visibilitychange', function() {
                            if (document.visibilityState === 'hidden') sendCleanup();
                        });
                        window.addEventListener('beforeunload', sendCleanup);
                    })();
                </script>
            </body>
            </html>
            ''', zip_id=zip_id, plots=plots)
    
    return render_template_string('''
    <!doctype html>
    <html lang="en">
    <head>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <title>Upload CSV</title>
        <style>
            body { font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif; background: linear-gradient(135deg, #667eea 0%, #764ba2 100%); color: #333; margin: 0; padding: 0; display: flex; justify-content: center; align-items: center; height: 100vh; }
            .container { background: rgba(255, 255, 255, 0.9); padding: 40px; border-radius: 15px; box-shadow: 0 10px 30px rgba(0,0,0,0.3); text-align: center; max-width: 500px; }
            h1 { color: #4a5568; margin-bottom: 20px; }
            form { margin-top: 20px; }
            .upload-area { position: relative; border: 2px dashed #cbd5e0; padding: 40px; border-radius: 10px; background: #f7fafc; cursor: pointer; transition: all 0.3s; display: inline-block; width: 100%; box-sizing: border-box; }
            .upload-area:hover { border-color: #667eea; background: #edf2f7; }
            input[type="file"] { position: absolute; top: 0; left: 0; width: 100%; height: 100%; opacity: 0; cursor: pointer; }
            #file-name { margin-top: 10px; font-size: 14px; color: #666; }
            button { background: linear-gradient(135deg, #667eea 0%, #764ba2 100%); color: white; border: none; padding: 12px 24px; border-radius: 8px; cursor: pointer; font-size: 16px; transition: transform 0.2s; }
            button:hover { transform: translateY(-2px); }
        </style>
    </head>
    <body>
        <div class="container">
            <h1>Upload Network Speed CSV</h1>
            <form method="post" enctype="multipart/form-data">
                <label for="file" class="upload-area">
                    <p>Click to select a CSV file</p>
                    <input type="file" name="file" id="file" required onchange="showFileName()">
                </label>
                <p id="file-name"></p>
                <br><br>
                <button type="submit">Upload & Analyze</button>
            </form>
        </div>
        <script>
            function showFileName() {
                const fileInput = document.getElementById('file');
                const fileName = document.getElementById('file-name');
                fileName.textContent = fileInput.files[0] ? 'Selected: ' + fileInput.files[0].name : '';
            }
        </script>
    </body>
    </html>
    ''')

@app.route('/download/<zip_id>')
def download_zip(zip_id):
    _prune_expired()
    meta = zips.get(zip_id)
    sid = session.get('sid')
    if not meta or _is_expired(meta):
        _cleanup(zip_id)
        return 'File not found', 404
    if not sid or meta.get('sid') != sid:
        return 'Unauthorized or expired', 403
    return send_file(meta['zip_path'], as_attachment=True, download_name='network_speed_results.zip')

@app.route('/image/<zip_id>/<int:index>')
def serve_image(zip_id, index):
    _prune_expired()
    meta = zips.get(zip_id)
    sid = session.get('sid')
    if not meta or _is_expired(meta):
        _cleanup(zip_id)
        return 'Image not found', 404
    if not sid or meta.get('sid') != sid:
        return 'Unauthorized or expired', 403
    if 0 <= index < len(meta['image_paths']):
        img_path = meta['image_paths'][index]
        if os.path.exists(img_path):
            return send_file(img_path, mimetype='image/png')
    return 'Image not found', 404

@app.route('/cleanup/<zip_id>', methods=['POST'])
def cleanup(zip_id):
    # Only allow the same session to trigger cleanup; always return 204 to avoid info leaks
    meta = zips.get(zip_id)
    if meta and session.get('sid') == meta.get('sid'):
        _cleanup(zip_id)
    return ('', 204)

if __name__ == '__main__':
    app.run(debug=True)
