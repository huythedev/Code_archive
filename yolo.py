from ultralytics import YOLO
import cv2
from ultralytics.utils.plotting import Annotator

model = YOLO('yolov8n.pt')
cap = cv2.VideoCapture(0)
cap.set(8, 1920)  # Set width to Full HD
cap.set(9, 1080)  # Set height to Full HD

while True:
    _, img = cap.read()

    results = model.predict(img)

    annotator = Annotator(img)  # Move annotator initialization outside the loop

    for r in results:
        boxes = r.boxes
        for box in boxes:
            b = box.xyxy[0]
            c = int(box.cls)  # Ensure class index is an integer
            annotator.box_label(b, model.names[c])

    img = annotator.result()
    img_resized = cv2.resize(img, (1920, 1080))
    cv2.imshow('YOLO V8 Detection', img_resized)

    if cv2.waitKey(1) & 0xFF == ord(' '):  # Use space bar to exit
        break

cap.release()
cv2.destroyAllWindows()