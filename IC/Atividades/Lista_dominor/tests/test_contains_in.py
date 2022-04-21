from src.unificada import contains_in


def test_contains_in_main():
    assert contains_in(5, [2, 3, 6, 4, 5]) == [5]
