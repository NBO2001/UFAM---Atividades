from src.unificada import ordertuple


def test_tuplas_em_ordem():
    assert ordertuple((5, 1)) == (1, 5)
