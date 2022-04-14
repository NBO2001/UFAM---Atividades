from src.unificada import tira_maior


def test_retorna_sem_as_maiores():
    assert tira_maior([(5, 6), (6, 5), (5, 2), (0, 0), (0, 5)]) == [
        (5, 2),
        (0, 0),
        (0, 5),
    ]


def test_sem_a_maior():
    assert tira_maior([(5, 6), (6, 6), (5, 0), (0, 0), (0, 5)]) == [
        (5, 6),
        (5, 0),
        (0, 0),
        (0, 5),
    ]
