from src.unificada import pedra_de_maior_ponto


def test_pedra_de_maior_ponto_teste_generico():
    assert pedra_de_maior_ponto(([5], [5, 5], [0], [])) == (0, 5)
