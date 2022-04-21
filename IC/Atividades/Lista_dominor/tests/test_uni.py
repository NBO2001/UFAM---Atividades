from src.unificada import uni


def test_uni_main():
    assert uni([5, 4, 2, 3], [2, 1, 3, 8]) == [1, 2, 3, 4, 5, 8]
