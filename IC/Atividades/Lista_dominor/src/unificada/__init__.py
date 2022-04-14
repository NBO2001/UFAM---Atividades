# P01: Escreva a função pedrap que associe um par a True se e somente se (sss) o
# par é uma representação válida para uma "pedra" e False caso contrário.
# pedrap(2,7) ==> False pedrap((-3),4) ==> False pedrap(3,4) ==> True
def pedrap(pedra):
    valorA, valorb = pedra
    return 6 >= valorA >= 0 and 6 >= valorb >= 0


# P02: Escreva a função maop que associe uma lista de pares de inteiros
#  a True sss a lista é uma representação válida para a "mão" de um jogador e False caso contrário.
def maop(mao_do_jogador):

    pedras_validas = [
        (ld_pedra_a, ld_pedra_b)
        for ld_pedra_a, ld_pedra_b in mao_do_jogador
        if pedrap((ld_pedra_a, ld_pedra_b))
    ]
    return len(mao_do_jogador) <= 7 and mao_do_jogador == pedras_validas


# P03: Escreva a função carrocap que associe um
# par a True sss o par é uma "carroça" e False caso contrário.
def carrocap(pedra):

    ld_pedra_a, ld_pedra_b = pedra

    return ld_pedra_a == ld_pedra_b


# P04: Escreva a função tem_carroca_p que associe uma "mão" a
#  True sss a mão possuir pelo menos uma carroça e False caso contrário.
def tem_carroca_p(mao_do_jogador):

    return len(tem_carrocas(mao_do_jogador)) != 0


# P05: Escreva a função tem_carrocas que associe a uma "mão" a lista das "carroças" nela contida.
def tem_carrocas(mao_do_jogador):

    return [
        (ld_pedra_a, ld_pedra_b)
        for ld_pedra_a, ld_pedra_b in mao_do_jogador
        if carrocap((ld_pedra_a, ld_pedra_b))
    ]


# P06: Escreva a função pontos que associe uma lista de "pedras"
#  a soma dos pontos das pedras nela contidos.
# Onde os pontos de uma pedra é a soma de suas pontas.
def pontos(pedras):
    if len(pedras) == 0:
        return 0

    return (head(pedras)[0] + head(pedras)[1]) + pontos(tail(pedras))


# P07: Escreva a função garagem que associe uma lista de "pedras" ao maior
#  múltiplo de 5 (cinco), menor ou igual à soma dos pontos nela contidos.


def garagem(pedras):
    soma_das_faces = pontos(pedras)

    return multcinco(soma_das_faces)


# P08: Escreva a função pedra_igual_p que associe dois pares de inteiros a
# True sss representam a mesma pedra e False caso contrário. É bom lembrar
# que a ordem das pontas é irrelevante, assim (2,4) e (4,2) representam a mesma pedra.


def pedra_igual_p(primeira_pedra, segunda_pedra):

    return ordertuple(primeira_pedra) == ordertuple(segunda_pedra)


# P09: Escreva a função ocorre_pedra_p que associe
# uma "pedra" e uma "mão" a True sss a "pedra" ocorre na "mão" e False caso contrário.


def ocorre_pedra_p(pedra, mao_do_jogador):

    return len(lista_de_pedras(pedra, mao_do_jogador)) != 0


# P10: Escreva a função ocorre_valor_p que associe um valor válido para
# "ponta" e uma "mão" e produza True sss o valor ocorre em alguma pedra
# da mão e False caso contrário.


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

        if pontos([pedra]) > pontos([maior_pedra]):
            maior_pedra = pedra
        elif pontos([pedra]) < pontos([maior_pedra]):
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


# P17: Escreva a função mesap que associe uma quadrupla de listas
#  a True sss a quadrupla for uma descrição válida de "mesa".


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


def pontos_marcados(mesa):

    return multcinco(sum_pontas(mesa)) == sum_pontas(mesa)


# P20: Escreva a função pode_jogar_p que associe uma "pedra" e uma "mesa" a
# True sss a pedra possui uma ponta que combina com pelo menos uma das pontas da mesa.


def pode_jogar_p(pedra, mesa):

    ld_a_mesa, ld_b_mesa, ld_c_mesa, ld_d_mesa = mesa
    pontas = ld_a_mesa + ld_b_mesa + ld_c_mesa + ld_d_mesa
    return verify_pontas(pontas, [pedra])


# P21: Escreva a função marca_ponto_p que tenha como entrada uma "pedra"
# e uma "mesa" e produza True sss a pedra pode ser jogada fazendo pontos em uma das pontas da mesa. Lembre-se que as carroças devem ser contadas pelas duas pontas da pedra.


def marca_ponto_p(pedra, mesa):

    indexs = find_indexs(pedra[0], mesa) + find_indexs(pedra[1], mesa)

    return find_to_point(indexs, pedra, mesa)


# P22: Escreva a função maior_ponto que associa uma pedra e uma mesa ao
# número da "ponta" da mesa onde pode ser marcado o maior valor de ponto que será marcado pela pedra.
#  Considere que a em uma "mesa" as pontas são numeradas a partir de zero, da esquerda para a direita.


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


def jogada(mao_do_jogador, mesa):

    return len(mapea_pedra(mao_do_jogador, mesa))


# P26: Escreva a função faz_jogada que associe uma "mão" e uma "mesa" e produza uma nova "mesa" obtida
#  por se jogar marcando o maior número de pontos possível


def faz_jogada(mao_do_jogador, mesa):

    pedra, _, m_ponto_index = mapea_pedra(mao_do_jogador, mesa)[0]
    return joga_pedra(pedra, mesa, m_ponto_index)


# Funções Auxiliares


def multcinco(number):
    if number < 5:
        return 0

    return 5 + multcinco(number - 5)


def ordertuple(element):
    element_a, element_b = element
    if element_a > element_b:
        return (element_b, element_a)
    elif element_a < element_b:
        return (element_a, element_b)
    else:
        return element


def lista_de_pedras(pedra, mao_do_jogador):
    return [
        pedr
        for pedr in mao_do_jogador
        if ordertuple(pedr) == ordertuple(pedra)
    ]


def hasfit(nib, stone):

    stone_a, stone_b = stone

    return stone_a == nib or stone_a == nib or stone_b == nib or stone_b == nib


def pedras_com_encaixe(ponta, mao_do_jogador):
    return [pedra for pedra in mao_do_jogador if hasfit(ponta, pedra)]


def lista_sem_maior(pedra_maior, pedras):
    return [
        pedra
        for pedra in pedras
        if ordertuple(pedra) != ordertuple(pedra_maior)
    ]


def suma(values):
    if len(values) == 0:
        return 0

    return head(values) + suma(tail(values))


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


def sum_pontas(pontas):
    if len(pontas) == 0:
        return 0
    return suma(pontas[0]) + sum_pontas(pontas[1:])


def pontos_marcados_v(mesa):
    if multcinco(sum_pontas(mesa)) == sum_pontas(mesa):
        return sum_pontas(mesa)
    else:
        return 0


def verify_pontas(pontas, mao_do_jogador):

    if len(pontas) == 0:
        return False

    return ocorre_valor_p(head(pontas), mao_do_jogador) or verify_pontas(
        tail(pontas), mao_do_jogador
    )


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
