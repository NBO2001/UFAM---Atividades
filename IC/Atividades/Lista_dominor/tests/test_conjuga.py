from src.unificada import conjuga


def test_conjuga_presente():
    assert conjuga('jogar', 'presente') == [
        'eu jogo',
        'tu jogas',
        'ele joga',
        'nos jogamos',
        'vos jogais',
        'eles jogam',
    ]
