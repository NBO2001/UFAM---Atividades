from counting_sort import sort


def test_pequenos_valores():
    assert sort([6, 9, 2, 5, 8]) == [2, 5, 6, 8, 9]


def test_sugerido_pela_professora():
    assert sort([5, 18, 11, 11, 15, 19, 12, 18]) == [
        5,
        11,
        11,
        12,
        15,
        18,
        18,
        19,
    ]


def test_2_sugerido_pela_professora():
    assert sort([12, 5, 1, 7, 11, 50, 9, 14, 15, 12]) == [
        1,
        5,
        7,
        9,
        11,
        12,
        12,
        14,
        15,
        50,
    ]
