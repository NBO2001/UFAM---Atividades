from src.unificada import pedra_maior


def test_pedra_maior_no_meio():
    assert pedra_maior([(4, 6), (6, 5), (0, 5)]) == (6, 5)


def test_com_duas_iguais():
    assert pedra_maior([(5, 6), (6, 5), (5, 2), (0, 0), (0, 5)]) == (6, 5)


def test_pedra_maior_no_final():
    assert pedra_maior([(4, 6), (0, 5), (4, 3), (6, 5)]) == (6, 5)
