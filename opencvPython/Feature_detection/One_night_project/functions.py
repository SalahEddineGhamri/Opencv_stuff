import cv2

refPt = []

def selectCrop(event, x, y, flags, params):
    ''' Selecting using mouse '''
    global refPt, cropState, frame
    if event == cv2.EVENT_LBUTTONDOWN:
        '''left mouse button pressed'''
        refPt = [(x, y)]
        cropState = True
        print "Selecting"
    elif event == cv2.EVENT_LBUTTONUP:
        ''' left mouse button released'''
        refPt.append((x, y))
        cropState = False
        print " Selected "
        drawFrame()

def readCap(cap):
    global frame
    ret, frame = cap.read()
    return ret, frame

def drawFrame():
    global frame, refPt
    cv2.rectangle(frame, refPt[0], refPt[1], (0, 255, 0), 1)

def show():
    global frame, refPt
    if len(refPt)==2 : drawFrame()
    cv2.imshow('Stream', frame)