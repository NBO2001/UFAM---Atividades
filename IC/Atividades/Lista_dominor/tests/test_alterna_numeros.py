from src.unificada import alterna_numeros


def test_alterna_numeros_10_elementos():
    assert alterna_numeros([2, 5, 8, 4, 1, 3, 6, 12, 15, 7]) == [
        2,
        5,
        8,
        1,
        4,
        3,
        6,
        15,
        12,
        7,
    ]
