from src.primeira_parte import pedrap

# P17: Escreva a função mesap que associe uma quadrupla de listas
#  a True sss a quadrupla for uma descrição válida de "mesa".


def head(lista_itens):
    if len(lista_itens) == 0:
        return []
    else:
        return lista_itens[0]


def tail(lista_itens):
    if len(lista_itens) == 0:
        return []
    else:
        return lista_itens[1:]


def pedrap_is(pedra):

    if len(pedra) == 0:
        return True
    return pedrap((head(pedra), head(pedra))) and pedrap_is(tail(pedra))


def mesap(mesa):

    if len(mesa) != 4:
        return False

    lado_a, lado_b, lado_c, lado_d = mesa

    return (
        pedrap_is(lado_a)
        and pedrap_is(lado_b)
        and pedrap_is(lado_c)
        and pedrap_is(lado_d)
    )


# P18: Escreva a função carroca_m_p que
# associe uma mesa a True sss pelo menos uma das pontas for carroça.


def carroca_m_p(mesa):
    if len(mesa) == 0:
        return False

    lado_a, lado_b, lado_c, lado_d = mesa

    return (
        len(lado_a) == 2
        or len(lado_b) == 2
        or len(lado_c) == 2
        or len(lado_b) == 2
    )


# P19: Escreva a função pontos_marcados que associe uma mesa ao o número
# de pontos a serem marcados se a soma das pontas for múltiplo de cinco e zero em caso contrário.
#
# P20: Escreva a função pode_jogar_p que associe uma "pedra" e uma "mesa" a
# True sss a pedra possui uma ponta que combina com pelo menos uma das pontas da mesa.
#
# P21: Escreva a função marca_ponto_p que tenha como entrada uma "pedra"
# e uma "mesa" e produza True sss a pedra pode ser jogada fazendo pontos em uma das pontas da mesa. Lembre-se que as carroças devem ser contadas pelas duas pontas da pedra.
#
# P22: Escreva a função maior_ponto que associa uma pedra e uma mesa ao
# número da "ponta" da mesa onde pode ser marcado o maior valor de ponto que será marcado pela pedra. Considere que a em uma "mesa" as pontas são numeradas a partir de zero, da esquerda para a direita.
#
# P23: Escreva a função joga_pedra que associe uma "pedra", uma "mesa" e
# um número de "ponta" da mesa a uma nova mesa obtida ao se jogar a "pedra" na "ponta" indicada.
#
# P24: Escreva a função jogap que associe uma "mão" e uma "mesa" e produza
# True sss existe pelo menos uma pedra na mão que possa ser jogada em pelo menos uma ponta da mesa. Caso contrário produza False.
#
# P25: Escreva a função jogada que associe uma "mão" e uma "mesa" ao número
# a pedra na mão e número da ponta na mesa onde pode ser feita a jogada que marque mais ponto.
#  Considere inclusive jogada onde não há marcação de ponto.
#
# P26: Escreva a função faz_jogada que associe uma "mão" e uma "mesa" e produza uma nova "mesa" obtida
#  por se jogar marcando o maior número de pontos possível
