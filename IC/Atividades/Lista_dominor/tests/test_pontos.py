from src.segunda_parte import pontos


def test_soma_retorna_10():
    assert pontos([(5, 6), (6, 5), (5, 0), (0, 0), (0, 5)]) == 10


def test_soma_retorna_8():
    assert pontos([(5, 6), (6, 5), (5, 0), (0, 0), (0, 5), (5, 3)]) == 8


def test_soma_retorna_11():
    assert (
        pontos([(5, 6), (6, 5), (5, 0), (0, 0), (0, 5), (5, 3), (3, 6)]) == 11
    )
