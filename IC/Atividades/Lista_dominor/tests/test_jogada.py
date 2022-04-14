from src.terceira_parte import jogada


def test_jogada_uma_pontuaçao():
    assert jogada([(4, 6), (6, 1), (1, 5)], ([3], [2], [5, 5], [0])) == 1


def test_jogada_duas_pontuaçao():
    assert jogada([(0, 0), (5, 0), (3, 0)], ([0], [0], [5, 5], [5])) == 1
