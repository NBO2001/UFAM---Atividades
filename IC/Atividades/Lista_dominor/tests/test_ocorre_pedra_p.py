from src.unificada import ocorre_pedra_p


def test_contem_uma_pedra_na_mao():
    assert (
        ocorre_pedra_p((5, 2), [(5, 6), (6, 5), (5, 2), (0, 0), (0, 5)])
        == True
    )


def test_NAO_contem_uma_pedra_na_mao():
    assert (
        ocorre_pedra_p((5, 2), [(5, 6), (6, 5), (5, 0), (0, 0), (0, 5)])
        == False
    )
