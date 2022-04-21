from src.unificada import intersec


def test_intersec_intersecao_de_4_elementos():
    assert intersec([5, 2, 3, 4], [8, 4, 6, 3]) == [3, 4]
