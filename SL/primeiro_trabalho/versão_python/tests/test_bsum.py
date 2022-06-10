from app.app import bsum


def test_sum_1_1_return_10():
    assert bsum('1', '1') == '10'
