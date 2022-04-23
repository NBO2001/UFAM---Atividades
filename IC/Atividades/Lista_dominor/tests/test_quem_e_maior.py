from src.unificada import quem_e_maior


def test_quem_e_maior_retorn_pedra_maior():
    assert quem_e_maior((6, 5), [(5, 2), (0, 0), (0, 5)]) == (6, 5)
