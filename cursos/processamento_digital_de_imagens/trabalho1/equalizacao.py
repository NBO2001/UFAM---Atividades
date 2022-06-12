import cv2
import numpy as np

img = cv2.imread('./imgs/semC.jpg', 0)

equ = cv2.equalizeHist(img)
res = np.hstack((img, equ))

cv2.imwrite('./imgs/outputImgs/imagemEqualizada.png', equ)
