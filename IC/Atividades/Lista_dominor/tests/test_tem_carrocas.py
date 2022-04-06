from src.primeira_parte import tem_carrocas


def test_mao_com_carrocas():
    assert tem_carrocas(
        [(1, 5), (2, 2), (6, 4), (0, 0), (3, 6), (3, 4), (3, 6)]
    ) == [(2, 2), (0, 0)]


def test_mao_sem_carrocas():
    assert (
        tem_carrocas([(1, 5), (2, 3), (6, 4), (0, 1), (3, 6), (3, 4), (3, 6)])
        == []
    )
