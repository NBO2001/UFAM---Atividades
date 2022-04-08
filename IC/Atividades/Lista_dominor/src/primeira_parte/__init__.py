def pedrap(pedra):
    valorA, valorb = pedra
    return 6 >= valorA >= 0 and 6 >= valorb >= 0


def maop(mao_do_jogador):

    pedras_validas = [
        (ld_pedra_a, ld_pedra_b)
        for ld_pedra_a, ld_pedra_b in mao_do_jogador
        if pedrap((ld_pedra_a, ld_pedra_b))
    ]
    return len(mao_do_jogador) <= 7 and mao_do_jogador == pedras_validas


def carrocap(pedra):

    ld_pedra_a, ld_pedra_b = pedra

    return ld_pedra_a == ld_pedra_b


def tem_carroca_p(mao_do_jogador):

    return len(tem_carrocas(mao_do_jogador)) != 0


def tem_carrocas(mao_do_jogador):

    return [
        (ld_pedra_a, ld_pedra_b)
        for ld_pedra_a, ld_pedra_b in mao_do_jogador
        if carrocap((ld_pedra_a, ld_pedra_b))
    ]
