import cv2

img = cv2.imread('./imgs/semC.jpg', 0)

# Definido as partes

limiarA_Entrada = 0
limiarA_Saida = 50

limiarB_Entrada = 125
limiarB_Saida = 200

line, collunm = img.shape

# funcao para calcular o valor do pixel
def calcVarA(pixel, pixelEntrada, pixelSaida):
    return (255 / (pixelSaida - pixelEntrada)) * (pixel - pixelEntrada)


# Fazendo a stretching linear
for i in range(0, line):

    for j in range(0, collunm):

        if limiarA_Saida >= img[i][j] >= limiarA_Entrada:

            img[i][j] = calcVarA(img[i][j], limiarA_Entrada, limiarA_Saida)

        elif limiarB_Saida >= img[i][j] >= limiarB_Entrada:

            img[i][j] = calcVarA(img[i][j], limiarB_Entrada, limiarB_Saida)

# salvando a imagem
cv2.imwrite('./imgs/outputImgs/histoImageStretchingLinearPorPartes.png', img)
