from src.unificada import e_palav


def test_e_palav_com_apenas_letras():
    assert e_palav('Natanael Bezerra') == True


def test_e_palav_com_numeros():
    assert e_palav('Natanael Bezerra12') == False


def test_e_palav_com_numeros_e_siumbulos():
    assert e_palav('N@tanael Bezerr@12') == False
