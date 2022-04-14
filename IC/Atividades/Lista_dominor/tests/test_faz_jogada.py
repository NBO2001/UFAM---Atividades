from src.unificada import faz_jogada


def test_faz_jogada_test1():
    assert faz_jogada([(4, 6), (6, 1), (1, 5)], ([3], [2], [5, 5], [0])) == (
        [3],
        [2],
        [1],
        [0],
    )
