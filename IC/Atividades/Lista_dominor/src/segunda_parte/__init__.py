from functools import reduce


def pontos(pedras):

    # Vou pegar o primeiro elemento da lista de pedras
    # E o ultimo elemento da lista de pedras

    primeira_pedra_a, primeira_pedra_b = pedras[0]
    ultima_pedra_a, ultima_pedra_b = pedras[-1]

    return primeira_pedra_a + ultima_pedra_b


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


def pedra_igual_p(duas_pedras):
    primeira_pedra, segunda_pedra = duas_pedras

    return ordertuple(primeira_pedra) == ordertuple(segunda_pedra)


# P09: Escreva a função ocorre_pedra_p que associe
# uma "pedra" e uma "mão" a True sss a "pedra" ocorre na "mão" e False caso contrário.
def ocorre_pedra_p(pedra, mao_do_jogador):

    return len(ocorre_pedra(pedra, mao_do_jogador)) != 0


# P10: Escreva a função ocorre_valor_p que associe um valor válido para
# "ponta" e uma "mão" e produza True sss o valor ocorre em alguma pedra
# da mão e False caso contrário.
def ocorre_valor_p(pedras):
    pass


# P11: Escreva a função ocorre_pedra que associe a um valor e uma "mão",
# uma lista contendo as pedras da "mão" que possuem o valor dado.
def ocorre_pedra(pedra, mao_do_jogador):

    return [
        pedr
        for pedr in mao_do_jogador
        if ordertuple(pedr) == ordertuple(pedra)
    ]


# P12: Escreva a função pedra_maior que associe uma "mão" a pedra de maior valor na "mão" dada.
#  Uma pedra p1 é maior que uma outra p2 sss a soma das pontas de p1 for maior que a soma das pontas de p2.
def pedra_maior(pedras):
    pass


# P13: Escreva a função ocorre_valor_q que associe um valor e
# uma "mão" e produza o número de pedras na mão que possuem o valor dado.
def ocorre_valor_q(pedras):
    pass


# P14: Escreva a função ocorre_carroca_q que associe uma mão à quantidade de carroças nela existentes.
def ocorre_carroca_q(pedras):
    pass


# P15: Escreva a função tira_maior que associe uma mão a uma
# lista similar à "mão" de onde foi extraída a pedra de maior ponto.
def tira_maior(pedras):
    pass


# P16: Escreva a função tira_maior_v que associe um valor e uma "mão" à lista similar à "mão"
# de onde se extraiu a pedra de maior pontos de um determinado valor para ponta.
def tira_maior_v(pedras):
    pass
