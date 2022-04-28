from counting_sort import sort

def test_pequenos_valores():
    assert sort([6,9,2,5,8]) == [2,5,6,8,9]


def test_sugerido_pela_professora():
    assert sort([5, 18, 11, 11, 15, 19, 12, 18]) == [5, 11, 11, 12, 15, 18, 18, 19]