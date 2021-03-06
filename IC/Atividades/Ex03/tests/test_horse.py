from pytest import mark
from src.horse import is_integer, possivel


@mark.parametrize(
    'coord_x,coord_y',
    [(6, 7), (7, 6), (7, 4), (6, 3), (4, 3), (3, 4), (3, 6), (4, 7)],
)
def test_positon_init(coord_x, coord_y):
    assert possivel(5, 5, coord_x, coord_y) == True


def test_one():

    assert possivel(5, 5, 4, 7) == True
    assert possivel(5, 5, 8, 1) == False
    assert possivel(5, 5, 6, 7) == True
    assert possivel(5, 5, 7, 6) == True
    assert possivel(1, 8, 2, 4) == False
    assert possivel(1, 1, 2, 3) == True
    assert possivel(1, 1, 2.5, 2.5) == False


def test_val_out_tab():
    assert possivel(8.1, 8, 9, 10) == False
    assert possivel(8, 8.5, 9, 10) == False
    assert possivel(8, 8, 9.5, 9.5) == False
    assert possivel(1, 8, 2, 11) == False
    assert possivel(8, 8, 9, 10) == False


def test_horse_out_tab():
    assert possivel(1, 9, 2, 7) == False
    assert possivel(9, 9, 7, 8) == False
    assert possivel(9, 1, 7, 2) == False


def test_int():
    assert is_integer(1) == True
    assert is_integer(1.5584) == False
    assert is_integer(2.5) == False
    assert is_integer(1.5) == False
    assert is_integer(5.5) == False
    assert is_integer(5) == True
    assert is_integer(6) == True
    assert is_integer(6.8) == False
    assert is_integer(7.5) == False
