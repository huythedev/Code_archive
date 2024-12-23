import GPUtil
import subprocess
import psutil
from pynvml import nvmlInit, nvmlDeviceGetHandleByIndex, nvmlDeviceGetName, nvmlShutdown

def get_gpu_info():
    try:
        # First attempt: Use GPUtil for discrete GPUs
        gpu_info = GPUtil.getGPUs()
        gpu_details = [
            f"{gpu.name} (Total Memory: {gpu.memoryTotal}MB)" for gpu in gpu_info
        ]
        if gpu_details:
            return "; ".join(gpu_details)
        
        # Second attempt: Use pynvml for NVIDIA GPUs
        nvmlInit()
        gpu_details = []
        for i in range(nvmlDeviceGetCount()):
            handle = nvmlDeviceGetHandleByIndex(i)
            name = nvmlDeviceGetName(handle).decode("utf-8")
            gpu_details.append(name)
        nvmlShutdown()
        if gpu_details:
            return "; ".join(gpu_details)

        # Fallback: Check integrated GPUs with DirectX diagnostics
        result = subprocess.run(
            ["dxdiag", "/t", "dxdiag.txt"], capture_output=True, text=True
        )
        with open("dxdiag.txt", "r") as file:
            for line in file.readlines():
                if "Card name" in line:
                    return line.split(":")[1].strip()

        return "No GPU Detected"
    except Exception as e:
        return f"Error detecting GPU: {e}"
    
if __name__ == "__main__":
    print(get_gpu_info())
