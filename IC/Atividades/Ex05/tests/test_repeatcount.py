from pytest import mark
from src.repeatcount import dig


@mark.parametrize(
    'number_a, number_b', [(00000, 1000), (20000, 50000), (5268, 5267)]
)
def test_deve_retorna_4(number_a, number_b):
    assert dig(number_a, number_b) == 4


@mark.parametrize(
    'number_a, number_b',
    [(38756, 98716), (123, 321), (12300, 32100), (1, 200)],
)
def test_deve_retorna_3(number_a, number_b):
    assert dig(number_a, number_b) == 3


@mark.parametrize('number_a, number_b', [(12345, 54321), (53871, 79641)])
def test_deve_retorna_1(number_a, number_b):
    assert dig(number_a, number_b) == 1


@mark.parametrize('number_a, number_b', [(12345, 53421)])
def test_deve_retorna_0(number_a, number_b):
    assert dig(number_a, number_b) == 0
