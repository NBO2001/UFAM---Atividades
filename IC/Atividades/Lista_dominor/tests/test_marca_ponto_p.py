from src.unificada import marca_ponto_p


def test_marca_ponto_p_retorna_verdeiro():

    assert marca_ponto_p((2, 5), ([3], [2], [5, 5], [2, 2])) == True


def test_marca_ponto_p_retorna_falso():

    assert marca_ponto_p((2, 1), ([3], [2], [5, 5], [2, 2])) == False
