# this one night project code.
import cv2
import functions

#read video stream
cap = cv2.VideoCapture(0)
cv2.namedWindow("Stream")
cv2.setMouseCallback("Stream", functions.selectCrop)

while True:
    functions.readCap(cap)
    functions.show()
    key = cv2.waitKey(1) & 0xFF
    if key == ord('q'): 
        break

cap.release()
cv2.destroyAllWindows()