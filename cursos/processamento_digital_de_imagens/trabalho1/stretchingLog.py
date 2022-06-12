from math import log10

import cv2


img = cv2.imread('./imgs/semC.jpg', 0)

varA = 255 / log10(201)

line, collunm = img.shape

# Fazendo a stretching logatimica
for i in range(0, line):

    for j in range(0, collunm):

        img[i][j] = varA * log10(img[i][j] + 1)


# salvando a imagem
cv2.imwrite('./imgs/outputImgs/ImageStretchingLog.png', img)
