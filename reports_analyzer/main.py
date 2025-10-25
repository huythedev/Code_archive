#!/usr/bin/env python3
"""
Network Speed Report Grapher

What it does
------------
- Loads your CSV (same columns as the sample you sent)
- Cleans column names and parses timestamps
- Converts Kbps -> Mbps exactly as: Mbps = Kbps / 1000
- Picks `ispNameRaw` when present, else `ispName` for ISP grouping
- Outputs:
  01_download_over_time.png
  02_upload_over_time.png
  03_ping_vs_download.png
  04_avg_download_by_isp.png
  05_boxplot_ping_by_isp.png
  06_geo_scatter.png
  07_download_upload_over_time.png
- Writes cleaned_speedtests.csv for reuse

Usage
-----
python network_speed_analysis.py /path/to/your.csv out_dir
"""

import os
import sys
import argparse
import pandas as pd
import numpy as np
import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt
import matplotlib.dates as mdates

def normalize_columns(cols):
    m = {}
    for c in cols:
        nc = (c.replace('"', '')
               .strip()
               .lower()
               .replace(' ', '_')
               .replace('(kbps)', 'kbps')
               .replace('(ms)', 'ms'))
        m[c] = nc
    return m

def load_and_clean(csv_path: str) -> pd.DataFrame:
    # Read; treat common placeholders as NA
    df = pd.read_csv(csv_path, na_values=["n/a", "N/A", "", "null", "NULL"])

    # Normalize names
    df.rename(columns=normalize_columns(df.columns), inplace=True)

    # Unify IP column names
    df.columns = [c.replace("ipaddress", "ipv4").replace("ipv6_address", "ipv6") for c in df.columns]

    # Parse time: input is ISO with 'Z' (UTC). Convert to user's local TZ.
    # pd.to_datetime(..., utc=True) -> tz-aware UTC; then tz_convert
    if "resultdate" in df.columns:
        df["resultDate"] = pd.to_datetime(df["resultdate"], utc=True, errors="coerce")
        df.drop(columns=["resultdate"], inplace=True)
    elif "resultDate" in df.columns:
        df["resultDate"] = pd.to_datetime(df["resultDate"], utc=True, errors="coerce")
    else:
        raise ValueError("Could not find resultDate column")

    df["local_time"] = df["resultDate"].dt.tz_convert("Asia/Ho_Chi_Minh")

    # Cast numerics
    for col in ["latitude", "longitude", "download_kbps", "upload_kbps", "ping_ms", "jitter"]:
        if col in df.columns:
            df[col] = pd.to_numeric(df[col], errors="coerce")

    # Fill empty download/upload with 0 before processing
    for col in ["download_kbps", "upload_kbps"]:
        if col in df.columns:
            df[col] = df[col].fillna(0)

    # Derived Mbps (explicit SI conversion)
    df["download_mbps"] = df["download_kbps"] / 1000.0
    df["upload_mbps"] = df["upload_kbps"] / 1000.0

    # Canonical ISP field
    ispn = "ispname" if "ispname" in df.columns else None
    ispraw = "ispnameraw" if "ispnameraw" in df.columns else None
    if ispraw and ispn:
        df["isp"] = df[ispraw].fillna(df[ispn]).fillna("Unknown")
    elif ispraw:
        df["isp"] = df[ispraw].fillna("Unknown")
    elif ispn:
        df["isp"] = df[ispn].fillna("Unknown")
    else:
        df["isp"] = "Unknown"

    # Sort by local time
    df = df.sort_values("local_time")

    return df

def fig_download_over_time(df: pd.DataFrame, out_path: str):
    plt.figure(figsize=(24, 12))
    for isp, g in df.groupby("isp"):
        plt.plot(g["local_time"], g["download_mbps"], marker="o", linestyle="-", label=isp)
    plt.title("Download speed over time by ISP (Mbps)")
    plt.xlabel("Local time (Asia/Ho_Chi_Minh)")
    plt.ylabel("Download (Mbps)")
    plt.legend()
    plt.gca().xaxis.set_major_formatter(mdates.DateFormatter('%Y-%m-%d %H:%M'))
    plt.gcf().autofmt_xdate()
    plt.tight_layout()
    plt.savefig(out_path, dpi=150)
    plt.close()

def fig_upload_over_time(df: pd.DataFrame, out_path: str):
    plt.figure(figsize=(24, 12))
    for isp, g in df.groupby("isp"):
        plt.plot(g["local_time"], g["upload_mbps"], marker="o", linestyle="-", label=isp)
    plt.title("Upload speed over time by ISP (Mbps)")
    plt.xlabel("Local time (Asia/Ho_Chi_Minh)")
    plt.ylabel("Upload (Mbps)")
    plt.legend()
    plt.gca().xaxis.set_major_formatter(mdates.DateFormatter('%Y-%m-%d %H:%M'))
    plt.gcf().autofmt_xdate()
    plt.tight_layout()
    plt.savefig(out_path, dpi=150)
    plt.close()

def fig_ping_vs_download(df: pd.DataFrame, out_path: str):
    plt.figure(figsize=(16, 14))
    plt.scatter(df["download_mbps"], df["ping_ms"])
    plt.title("Ping vs. Download speed")
    plt.xlabel("Download (Mbps)")
    plt.ylabel("Ping (ms)")
    plt.grid(True, linestyle="--", alpha=0.4)
    plt.tight_layout()
    plt.savefig(out_path, dpi=150)
    plt.close()

def fig_avg_download_by_isp(df: pd.DataFrame, out_path: str):
    plt.figure(figsize=(18, 14))
    all_isps = df['isp'].unique()
    avg_by_isp = df.groupby("isp")["download_mbps"].mean().reindex(all_isps, fill_value=0).sort_values(ascending=True)

    # Plot with tiny epsilon for zeros so they aren't invisible
    eps = 0.01
    plot_vals = avg_by_isp.mask(avg_by_isp <= 0, eps)
    plot_vals.plot(kind="barh")
    plt.title("Average download speed by ISP (Mbps)")
    plt.xlabel("Download (Mbps)")
    plt.ylabel("ISP")
    plt.xlim(left=0)

    # Annotate with the true values
    max_val = float(plot_vals.max()) if len(plot_vals) else eps
    offset = max(max_val * 0.01, eps * 1.5)
    for i, (true_val, disp_val) in enumerate(zip(avg_by_isp.values, plot_vals.values)):
        plt.text(disp_val + offset, i, f"{true_val:.2f}", va="center", fontsize=9)

    plt.tight_layout()
    plt.savefig(out_path, dpi=150)
    plt.close()

def fig_box_ping_by_isp(df: pd.DataFrame, out_path: str):
    plt.figure(figsize=(21, 14))
    isp_labels, isp_ping = [], []
    for isp, g in df.groupby("isp"):
        vals = g["ping_ms"].dropna().values
        if vals.size > 0:
            isp_labels.append(isp)
            isp_ping.append(vals)
    if not isp_ping:
        return
    plt.boxplot(isp_ping, labels=isp_labels, vert=True, showfliers=True)
    plt.title("Ping distribution by ISP (ms)")
    plt.xlabel("ISP")
    plt.ylabel("Ping (ms)")
    plt.tight_layout()
    plt.savefig(out_path, dpi=150)
    plt.close()

def fig_geo_scatter(df: pd.DataFrame, out_path: str):
    plt.figure(figsize=(16, 14))
    valid_geo = df.dropna(subset=["latitude", "longitude", "download_mbps"]).copy()
    if valid_geo.empty:
        return
    sizes = (valid_geo["download_mbps"] + 1.0) * 0.5
    plt.scatter(valid_geo["longitude"], valid_geo["latitude"], s=sizes)
    plt.title("Geographic scatter of tests (size ~ download Mbps)")
    plt.xlabel("Longitude")
    plt.ylabel("Latitude")
    plt.tight_layout()
    plt.savefig(out_path, dpi=150)
    plt.close()

def fig_download_upload_over_time(df: pd.DataFrame, out_path: str):
    plt.figure(figsize=(24, 12))
    for isp, g in df.groupby("isp"):
        plt.plot(g["local_time"], g["download_mbps"], marker="o", linestyle="-", label=f"{isp} Download")
        plt.plot(g["local_time"], g["upload_mbps"], marker="s", linestyle="--", label=f"{isp} Upload")
    plt.title("Download and Upload speed over time by ISP (Mbps)")
    plt.xlabel("Local time (Asia/Ho_Chi_Minh)")
    plt.ylabel("Speed (Mbps)")
    plt.legend()
    plt.gca().xaxis.set_major_formatter(mdates.DateFormatter('%Y-%m-%d %H:%M'))
    plt.gcf().autofmt_xdate()
    plt.tight_layout()
    plt.savefig(out_path, dpi=150)
    plt.close()

def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("csv_path", help="Input CSV path")
    ap.add_argument("out_dir", nargs="?", default="net-report-output", help="Directory to write figures & cleaned CSV")
    args = ap.parse_args()

    os.makedirs(args.out_dir, exist_ok=True)
    df = load_and_clean(args.csv_path)

    # Save cleaned dataset for verification/reuse
    cleaned_csv = os.path.join(args.out_dir, "cleaned_speedtests.csv")
    df.to_csv(cleaned_csv, index=False)

    # Produce figures
    fig_download_over_time(df, os.path.join(args.out_dir, "01_download_over_time.png"))
    fig_upload_over_time(df,   os.path.join(args.out_dir, "02_upload_over_time.png"))
    fig_ping_vs_download(df,   os.path.join(args.out_dir, "03_ping_vs_download.png"))
    fig_avg_download_by_isp(df,os.path.join(args.out_dir, "04_avg_download_by_isp.png"))
    fig_box_ping_by_isp(df,    os.path.join(args.out_dir, "05_boxplot_ping_by_isp.png"))
    fig_geo_scatter(df,        os.path.join(args.out_dir, "06_geo_scatter.png"))
    fig_download_upload_over_time(df, os.path.join(args.out_dir, "07_download_upload_over_time.png"))

    # Optional: print a small summary to stdout (derived only from your CSV)
    summary = (df.groupby("isp", dropna=False)
                 .agg(tests=("isp", "size"),
                      avg_down_mbps=("download_mbps", "mean"),
                      med_down_mbps=("download_mbps", "median"),
                      avg_up_mbps=("upload_mbps", "mean"),
                      med_up_mbps=("upload_mbps", "median"),
                      med_ping_ms=("ping_ms", "median"))
                 .round(2)
              )
    print("\nSummary by ISP (computed from the input CSV):")
    print(summary)

if __name__ == "__main__":
    main()
