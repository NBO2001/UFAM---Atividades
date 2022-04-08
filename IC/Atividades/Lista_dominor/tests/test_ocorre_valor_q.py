from src.segunda_parte import ocorre_valor_q


def test_contem_uma_pedra_na_mao():
    assert (
        ocorre_valor_q(5, [(5, 6), (6, 5), (2, 5), (0, 0), (0, 5)]) == 4
    )


def test_contem_duas_pedras_na_mao():
    assert (
        ocorre_valor_q( 2, [(5, 6), (6, 5), (2, 5), (5, 2), (0, 5)]) == 2
    )


def test_NAO_contem_uma_pedra_na_mao():
    assert (
        ocorre_valor_q(0, [(5, 6), (6, 5), (5, 0), (0, 0), (0, 5)]) == 3
    )
