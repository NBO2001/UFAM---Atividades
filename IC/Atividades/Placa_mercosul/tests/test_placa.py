from src import placa

def test_placa_moto():
    assert placa("LLL68L1") == 'moto'

def test_placa_carro():
    assert placa("ASL4L26") == 'carro'


def test_placa_nada():
    assert placa("ASL4LU6") == 'nada'