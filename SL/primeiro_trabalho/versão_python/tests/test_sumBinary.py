from app.app import sumBinary


def test_sum_1_plus_1_resto_0_retun_0_e_resto_1():
    assert sumBinary('1', '1', '0') == ('0', '1')


def test_sum_1_plus_0_resto_0_retun_0_e_resto_0():
    assert sumBinary('1', '0', '0') == ('1', '0')


def test_sum_1_plus_1_resto_1_retun_1_e_resto_1():
    assert sumBinary('1', '1', '1') == ('1', '1')


def test_sum_0_plus_0_resto_0_retun_0_e_resto_0():
    assert sumBinary('0', '0', '0') == ('0', '0')


def test_sum_0_plus_0_resto_1_retun_1_e_resto_0():
    assert sumBinary('0', '0', '1') == ('1', '0')
