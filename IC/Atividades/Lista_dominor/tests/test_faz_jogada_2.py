from src.unificada import faz_jogada_2


def test_faz_jogada_2_return_nova_table():
    assert faz_jogada_2(
        (2, 5), [[(2, 2)], [(5, 2)], [(5, 5), (5, 6), (6, 2)], [(0, 2)], []], 0
    ) == [[(2, 2)], [(2, 5), (5, 2)], [(5, 5), (5, 6), (6, 2)], [(0, 2)], []]
