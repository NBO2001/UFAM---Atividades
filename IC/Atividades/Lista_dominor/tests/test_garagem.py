from src.unificada import garagem


def test_garagem_25_pontos():
    assert garagem([(5, 6), (6, 5), (0, 5)]) == 25


def test_garagem_05_pontos():
    assert garagem([(0, 5)]) == 5
