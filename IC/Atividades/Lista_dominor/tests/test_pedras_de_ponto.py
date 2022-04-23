from src.unificada import pedras_de_ponto


def test_pedras_de_ponto_test_generico():
    assert pedras_de_ponto(([5], [5, 5], [0], [])) == [(0, 0), (0, 5), (5, 5)]
