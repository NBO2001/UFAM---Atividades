from src.unificada import int_frac


def test_int_frac_caso_1():
    assert int_frac('324.8765') == ('324', '8765')


def test_int_frac_caso_2():
    assert int_frac('4586') == ('4586', '0')
