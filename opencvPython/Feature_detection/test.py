import cv2
from matplotlib import pyplot as plt
img = cv2.imread("//home//salaheddineghamri//salaheddineghamri.jpg", 1)
cv2.imshow('g', img)
cv2.waitKey(0)