import cv2

img = cv2.imread('./imgs/semC.jpg', 0)

# variavéis para o calculo 255/256

varA = (200) / (255**1.6)

line, collunm = img.shape

# Fazendo a stretching quadratica
for i in range(0, line):

    for j in range(0, collunm):

        valuePixel = varA * (img[i][j] ** 2)

        img[i][j] = valuePixel if valuePixel <= 255 else 255


# salvando a imagem
cv2.imwrite('./imgs/outputImgs/ImageStretchingQuadratica.png', img)
