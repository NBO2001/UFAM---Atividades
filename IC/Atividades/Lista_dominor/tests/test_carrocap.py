from src.unificada import carrocap


def test_carroca_valida():
    assert carrocap((5, 5)) == True


def test_carroca_invalida():
    assert carrocap((3, 6)) == False
