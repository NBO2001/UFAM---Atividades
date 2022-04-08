from src.segunda_parte import garagem


def test_garagem_25_pontos():
    assert garagem([(5, 6), (6, 5), (0, 5)]) == 25
