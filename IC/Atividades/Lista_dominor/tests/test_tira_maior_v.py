from src.segunda_parte import tira_maior_v


def test_da_ponta_5_retira_o_maior_valor():
    assert tira_maior_v(
        5, [(4, 6), (6, 5), (2, 3), (5, 2), (0, 0), (5, 1)]
    ) == [(4, 6), (2, 3), (5, 2), (0, 0), (5, 1)]


def test_da_ponta_3_retira_o_maior_valor():
    assert tira_maior_v(
        3, [(4, 6), (6, 5), (2, 3), (5, 2), (0, 0), (5, 1)]
    ) == [(4, 6), (6, 5), (5, 2), (0, 0), (5, 1)]
