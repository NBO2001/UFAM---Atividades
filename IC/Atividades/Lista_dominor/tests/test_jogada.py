from src.unificada import jogada


def test_jogada_uma_pontuaçao():
    assert jogada([(4, 6), (6, 1), (0, 5)], ([3], [2], [5, 5], [0])) == (2, 3)


def test_jogada_duas_pontuaçao():
    assert jogada([(1, 0), (5, 0), (3, 0)], ([0], [1], [5, 5], [5])) == (1, 0)
