from src.unificada import maior_ponto


def test_maior_ponto_index_3():
    assert maior_ponto((0, 5), ([3], [2], [5, 5], [0])) == 3


def test_maior_ponto_index_0():
    assert maior_ponto((3, 0), ([3], [5], [5, 5], [0])) == 0


def test_maior_ponto_index_0():
    assert maior_ponto((3, 3), ([3], [4], [5], [0])) == 0
