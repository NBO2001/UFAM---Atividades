from src.unificada import lista_de_jogadas


def test_lista_de_jogadas_return_true():
    assert lista_de_jogadas([(5, 5), (5, 6), (6, 2)]) == True


def test_lista_de_jogadas_return_false():
    assert lista_de_jogadas([(5, 5), (5, 6), (2, 6)]) == False
