from src.unificada import e_float
from pytest import mark


@mark.parametrize('cadeia', ['2.5', '5.6', '21548.5', '549812.5'])
def test_e_float_retorn_true(cadeia):

    assert e_float(cadeia) == True


@mark.parametrize('cadeia', ['2.', '6.', '21548a.5', 'a.5'])
def test_e_float_retorn_false(cadeia):

    assert e_float(cadeia) == False
