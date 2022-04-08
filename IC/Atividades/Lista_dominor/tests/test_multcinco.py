from src.segunda_parte import multcinco


def test_somar_multiplos_de_cinco_retorna_35():
    assert multcinco(36) == 35


def test_somar_multiplos_de_cinco_retorna_0():
    assert multcinco(4) == 0
