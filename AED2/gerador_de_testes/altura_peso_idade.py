from random import randrange, random
from math import trunc

def peso_generator():
    return float( f"{(randrange(10,120) + (random())):.2f}")

def altura_generator():
    valor = float( f"{(randrange(0,1) + (random() % 99)):.2f}")
    valor = valor if valor > 0.25 else (valor + 1)

    valor = float( f"{(valor):.2f}")
    return valor

def idade_generator():
    return randrange(10,95)

