from src.primeira_parte import maop


def test_mao_valida():
    assert (
        maop([(1, 5), (2, 5), (6, 4), (0, 0), (3, 6), (3, 4), (3, 6)]) == True
    )


def test_mao_invalida_sem_um_valor():
    assert maop([(1, 5), (2, 5), (6, 4), (0, 0), (3, 6), (3, 4)]) == False


def test_mao_invalida_valor_errado():
    assert (
        maop([(1, 5), (2, 5), (6, 4), (0, 0), (3, 6), (3, 4), (3, 8)]) == False
    )
