from src.terceira_parte import sum_pontas


def test_soma_pontas_retorna_25():
    assert sum_pontas(([5], [5], [5], [5, 5])) == 25
