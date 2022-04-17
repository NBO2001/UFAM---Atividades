from src.unificada import marca_ponto_2


def test_marca_ponto_2_retun_15():
    assert (
        marca_ponto_2(
            [[(2, 2)], [(5, 2)], [(5, 5), (5, 6), (6, 2)], [(0, 2)], []]
        )
        == 15
    )


def test_marca_ponto_2_retun_15():
    assert (
        marca_ponto_2(
            [[(2, 2)], [(5, 2)], [(5, 5), (5, 6), (6, 2)], [(0, 2)], [(4, 2)]]
        )
        == 0
    )
