import cv2

img = cv2.imread('./imgs/semC.jpg', 0)

# funcao para calcular o valor do pixel
def calcVarA(pixel, pixelEntrada, pixelSaida):
    return (255 / (pixelSaida - pixelEntrada)) * (pixel - pixelEntrada)


line, collunm = img.shape

# Fazendo a stretching linear
for i in range(0, line):
    for j in range(0, collunm):

        pixelVal = calcVarA(img[i][j], 2, 200)

        img[i][j] = pixelVal if pixelVal <= 255 else 255

# salvando a imagem
cv2.imwrite('./imgs/outputImgs/histoImageStretchingLinear.png', img)
