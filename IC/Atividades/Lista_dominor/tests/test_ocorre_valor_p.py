from src.unificada import ocorre_valor_p


def test_com_o_jogador_tendo_um_pedra_retorn_true():
    assert ocorre_valor_p(2, [(4, 6), (6, 4), (2, 3)]) == True


def test_com_o_jogador_sem_pedra_retorn_false():
    assert ocorre_valor_p(5, [(4, 6), (6, 4), (0, 3)]) == False
