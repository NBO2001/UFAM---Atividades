from src.prova import retira


def test_retira_geral():
    assert retira([1, 5, 2], [8, 6, 2, 1, 4, 6, 5, 2, 1, 58, 6]) == [
        8,
        6,
        4,
        6,
        58,
        6,
    ]
