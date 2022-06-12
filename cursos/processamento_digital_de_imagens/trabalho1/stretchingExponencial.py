import cv2

img = cv2.imread('./imgs/semC.jpg', 0)

# variáveis

e = 2.718281828459045

varA = (200) / (255**8)

line, collunm = img.shape

# Fazendo a stretching Exponencial
for i in range(0, line):

    for j in range(0, collunm):

        valorPixel = varA * (e ** img[i][j])

        img[i][j] = valorPixel if valorPixel <= 255 else 255


# salvando a imagem
cv2.imwrite('./imgs/outputImgs/ImageStretchingExponencial.png', img)
