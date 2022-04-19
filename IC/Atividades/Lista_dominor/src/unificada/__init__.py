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

    if multcinco(sum_pontas(mesa)) == sum_pontas(mesa):
        return sum_pontas(mesa)
    else:
        return 0


# P20: Escreva a função pode_jogar_p que associe uma "pedra" e uma "mesa" a
# True sss a pedra possui uma ponta que combina com pelo menos uma das pontas da mesa.


def pode_jogar_p(pedra, mesa):

    ld_a_mesa, ld_b_mesa, ld_c_mesa, ld_d_mesa = mesa
    pontas = ld_a_mesa + ld_b_mesa + ld_c_mesa + ld_d_mesa
    return verify_pontas(pontas, [pedra])


# P21: Escreva a função marca_ponto_p que tenha como entrada uma "pedra"
# e uma "mesa" e produza True sss a pedra pode ser jogada fazendo pontos em uma das
# pontas da mesa. Lembre-se que as carroças devem ser contadas pelas duas pontas da pedra.


def marca_ponto_p(pedra, mesa):

    indexs = find_indexs(pedra[0], mesa) + find_indexs(pedra[1], mesa)

    return find_to_point(indexs, pedra, mesa) != 0


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

    bigger_stones = mapea_pedra(mao_do_jogador, mesa)

    return (bigger_stones[0][1], bigger_stones[0][3])


# P26: Escreva a função faz_jogada que associe uma "mão" e uma "mesa" e produza uma nova "mesa" obtida
#  por se jogar marcando o maior número de pontos possível


def faz_jogada(mao_do_jogador, mesa):

    pedra, _, _, m_ponto_index = mapea_pedra(mao_do_jogador, mesa)[0]
    return joga_pedra(pedra, mesa, m_ponto_index)


# P27: Escreva a função lista_de_jogadas que associa uma lista de pedras
# com True, sss ela representa corretamentamente uma sequência de jogadas.


def lista_de_jogadas(pedras):
    if len(pedras) <= 1:
        return True

    return pedras[0][1] == pedras[1][0] and lista_de_jogadas(tail(pedras))


# P28: Escreva a função mesa2p que associa um valor com True, sss ele representa
#  corretamentamente a descrição de uma mesa no formato 2 com sua representação no formato 1.
def mesa2p(mesa_formato_1, mesa_formato_2):
    olde_table = conversor_de_mesa(mesa_formato_2)
    return iquals_tables(mesa_formato_1, olde_table)


# P29: Escreva a função marca_ponto_2 que associa uma mesa no formato 2 com o número de pontos marcados.
def marca_ponto_2(mesa_formato_2):
    old_table = conversor_de_mesa(mesa_formato_2)
    return pontos_marcados(old_table)


# P30: Escreva a função faz_jogada_2 que associa uma pedra, uma mesa e um
# número de ponta na mesa, com a mesa obtida após jogar a pedra na ponta indicada.
def faz_jogada_2(pedra, mesa_formato_2, nun_ponta):
    old_table = conversor_de_mesa(mesa_formato_2)
    new_ponta = joga_pedra(pedra, old_table, nun_ponta)

    new_stone = order_stone(new_ponta[nun_ponta], pedra)
    ponta_subs = mesa_formato_2[nun_ponta + 1]

    anterior = mesa_formato_2[: nun_ponta + 1]
    new_path = [new_stone] + ponta_subs
    posterior = mesa_formato_2[nun_ponta + 2 :]

    return anterior + [new_path] + posterior


# P31: Escreva a função pedra_de_ponto que associa uma mesa no formato 1 com uma pedra que pode marcar ponto.
def pedra_de_ponto(mesa_formato_1):
    stones_with_encaixe = pedras_de_ponto(mesa_formato_1)
    if len(stones_with_encaixe) != 0:
        return stones_with_encaixe[0]
    else:
        return []


# P32: Escreva a função pedras_de_ponto que associa uma mesa no formato 1 com a lista de pedras que podem marcar ponto.
def pedras_de_ponto(mesa_formato_1):
    stones_with_encaixe = []

    for stone in get_all_stones():

        if pode_jogar_p(stone, mesa_formato_1) and marca_ponto_p(
            stone, mesa_formato_1
        ):
            stones_with_encaixe.append(stone)

    return stones_with_encaixe


# P33: Escreva a função pedra_de_maior_ponto que associa uma mesa no formato 1 com a pedra que marcar mais pontos.
def pedra_de_maior_ponto(mesa_formato_1):

    stones_with_encaixe = pedras_de_ponto(mesa_formato_1)
    pedras_pont = mapea_pedra(stones_with_encaixe, mesa_formato_1)

    fisrt_value = pedras_pont[0]

    stone, _, _, _ = fisrt_value

    return stone


# P34: Escreva a função pedras_fora_p que associa uma mesa no formato 2 e uma pedra com True sss ela ainda não foi jogada.
def pedras_fora_p(mesa_formato_2, pedra):

    stones_list = merge_stones(mesa_formato_2)

    return find_stone_in_list(pedra, stones_list) != True


#P35: Defina a função somavet que determine a soma de dois vetores x e y, de origem no ponto (0,0)
#  e situados no primeiro quadrante do plano cartesiano.
def somavet(vetor_1, vetor_2):
    return ( vetor_1[0] + vetor_2[0], vetor_1[1] + vetor_2[1])

#P36: Defina a função sumdo que dado um número inteiro positivo n, construa uma lista com todos
#  os pares cuja soma de elementos é igual a n.
def sumdo(n):

    end_list = []
    
    for contador in range(0,n,2):
        if suma(end_list) < n:
            end_list.append(contador)

    return end_list

#P37: Dada uma lista L, contendo um número igual de números inteiros pares e ímpares (em qualquer ordem),
#  defina a função alterna que, quando avaliada, produz uma lista na qual esses números pares e ímpares encontram-se alternados.
def alterna_numeros(lista_baguncada):

    if len(lista_baguncada) == 0: return []

    pair_numbers = filter_numbers(ispair, lista_baguncada)
    odd_numbers = filter_numbers(isodd, lista_baguncada)
    return [head(pair_numbers)] + [head(odd_numbers)] + alterna_numeros(tail(pair_numbers) + tail(odd_numbers))

    

#P38: Defina a função intersec que a partir de duas listas de 
# elementos distintos, determina a interseção entre elas.
def intersec():
    pass

#P39: Defina a função uni que dadas duas listas
#  de elementos distintos, determina a união entre elas.
def uni():
    pass


#P40: Verificar se uma cadeia é uma palavra (apenas letras). e_palav(cadeia)
def e_palav(cadeia):
    pass
#P41: Verificar se uma cadeia é um número inteiro positivo. e_int(cadeia)
def e_int(cadeia):
    pass
#P42: Dado um verbo regular e um tempo do modo indicativo, 
# produzir as conjugações. conjuga(verbo,tempo) 
# conjuga("jogar","presente") 
# ==> [ "eu jogo", "tu jogas", "ele joga", "nos jogamos", "vos jogais", "eles jogam"]
def conjuga(verbo,tempo):
    pass

#P43: Verificar se uma cadeia representa um número real (escrito na notação com ponto decimal). 
# e_float(cadeia) e_float("3") ==> False e_float("3.") ==> False e_float("ab") ==> False e_float("3.5") ==> True
def e_float(cadeia):
    pass

#P44: Determinar a cadeia formada pela parte inteira e a cadeia
#  formada pela parte fracionária da representação de um número através de cadeia de caracteres.
#  Se o número for inteiro, 
# a parte fracionária será zero.
#  int_frac(cadeia) int_frac("324.8765") ==> ("324","8765") int_frac("4586") ==> ("4586","0")
def int_frac(cadeia):
    pass
#P45: Dado um número de dois algarismo, produzir a cadeia de caracteres que seja a sua representação literal. 
# traduz(numero) traduz(35) ==> "trinta e cinco" traduz(3) ==> "tres" traduz(15) ==> "quinze"

def traduz(numero):

    if numero <= 9:
        return get_number_0_9(numero)
    elif 19 >= numero > 9:
        return get_number_10_19(numero)
    elif 90 >= numero > 19:
        
        numero_inteiro = (numero//10)*10
        numero_fracionado = numero%10
        if numero_fracionado != 0:
            traducao_a = get_number_20_90(numero_inteiro) 
            traducao_b = get_number_0_9(numero_fracionado)
            return f'{traducao_a} e {traducao_b}'
        else:
            return get_number_20_90(numero_inteiro)


## Funções Auxiliares


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


def tail(lista_itens, position=1):
    if len(lista_itens) == 0:
        return []
    else:
        return lista_itens[position:]


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

    for idn in range(0, len(mao_do_jogador)):
        m_ponto, m_ponto_index = m_mais_ponto(mao_do_jogador[idn], mesa)
        if m_ponto > mior_ponto:
            mior_ponto = m_ponto
            pedras = [(mao_do_jogador[idn], idn, m_ponto, m_ponto_index)]
        elif m_ponto == mior_ponto:
            pedras.append((mao_do_jogador[idn], idn, m_ponto, m_ponto_index))

    return pedras


def conversor_de_mesa(mesa):

    return conversor_de_pontas(tail(mesa))


def conversor_de_pontas(pontas):

    if len(pontas) == 0:
        return ()
    elif len(pontas) != 0 and len(pontas[0]) == 0:
        return ([],)

    return coversor_de_pedras(head(pontas)[0]) + conversor_de_pontas(
        tail(pontas)
    )


def coversor_de_pedras(pedra):
    if len(pedra) == 2:
        if pedra[0] == pedra[1]:
            return ([pedra[0], pedra[1]],)
        else:
            return ([pedra[0]],)
    else:
        return ([],)


def iquals_tables(table_one, table_two):

    if len(table_one) != len(table_two):
        return False
    elif len(table_one) == 0:
        return True

    return head(table_one) == head(table_two) and iquals_tables(
        tail(table_one), tail(table_two)
    )


def find_stone_in_list(stone, stones_list):
    if len(stones_list) == 0:
        return False

    return ordertuple(stone) == ordertuple(
        head(stones_list)
    ) or find_stone_in_list(stone, tail(stones_list))


def merge_stones(mesa_formato_2):
    if len(mesa_formato_2) == 0:
        return []

    return head(mesa_formato_2) + merge_stones(tail(mesa_formato_2))


def order_stone(ponta, stone):
    if ponta[0] == stone[0]:
        return stone
    else:
        return (stone[1], stone[0])


def get_all_stones():
    return [
        (0, 0),
        (1, 1),
        (2, 2),
        (3, 3),
        (4, 4),
        (5, 5),
        (6, 6),
        (0, 1),
        (0, 2),
        (0, 3),
        (0, 4),
        (0, 5),
        (0, 6),
        (1, 2),
        (1, 3),
        (1, 4),
        (1, 5),
        (1, 6),
        (2, 3),
        (2, 4),
        (2, 5),
        (2, 6),
        (3, 4),
        (3, 5),
        (3, 6),
        (4, 5),
        (4, 6),
        (5, 6),
    ]

def get_number_0_9(number):
    numeros_0_a_9 = ["zero",
    "um",
    "dois",
    "tres",
    "quatro",
    "cinco",
    "seis",
    "sete",
    "oito",
    "nove"]
    return numeros_0_a_9[number]

def get_number_10_19(number):
    index = number - 10
    numeros_10_a_19 = ["dez",
    "onze",
    "doze",
    "treze",
    "quatorze ou catorze",
    "quinze",
    "dezesseis",
    "dezessete",
    "dezoito",
    "dezenove"]

    return numeros_10_a_19[index]

def get_number_20_90(numeber):

    index = int((numeber-20)/10)

    numbers = ["vinte",
    "trinta",
    "quarenta",
    "cinquenta",
    "sessenta",
    "setenta",
    "oitenta",
    "noventa",]
    return numbers[index]

def filter_numbers(condition, list_numbers):
    
    if len(list_numbers) == 0: return []
    
    elif condition(head(list_numbers)):

        return [head(list_numbers) ]+ filter_numbers(condition,tail(list_numbers))
    else:
        return filter_numbers(condition,tail(list_numbers))

def ispair(number):
    return number%2 == 0

def isodd(number):
    return number%2 != 0