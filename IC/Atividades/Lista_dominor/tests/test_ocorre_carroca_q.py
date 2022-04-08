from src.segunda_parte import ocorre_carroca_q


def test_contem_uma_carroca_na_mao():
    assert ocorre_carroca_q([(5, 6), (6, 5), (5, 2), (0, 0), (0, 5)]) == 1


def test_contem_duas_carrocas_na_mao():
    assert ocorre_carroca_q([(5, 6), (6, 6), (5, 0), (0, 0), (0, 5)]) == 2
