import requests
import time
import random

# URL đích
url = "https://nbk.homes/problem/colorhsg3/submit"

# Headers từ request gốc
headers = {
    "Accept": "text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.7",
    "Accept-Encoding": "gzip, deflate, br, zstd",
    "Accept-Language": "en,vi-VN;q=0.9,vi;q=0.8,en-US;q=0.7",
    "Cache-Control": "max-age=0",
    "Content-Type": "application/x-www-form-urlencoded",
    "Origin": "https://nbk.homes",
    "Referer": "https://nbk.homes/problem/colorhsg3/submit",
    "Sec-CH-UA": '"Not;A=Brand";v="99", "Google Chrome";v="139", "Chromium";v="139"',
    "Sec-CH-UA-Mobile": "?0",
    "Sec-CH-UA-Platform": '"Windows"',
    "Sec-Fetch-Dest": "document",
    "Sec-Fetch-Mode": "navigate",
    "Sec-Fetch-Site": "same-origin",
    "Sec-Fetch-User": "?1",
    "Upgrade-Insecure-Requests": "1",
    "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/139.0.0.0 Safari/537.36"
}

# Cookies
cookies = {
    "csrftoken": "Eoou4zWRTP3TgPMISRPHaLRg78WuPPY1kofbQ4BgTqpOEUSLYmEURpKoFSytip3N",
    "sessionid": "f45rmmyk4e8pa8jkzaofa0iw7i2ia7p1"
}

# CSRF token trong payload
csrf_token = "c8Q2gUhCrwm2BoRJ1mIRgvinv4ArBSVYS8HJ2pW1r7IXZtXM7Rx4X9bv3Ocq4s0K"

while True:
    # Sinh code Python ngẫu nhiên
    random_number = random.randint(1, 200)
    source_code = f"import random\nn = {random_number}\nprint(n)"

    # Payload
    payload = {
        "csrfmiddlewaretoken": csrf_token,
        "source": source_code,
        "language": "8"
    }

    # Gửi request
    response = requests.post(url, headers=headers, cookies=cookies, data=payload, allow_redirects=False)

    print(f"Gửi thành công: {random_number}, status={response.status_code}, location={response.headers.get('Location')}")
    
    time.sleep(2)
