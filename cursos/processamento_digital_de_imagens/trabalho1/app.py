from math import log10

import cv2
import numpy as np
from matplotlib import pyplot as plt

# limiar = 100
# arryHistogram = [0]*256

img1 = cv2.imread('./imgs/semC.jpg', 0)
plt.hist(img1.ravel(), 256, [0, 256])
plt.savefig('./imgs/semCHis.png')

cv2.imwrite('imgbc.png', img1)

# img1 = cv2.imread('./imgs/outputImgs/histoImageStretchingLinear.png')
# img2 = cv2.imread('./imgs/outputImgs/histoImageStretchingLinearPorPartes.png')
# img3 = cv2.imread('./imgs/outputImgs/imagemBinary.png')   # imagemTonsDeCinza
# img4 = cv2.imread('./imgs/outputImgs/imagemTonsDeCinza.png')   #
# img5 = cv2.imread('./imgs/outputImgs/imagemEqualizada.png')   #

# plt.hist(img1.ravel(), 256, [0, 256])
# plt.savefig('./imgs/histos/histoImageStretchingLinear.png')

# plt.hist(img2.ravel(), 256, [0, 256])
# plt.savefig('./imgs/histos/histoImageStretchingLinearPorPartes.png')

# plt.hist(img3.ravel(), 256, [0, 256])
# plt.savefig('./imgs/histos/imagemBinary.png')

# plt.hist(img4.ravel(), 256, [0, 256])
# plt.savefig('./imgs/histos/imagemTonsDeCinza.png')

# plt.hist(img5.ravel(), 256, [0, 256])
# plt.savefig('./imgs/histos/imagemEqualizada.png')


# resized = cv2.resize(img,(900,500))
# resized2 = cv2.resize(img4,(900,500))
# # resized3 = cv2.resize(img2,(900,500))
# resized4 = cv2.resize(img3,(900,500))

# cv2.imshow("Campo Ufam", resized)
# cv2.imshow("Campo Log ", resized2)
# # cv2.imshow("Campo Ufam3", resized3)
# cv2.imshow("Campo Linear", resized4)


# cv2.waitKey(0)
# cv2.destroyAllWindows()
