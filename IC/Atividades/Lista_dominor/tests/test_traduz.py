from src.unificada import traduz


def test_traduz_retorn_quize():
    assert traduz(15) == 'quinze'


def test_traduz_retorn_tres():
    assert traduz(3) == 'tres'


def test_traduz_return_trinta_e_cinco():

    assert traduz(35) == 'trinta e cinco'
