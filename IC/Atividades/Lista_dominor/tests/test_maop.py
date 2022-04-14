from src.unificada import maop


def test_mao_valida():
    assert (
        maop([(1, 5), (2, 5), (6, 4), (0, 0), (3, 6), (3, 4), (3, 6)]) == True
    )


def test_mao_invalida_com_pedra_a_mais():
    assert (
        maop([(1, 5), (2, 5), (6, 4), (0, 0), (3, 6), (3, 4), (2, 5), (3, 5)])
        == False
    )


def test_mao_invalida_valor_errado():
    assert (
        maop([(1, 5), (2, 5), (6, 4), (0, 0), (3, 6), (3, 4), (3, 8), (5, 8)])
        == False
    )
