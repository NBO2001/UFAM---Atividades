from src.unificada import find_indexs


def test_find_indexs_lado_com_5():
    assert find_indexs(5, ([3], [2], [5, 5], [6])) == [2]


def test_find_indexs_lado_com_2():
    assert find_indexs(2, ([3], [2], [5, 5], [2, 2])) == [1, 3]
