import cv2 

cap = cv2.VideoCapture('policechase')

while True:
    _,frame = cap.read()
    cv2.imshow('frame', frame)
    cv2.waitKey(0)

cap.realse()
cv2.destroyAllWindows()