import cv2
import numpy as np
from matplotlib import pyplot as plt

# Abrindo a imagem
img = cv2.imread('./imgs/semC.jpg', 0)

# Salvando a imagem em tons de cinza
cv2.imwrite('./imgs/outputImgs/imagemTonsDeCinza.png', img)

# Array para amarzenar os pixels
arryHistogram = [0] * 256

# Pegando as dimessões da imagem
line, collum = img.shape

# Contanto os pixels
for i in range(0, line):
    for j in range(0, collum):

        arryHistogram[img[i][j]] += 1


fig, ax = plt.subplots()

xdata = np.arange(len(arryHistogram))

ax.plot(xdata, arryHistogram)
# Plot some data on the axes.

# Salvando o historograma
plt.savefig('./imgs/histos/histoImageOriginal.png')

# Definindo um limiar
limiar = 125

# binarizando a imagem
for i in range(0, line):

    for j in range(0, collum):

        if img[i][j] >= limiar:

            img[i][j] = 255

        else:

            img[i][j] = 0

cv2.imwrite('./imgs/outputImgs/imagemBinary.png', img)
