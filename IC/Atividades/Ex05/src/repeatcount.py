"""Atividade de IC."""

# Função para dividir números.
def divisao_de_um_numero(numero_a_ser_dividido, divisor):
    """Recebe um numero a ser dividido e o divisor,retorna a divisão inteira e o resto."""
    divisao_inteira = numero_a_ser_dividido // divisor
    resto_divisao_inteira = numero_a_ser_dividido % divisor
    return (divisao_inteira, resto_divisao_inteira)


# Verifica se dois números são iguais.
def verifica_divisao_inteira_numeros(tupla_itens_a, tupla_itens_b):
    """Verifica a igualdade de dois numeros e retona o verdadeiro ou false e o resto."""
    divison_a, resto_a = tupla_itens_a
    divison_b, resto_b = tupla_itens_b
    return ((divison_a == divison_b), (resto_a, resto_b))


# Função solitada
def dig(a, b):
    """Verifica a contidade de números que estão na mesma posição em dois números de 5 algarimos."""
    equals_digs = 0

    for potencia in range(4, -1, -1):

        is_equal_first, restos = verifica_divisao_inteira_numeros(
            divisao_de_um_numero(a, 10**potencia),
            divisao_de_um_numero(b, 10**potencia),
        )
        a, b = restos
        if is_equal_first:
            equals_digs = equals_digs + 1

    return equals_digs
