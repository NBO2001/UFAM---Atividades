from src.segunda_parte import pontos


def test_soma_retorna_5_tuplas():
    assert pontos([(5, 6), (6, 5), (5, 0), (0, 0), (0, 5)]) == [ ((5, 6), 11), ((6, 5), 11), ((5, 0), 5), ((0, 0), 0), ((0, 5), 5)  ]


def test_soma_retorna_3_tuplas():
    assert pontos([(5, 6), (6, 5), (5, 0)]) == [ ((5, 6), 11), ((6, 5), 11), ((5, 0),5)]

