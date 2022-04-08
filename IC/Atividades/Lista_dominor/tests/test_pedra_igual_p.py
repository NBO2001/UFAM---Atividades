from src.segunda_parte import pedra_igual_p


def test_return_true_com_duas_pedra_iguais():
    assert pedra_igual_p(((2, 4), (4, 2))) == True


def test_return_false_com_duas_pedra_iguais():
    assert pedra_igual_p(((2, 4), (5, 2))) == False
