from src.primeira_parte import pedrap


def test_deprap_primeiro():
    assert pedrap((2, 7)) == False


def test_deprap_segundo():
    assert pedrap(((-3), 4)) == False


def test_deprap_teceiro():
    assert pedrap((3, 4)) == True
