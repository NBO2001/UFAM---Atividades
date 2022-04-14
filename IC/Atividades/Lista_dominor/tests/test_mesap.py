from pytest import mark

from src.unificada import mesap


def test_mesap_mesa_valida():
    assert mesap(([5], [5, 5], [0], [])) == True


@mark.parametrize(
    'mesa',
    [([5], [5, 5], [0]), ([6], [5, 5], [0], [7]), ([6], [5, 5], [0], [], [])],
)
def test_mesap_mesa_invalida(mesa):
    assert mesap(mesa) == False
