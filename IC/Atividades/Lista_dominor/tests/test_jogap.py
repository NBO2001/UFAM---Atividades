from src.terceira_parte import jogap


def test_jogap_retorn_true():
    assert jogap([(4, 6), (6, 1), (1, 5)], ([3], [2], [5, 5], [0])) == True


def test_jogap_retorn_false():
    assert jogap([(4, 6), (6, 1), (1, 1)], ([3], [2], [5, 5], [0])) == False
