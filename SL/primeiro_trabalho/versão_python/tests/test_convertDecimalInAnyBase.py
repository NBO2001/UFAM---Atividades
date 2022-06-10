from app.app import convertDecimalInAnyBase


def test_15decimalForOctal():
    assert convertDecimalInAnyBase(15, 8) == '17'


def test_166DecimalFor248Octal():
    assert convertDecimalInAnyBase(166, 8) == '246'


def test_FhexaIn15Decimal():
    assert convertDecimalInAnyBase(15, 16) == 'F'


def test_5909807decimalFor5A2D2FHexa():
    assert convertDecimalInAnyBase(5909807, 16) == '5A2D2F'


def test_15decimal_for_1111binary():
    assert convertDecimalInAnyBase(15, 2) == '1111'


def test_10decimal_for_1010binary():
    assert convertDecimalInAnyBase(10, 2) == '1010'
