from src.unificada import mesa2p


def test_mesa2p_return_true():
    assert (
        mesa2p(
            ([5], [5, 5], [0], []),
            [[(2, 2)], [(5, 2)], [(5, 5), (5, 6), (6, 2)], [(0, 2)], []],
        )
        == True
    )


def test_mesa2p_return_false():
    assert (
        mesa2p(
            ([5], [5, 5], [0], []),
            [
                [(2, 2)],
                [(5, 2)],
                [(5, 5), (5, 6), (6, 2)],
                [(0, 2)],
                [(0, 4), (4, 2)],
            ],
        )
        == False
    )
