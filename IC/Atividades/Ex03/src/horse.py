def modulo(num_recebido) -> float or int:
    """Devolve o modulo de um numero."""
    if num_recebido > 0:
        return num_recebido

    return num_recebido * (-1)


def is_on_table(positon_x, positon_y) -> bool:
    """Verifica se está no tabuleiro de xadrez"""
    table_x_length, table_y_length = (8, 8)

    return table_x_length >= positon_x > 0 and table_y_length >= positon_y > 0


def is_integer(analyzed_value):

    """Como não posso usar outros métodos, já que não foi visto em aula,
    verificarei se o número é inteiro apenas usando funções matématica vistas em aula."""

    mul = analyzed_value * 10
    rest = mul % 5
    if not rest:

        resul_div = mul / 5
        # Se o resto do for par, significa que a o número termina com 0
        return not resul_div % 2

    return False


def possivel(x1, y1, x2, y2) -> bool:
    """Verifica se alguma cordenada é flutuante"""
    if (
        not is_integer(x1)
        or not is_integer(y1)
        or not is_integer(x2)
        or not is_integer(y2)
    ):
        return False
    # Verifica se está no tabuleiro
    if not ((is_on_table(x1, y1)) and (is_on_table(x2, y2))):
        return False
    # Verifica se soma dos modulos é 3
    if (modulo(x1 - x2) + modulo(y1 - y2)) == 3:
        return True

    return False
