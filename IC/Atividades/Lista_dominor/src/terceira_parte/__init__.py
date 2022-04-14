import pdb
from regex import P
from src.primeira_parte import pedrap
from src.segunda_parte import multcinco, ocorre_pedra_p, ocorre_valor_p


def suma(values):
    if len(values) == 0:
        return 0

    return head(values) + suma(tail(values))


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


def sum_pontas(pontas):
    if len(pontas) == 0:
        return 0
    return suma(pontas[0]) + sum_pontas(pontas[1:])


def pontos_marcados_v(mesa):
    if multcinco(sum_pontas(mesa)) == sum_pontas(mesa):
        return sum_pontas(mesa)
    else:
        return 0


def pontos_marcados(mesa):

    return multcinco(sum_pontas(mesa)) == sum_pontas(mesa)


# P20: Escreva a função pode_jogar_p que associe uma "pedra" e uma "mesa" a
# True sss a pedra possui uma ponta que combina com pelo menos uma das pontas da mesa.

# Função auxiliar
def verify_pontas(pontas, mao_do_jogador):

    if len(pontas) == 0:
        return False

    return ocorre_valor_p(head(pontas), mao_do_jogador) or verify_pontas(
        tail(pontas), mao_do_jogador
    )


def pode_jogar_p(pedra, mesa):

    ld_a_mesa, ld_b_mesa, ld_c_mesa, ld_d_mesa = mesa
    pontas = ld_a_mesa + ld_b_mesa + ld_c_mesa + ld_d_mesa
    return verify_pontas(pontas, [pedra])


# P21: Escreva a função marca_ponto_p que tenha como entrada uma "pedra"
# e uma "mesa" e produza True sss a pedra pode ser jogada fazendo pontos em uma das pontas da mesa. Lembre-se que as carroças devem ser contadas pelas duas pontas da pedra.

# função auxiliar


def ponta_que_entra(pedra, ponta):
    if pedra[0] == ponta[0] and pedra[0] != pedra[1]:
        return [pedra[1]]
    elif pedra[0] == ponta[0] and pedra[0] == pedra[1]:
        return [pedra[0], pedra[1]]
    else:
        return [pedra[0]]


def find_indexs(lado_a, mesa):
    indece = []
    for ind in range(0, len(mesa)):
        if len(mesa[ind]) != 0 and lado_a == mesa[ind][0]:
            indece.append(ind)

    return indece


def find_to_point(indexs, pedra, mesa):
    if len(indexs) == 0:
        return False

    return pontos_marcados(
        joga_pedra(pedra, mesa, head(indexs))
    ) or find_to_point(tail(indexs), pedra, mesa)


def marca_ponto_p(pedra, mesa):

    indexs = find_indexs(pedra[0], mesa) + find_indexs(pedra[1], mesa)

    return find_to_point(indexs, pedra, mesa)


# P22: Escreva a função maior_ponto que associa uma pedra e uma mesa ao
# número da "ponta" da mesa onde pode ser marcado o maior valor de ponto que será marcado pela pedra. Considere que a em uma "mesa" as pontas são numeradas a partir de zero, da esquerda para a direita.


def maior_ponto(pedra, mesa):

    indexs = find_indexs(pedra[0], mesa) + find_indexs(pedra[1], mesa)

    maior_ponto = 0
    maior_ponto_index = 0

    for inx in indexs:
        if maior_ponto <= pontos_marcados_v(joga_pedra(pedra, mesa, inx)):
            maior_ponto = pontos_marcados_v(joga_pedra(pedra, mesa, inx))
            maior_ponto_index = inx

    return maior_ponto_index


# P23: Escreva a função joga_pedra que associe uma "pedra", uma "mesa" e
# um número de "ponta" da mesa a uma nova mesa obtida ao se jogar a "pedra" na "ponta" indicada.


def joga_pedra(pedra, mesa, index):

    valores_anteriores = mesa[:index]
    if len(mesa) != index + 1:
        valores_posteriores = mesa[(index + 1) :]
    else:
        valores_posteriores = ()

    return (
        valores_anteriores
        + (ponta_que_entra(pedra, mesa[index]),)
        + valores_posteriores
    )


# P24: Escreva a função jogap que associe uma "mão" e uma "mesa" e produza
# True sss existe pelo menos uma pedra na mão que possa ser jogada em pelo menos uma ponta da mesa. Caso contrário produza False.


def jogap(mao_do_jogador, mesa):
    if len(mao_do_jogador) == 0:
        return False

    return len(
        find_indexs(head(mao_do_jogador)[0], mesa)
        + find_indexs(head(mao_do_jogador)[1], mesa)
    ) != 0 or jogap(tail(mao_do_jogador), mesa)


# P25: Escreva a função jogada que associe uma "mão" e uma "mesa" ao número
# a pedra na mão e número da ponta na mesa onde pode ser feita a jogada que marque mais ponto.
#  Considere inclusive jogada onde não há marcação de ponto.


def m_mais_ponto(pedra, mesa):

    indexs = find_indexs(pedra[0], mesa) + find_indexs(pedra[1], mesa)

    maior_ponto = 0
    maior_ponto_index = 0

    for inx in indexs:
        if maior_ponto <= sum_pontas(joga_pedra(pedra, mesa, inx)):
            maior_ponto = sum_pontas(joga_pedra(pedra, mesa, inx))
            maior_ponto_index = inx

    return (maior_ponto, maior_ponto_index)


def mapea_pedra(mao_do_jogador, mesa):

    mior_ponto = 0

    pedras = []

    for pedra in mao_do_jogador:
        m_ponto, m_ponto_index = m_mais_ponto(pedra, mesa)
        if m_ponto > mior_ponto:
            mior_ponto = m_ponto
            pedras = [(pedra, m_ponto, m_ponto_index)]
        elif m_ponto == mior_ponto:
            pedras.append((pedra, m_ponto, m_ponto_index))
    
    return pedras


def jogada(mao_do_jogador, mesa):

    
    return len(mapea_pedra(mao_do_jogador, mesa))


# P26: Escreva a função faz_jogada que associe uma "mão" e uma "mesa" e produza uma nova "mesa" obtida
#  por se jogar marcando o maior número de pontos possível


def faz_jogada(mao_do_jogador, mesa):

    pedra, _, m_ponto_index = mapea_pedra(mao_do_jogador, mesa)[0]
    return joga_pedra(pedra, mesa, m_ponto_index)
