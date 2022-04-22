from src import norep

def test_norep_lista_sem_repetidos():
    assert norep([2,5,8,5,5,2]) == [2,5,8]