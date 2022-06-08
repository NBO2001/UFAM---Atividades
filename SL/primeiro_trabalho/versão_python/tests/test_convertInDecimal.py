from app.app import convertInDecimal


def test_octal_for_15decimal():
    assert convertInDecimal('17', 8) == 15


def test_octal_for_15decimal():
    assert convertInDecimal('246', 8) == 166


def test_hexa_for_15decimal():
    assert convertInDecimal('F', 16) == 15


def test_hexa_for_5909807decimal():
    assert convertInDecimal('5A2D2F', 16) == 5909807


def test_binary_for_15decimal():
    assert convertInDecimal('1111', 2) == 15


def test_binary_for_10decimal():
    assert convertInDecimal('1010', 2) == 10
