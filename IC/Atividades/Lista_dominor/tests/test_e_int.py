from pytest import mark

from src.unificada import e_int


@mark.parametrize('cadeia', ['5451', '5', '2', '54821', '0', '875'])
def test_e_int_retorn_true(cadeia):
    assert e_int(cadeia) == True


@mark.parametrize(
    'cadeia_2', ['54a51', '5.5', '2@', '5,4821', '0_', 'Natr875']
)
def test_e_int_retorn_false(cadeia_2):
    assert e_int(cadeia_2) == False
