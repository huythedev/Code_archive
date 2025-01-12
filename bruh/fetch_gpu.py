import GPUtil
import subprocess

def get_gpu_info():
    gpu_details = []

    try:
        # Attempt 1: Detect discrete GPUs with GPUtil
        gpus = GPUtil.getGPUs()
        if gpus:
            gpu_details = [f"{gpu.name} (Total Memory: {gpu.memoryTotal}MB)" for gpu in gpus]

    except Exception as e:
        gpu_details.append(f"Error with GPUtil: {e}")

    try:
        # Attempt 2: Integrated GPUs with DirectX Diagnostics (dxdiag)
        if not gpu_details:
            result = subprocess.run(
                ["dxdiag", "/t", "dxdiag.txt"], capture_output=True, text=True
            )
            with open("dxdiag.txt", "r") as file:
                for line in file.readlines():
                    if "Card name" in line:
                        gpu_details.append(line.split(":")[1].strip())
    except Exception as e:
        gpu_details.append(f"Error detecting integrated GPU: {e}")

    return "; ".join(gpu_details) if gpu_details else "No GPU Detected"

if __name__ == "__main__":
    print(get_gpu_info())