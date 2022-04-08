from src.segunda_parte import pontos


def test_soma_retorna_5_tuplas():
    assert pontos([(5, 6), (6, 5), (5, 0), (0, 0), (0, 5)]) == 32


def test_soma_retorna_3_tuplas():
    assert pontos([(5, 6), (6, 5), (5, 0)]) == 27


def test_resultado_feito_em_sala():
    assert pontos([(4, 2), (5, 5), (0, 3), (1, 4)]) == 24
