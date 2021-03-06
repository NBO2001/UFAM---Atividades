from src.unificada import ocorre_pedra


def test_contem_uma_pedra_na_mao():
    assert ocorre_pedra(2, [(5, 6), (6, 5), (2, 5), (0, 0), (0, 5)]) == [
        (2, 5)
    ]


def test_contem_duas_pedras_na_mao():
    assert ocorre_pedra(5, [(5, 6), (2, 5), (4, 2), (0, 5)]) == [
        (5, 6),
        (2, 5),
        (0, 5),
    ]


def test_NAO_contem_uma_pedra_na_mao():
    assert ocorre_pedra(0, [(5, 6), (6, 5), (5, 0), (0, 0), (0, 5)]) == [
        (5, 0),
        (0, 0),
        (0, 5),
    ]
