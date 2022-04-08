from src.prova import nomax


def test_geral():
    assert nomax([(1, 6), (2, 2), (4, 4), (0, 5), (0, 0)]) == [
        (1, 6),
        (2, 2),
        (0, 5),
        (0, 0),
    ]
