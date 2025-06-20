import base64
from PIL import Image
from io import BytesIO
import pytesseract

# Base64 string of your CAPTCHA
b64_string = """
iVBORw0KGgoAAAANSUhEUgAAAEgAAAAcCAIAAABNkG7xAAAACXBIWXMAAA7EAAAOxAGVKw4bAAAA4UlEQVRYhe2XXQ7EIAiE7WaPxP1P4KH2gcQYBvzBbBsavqcGYWTUutur1lreyOfpBv5FGotGGotGGovG111JRBjkX0V1qI2KBDW4K4j4jQ2kMdh3xs+tYyLq8x2CKncfxd5VmW3ICUs7JiYW69dGrYMhzKxPdyI437GmwhQ4V2rcakJkYsmuoMU1zthabEy2yvs9GUyxLoicXh4DBk34Pim2Vtl/efCF5mjCqnILqkyMqS+VuK9x4mkTatWJIDJ5x0QfDB56EV83hmk+QWTJWERe+18xjUUjjUUjjUUjjUXjB9IIr3XH7gxpAAAAAElFTkSuQmCC
""".strip()

# Decode image
image_data = base64.b64decode(b64_string)
image = Image.open(BytesIO(image_data))

# Optional: preprocess image for better OCR accuracy (e.g. convert to grayscale)
gray_image = image.convert("L")  # L = grayscale

# OCR: extract text
text = pytesseract.image_to_string(
    gray_image,
    config='--psm 8 -c tessedit_char_whitelist=ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789'
)

print("CAPTCHA Text:", text.strip())
