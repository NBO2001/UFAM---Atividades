from src.unificada import hasfit


def test_pedra_tem_encaixe_retorna_verdadeiro():
    assert hasfit(5, (6, 5)) == True


def test_pedra_tem_encaixe_retorna_false():
    assert hasfit(2, (6, 1)) == False
