import cv2
import numpy as np

refPt = []
PenHist = 0
ret = []
selected = False
i = 0

def selectCrop(event, x, y, flags, params):
    ''' Selecting using mouse '''
    global refPt, frame, selected, i
    if event == cv2.EVENT_LBUTTONDOWN:
        '''left mouse button pressed'''
        selected = False
        refPt = [(x, y)]
        print "Selecting zone"
    elif event == cv2.EVENT_LBUTTONUP:
        ''' left mouse button released'''
        refPt.append((x, y))
        getPen()
        print "Zone selected"

def readCap(cap):
    global frame
    ret, frame = cap.read()
    return ret, frame

def drawFrame():
    global frame, refPt
    cv2.rectangle(frame, refPt[0], refPt[1], (0, 255, 0), 1)

def show():
    global frame, refPt

def getPen():
    #get Pen for two time figure out why later//
    global Pen, frame, refPt, ret, selected, trackWindow
    clone = frame.copy()
    if len(refPt)==2:
        x1, y1 = refPt[0][0], refPt[0][1]
        x2, y2 = refPt[1][0], refPt[1][1]
        #x = true_value if condition else false_value
        w = x1 - x2 if x1 > x2 else x2 - x1
        h = y1 - y2 if y1 > y2 else y2 - y1
        c = x1 if x1 < x2 else x2 
        r = y1 if y1 < y2 else y2
        trackWindow = (c, r, w, h)
        Pen = clone[r:r+h, c:c+w]
        hsvPen =  cv2.cvtColor(Pen, cv2.COLOR_BGR2HSV)
        mask = cv2.inRange(hsvPen, np.array([0, 60, 32]), np.array([180,255,255]))
        PenHist = cv2.calcHist([hsvPen],[0],mask,[180],[0,180])
        cv2.normalize(PenHist,PenHist,0,255,cv2.NORM_MINMAX)
        selected = True

# Setup the termination criteria, either 10 iteration or move by atleast 1 pt
term_crit = ( cv2.TERM_CRITERIA_EPS | cv2.TERM_CRITERIA_COUNT, 1, 1 )

def trackUpdate():
    global PenHist, trackWindow, ret, frame
    print(trackWindow)
    hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
    dst = cv2.calcBackProject([hsv],[0], PenHist,[0,180],1)
    ret, trackWindow = cv2.CamShift(dst, trackWindow, term_crit)

def drawIt():
    global frame, ret, selected, trackWindow
    if selected:
        x, y, w, h = trackWindow
        cv2.rectangle(frame, (x,y), (x+w,y+h), (0, 255, 0),1)
        cv2.imshow( 'Stream', frame)
    else:
        if len(refPt)==2 : drawFrame()
        cv2.imshow('Stream', frame)
