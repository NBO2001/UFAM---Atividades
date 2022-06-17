from utils import qualValorEmDeci, bsum, convertInDecimal, binaryRandom
from time import localtime, time_ns


fortuna_infortunio = binaryRandom()

print(f"Seu valor inicial é {convertInDecimal( fortuna_infortunio ,2,True)}")

sua_sorte = binaryRandom(seed=time_ns())

binariosSomados = bsum(fortuna_infortunio,sua_sorte, 4)

fortuna_infortunio = binariosSomados

print(f"Você ganhou {convertInDecimal( fortuna_infortunio ,2,True)}")

continue_is = input("Deseja girar a roda? [S / N]")

for tentativa in range(0,3):

    if (continue_is == 'S'):

        sua_sorte = binaryRandom(seed=time_ns())

        binariosSomados = bsum(fortuna_infortunio,sua_sorte, 4)

        fortuna_infortunio = binariosSomados

        print(f"Você ganhou {convertInDecimal( fortuna_infortunio ,2,True)}")

        print(f"Você tem {3-(tentativa+1)} tentativas")
        if (3-(tentativa+1)) != 0:
        
            continue_is = input("Deseja girar a roda? [S / N]")
    else:
        break
