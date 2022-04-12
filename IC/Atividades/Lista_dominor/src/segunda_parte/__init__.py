from functools import reduce

from src.primeira_parte import tem_carrocas


# P06: Escreva a função pontos que associe uma lista de "pedras"
#  a soma dos pontos das pedras nela contidos.
# Onde os pontos de uma pedra é a soma de suas pontas.
def pontos(pedras):
    if len(pedras) == 0:
        return 0

    return soma_faces(0, pedras[0]) + pontos(pedras[1:])


# P07: Escreva a função garagem que associe uma lista de "pedras" ao maior
#  múltiplo de 5 (cinco), menor ou igual à soma dos pontos nela contidos.

# Função auxiliar


def soma_faces(soma_das_faces, pedra_element):

    ld_a_pedra, ld_b_pedra = pedra_element

    return (ld_a_pedra + ld_b_pedra) + soma_das_faces


def multcinco(number):
    if number < 5:
        return 0

    return 5 + multcinco(number - 5)


def garagem(pedras):
    soma_das_faces = reduce(soma_faces, pedras, 0)

    return multcinco(soma_das_faces)


# P08: Escreva a função pedra_igual_p que associe dois pares de inteiros a
# True sss representam a mesma pedra e False caso contrário. É bom lembrar
# que a ordem das pontas é irrelevante, assim (2,4) e (4,2) representam a mesma pedra.

# Função Auxiliar para ordenar as tuplas:


def ordertuple(element):
    element_a, element_b = element
    if element_a > element_b:
        return (element_b, element_a)
    elif element_a < element_b:
        return (element_a, element_b)
    else:
        return element


def pedra_igual_p(primeira_pedra, segunda_pedra):

    return ordertuple(primeira_pedra) == ordertuple(segunda_pedra)


# P09: Escreva a função ocorre_pedra_p que associe
# uma "pedra" e uma "mão" a True sss a "pedra" ocorre na "mão" e False caso contrário.

# Funcaçao auxiliar
def lista_de_pedras(pedra, mao_do_jogador):
    return [
        pedr
        for pedr in mao_do_jogador
        if ordertuple(pedr) == ordertuple(pedra)
    ]


def ocorre_pedra_p(pedra, mao_do_jogador):

    return len(lista_de_pedras(pedra, mao_do_jogador)) != 0


# P10: Escreva a função ocorre_valor_p que associe um valor válido para
# "ponta" e uma "mão" e produza True sss o valor ocorre em alguma pedra
# da mão e False caso contrário.

# Funcao auxiliar
def hasfit(nib, stone):

    stone_a, stone_b = stone

    return stone_a == nib or stone_a == nib or stone_b == nib or stone_b == nib


def pedras_com_encaixe(ponta, mao_do_jogador):
    return [pedra for pedra in mao_do_jogador if hasfit(ponta, pedra)]


def ocorre_valor_p(ponta, mao_do_jogador):

    return len(pedras_com_encaixe(ponta, mao_do_jogador)) != 0


# P11: Escreva a função ocorre_pedra que associe a um valor e uma "mão",
# uma lista contendo as pedras da "mão" que possuem o valor dado.
def ocorre_pedra(valor_ponta, mao_do_jogador):

    return [
        (pedra_a, predra_b)
        for pedra_a, predra_b in mao_do_jogador
        if pedra_a == valor_ponta or predra_b == valor_ponta
    ]


# P12: Escreva a função pedra_maior que associe uma "mão" a pedra de maior valor na "mão" dada.
#  Uma pedra p1 é maior que uma outra p2 sss a soma das pontas de p1 for maior que a soma das pontas de p2.
def pedra_maior(mão_do_jogador):

    maior_pedra = (0, 0)

    for pedra in mão_do_jogador:

        if soma_faces(0, pedra) > soma_faces(0, maior_pedra):
            maior_pedra = pedra
        elif soma_faces(0, pedra) < soma_faces(0, maior_pedra):
            maior_pedra = maior_pedra
        else:
            maior_pedra = pedra

    return maior_pedra


# P13: Escreva a função ocorre_valor_q que associe um valor e
# uma "mão" e produza o número de pedras na mão que possuem o valor dado.
def ocorre_valor_q(face, mao_do_jogador):

    return len(ocorre_pedra(face, mao_do_jogador))


# P14: Escreva a função ocorre_carroca_q que associe uma mão à quantidade de carroças nela existentes.
def ocorre_carroca_q(mao_do_jogador):
    return len(tem_carrocas(mao_do_jogador))


# Funcao auxiliar
def lista_sem_maior(pedra_maior, pedras):
    return [
        pedra
        for pedra in pedras
        if ordertuple(pedra) != ordertuple(pedra_maior)
    ]


# P15: Escreva a função tira_maior que associe uma mão a uma
# lista similar à "mão" de onde foi extraída a pedra de maior ponto.
def tira_maior(mao_do_jogador):

    maior_pedra = pedra_maior(mao_do_jogador)

    return lista_sem_maior(maior_pedra, mao_do_jogador)


# P16: Escreva a função tira_maior_v que associe um valor e uma "mão" à lista similar à "mão"
# de onde se extraiu a pedra de maior pontos de um determinado valor para ponta.
def tira_maior_v(ponta, mao_do_jogador):

    maior_pedra = pedra_maior(pedras_com_encaixe(ponta, mao_do_jogador))

    return lista_sem_maior(maior_pedra, mao_do_jogador)
