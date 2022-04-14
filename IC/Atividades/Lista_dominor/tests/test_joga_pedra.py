from src.terceira_parte import joga_pedra


def test_joga_pedra_mesa_com_5():
    assert joga_pedra((0, 5), ([3], [2], [5, 5], [0]), 3) == (
        [3],
        [2],
        [5, 5],
        [5],
    )


def test_joga_pedra_mesa_com_2():
    assert joga_pedra((0, 3), ([3], [], [5, 5], []), 0) == (
        [0],
        [],
        [5, 5],
        [],
    )


def test_configura_mesa_retorna_mesa_com_5():

    assert joga_pedra((2, 5), ([3], [2], [5, 5], [6]), 2) == (
        [3],
        [2],
        [2],
        [6],
    )


def test_configura_mesa_retorna_mesa_com_6():
    assert joga_pedra((2, 6), ([3], [2], [5], [6]), 1) == ([3], [6], [5], [6])


def test_configura_mesa_retorna_mesa_com_carroca():
    assert joga_pedra((3, 3), ([3], [4], [5], [0]), 0) == (
        [3, 3],
        [4],
        [5],
        [0],
    )
