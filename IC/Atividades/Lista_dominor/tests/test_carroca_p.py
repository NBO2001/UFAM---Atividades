from src.unificada import tem_carroca_p


def test_mao_com_carroca():
    assert (
        tem_carroca_p([(1, 5), (2, 5), (6, 4), (0, 0), (3, 6), (3, 4), (3, 6)])
        == True
    )


def test_mao_Sem_carroca():
    assert (
        tem_carroca_p([(1, 5), (2, 5), (6, 4), (0, 4), (3, 6), (3, 4), (3, 6)])
        == False
    )


def test_mao_invalida():
    assert (
        tem_carroca_p([(1, 5), (2, 5), (6, 4), (3, 6), (3, 4), (3, 6)])
        == False
    )
