from src.terceira_parte import pode_jogar_p


def test_pode_jogar_p_retorna_verdadeiro():

    assert pode_jogar_p((2, 5), ([3], [4], [0], [2])) == True


def test_pode_jogar_p_retorna_falso():
    assert pode_jogar_p((2, 5), ([3], [4], [0], [])) == False
