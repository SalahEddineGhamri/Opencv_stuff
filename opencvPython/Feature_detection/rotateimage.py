#code to rotate images
import cv2
import matplotlib.pyplot as plt

img = cv2.imread("//home//salaheddineghamri//salaheddineghamri.jpg", 1)
rows, cols, RGB = img.shape
#rotation matrix 2D:
M = cv2.getRotationMatrix2D((cols/2, rows/2), 90, 1)
rotImg = cv2.warpAffine(img, M, (cols, rows))

#turn images to gray:
img1 = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
img2 = cv2.cvtColor(rotImg, cv2.COLOR_BGR2GRAY)

# get keypoints from both images:
Sift = cv2.xfeatures2d.SIFT_create()
key1, des1 = Sift.detectAndCompute(img1, None)
key2, des2 = Sift.detectAndCompute(img2, None)

# create BFMatcher object
bf = cv2.BFMatcher()

# Match descriptors.
matches = bf.knnMatch(des1,des2, k=2)

# Apply ratio test
good = []
for m,n in matches:
    if m.distance < 0.75*n.distance:
        good.append([m])

# cv2.drawMatchesKnn expects list of lists as matches.
img3 = cv2.drawMatchesKnn(img1,key1,img2,key2, good, None, flags=2)

plt.imshow(img3),plt.show()
