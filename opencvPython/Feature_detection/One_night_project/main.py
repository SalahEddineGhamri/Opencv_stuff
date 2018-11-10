# this one night project code.
import cv2
import functions

#read video stream
cap = cv2.VideoCapture(0)
cv2.namedWindow("Stream")
cv2.setMouseCallback("Stream", functions.selectCrop)
# Setup the termination criteria, either 10 iteration or move by atleast 1 pt
term_crit = ( cv2.TERM_CRITERIA_EPS | cv2.TERM_CRITERIA_COUNT, 10, 1 )

while True:
    functions.readCap(cap)
    if functions.selected:
        functions.trackUpdate()
    functions.drawIt()
    key = cv2.waitKey(1) & 0xFF
    if key == ord('q'): 
        break

cap.release()
cv2.destroyAllWindows()