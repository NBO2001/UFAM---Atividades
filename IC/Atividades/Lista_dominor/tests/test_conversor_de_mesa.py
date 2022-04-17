from src.unificada import conversor_de_mesa


def test_conversor_de_mesa_retorn_nem_table():

    assert conversor_de_mesa(
        [[(2, 2)], [(5, 2)], [(5, 5), (5, 6), (6, 2)], [(0, 2)], []]
    ) == ([5], [5, 5], [0], [])
