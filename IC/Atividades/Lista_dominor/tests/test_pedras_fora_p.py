from src.unificada import pedras_fora_p


def test_pedras_fora_p_return_true():
    assert (
        pedras_fora_p(
            [[(2, 2)], [(5, 2)], [(5, 5), (5, 6), (6, 2)], [(0, 2)], []],
            (0, 0),
        )
        == True
    )


def test_pedras_fora_p_return_false():
    assert (
        pedras_fora_p(
            [[(2, 2)], [(5, 2)], [(5, 5), (5, 6), (6, 2)], [(0, 2)], []],
            (2, 5),
        )
        == False
    )
