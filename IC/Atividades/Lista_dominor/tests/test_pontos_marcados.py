from src.unificada import pontos_marcados


def test_retorna_True():
    assert pontos_marcados(([5], [5], [5], [5, 5])) == 25


def test_retorna_false():
    assert pontos_marcados(([1], [5], [5], [5, 5])) == 0
