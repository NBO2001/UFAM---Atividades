import pdb
from src.terceira_parte import verify_pontas


def test_verify_pontas_retorna_true():

    assert verify_pontas([3, 4, 5], [(5, 2)]) == True
