#Scale-space Extrema Detection
import cv2
import numpy as np

img = cv2.imread( "//home//salaheddineghamri//salaheddineghamri.jpg")
gray_img = cv2. cvtColor(img, cv2.COLOR_RGB2GRAY)

sift = cv2.xfeatures2d.SIFT_create()
#kp = sift.detect(gray_img, None)
kp, des = sift.detectAndCompute(gray_img,None)

outputimg = cv2.drawKeypoints(gray_img, kp, None)

cv2.imshow("myimage", outputimg)
print(des.shape) # number of descriptors ? x 128
cv2.waitKey(0)