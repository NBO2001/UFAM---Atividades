
def placa(x):

    final_da_placa = x[-3:]
    
    if verify_is_number([final_da_placa[0],final_da_placa[2]]) and verify_is_cadeia_valida([final_da_placa[1]]):
        return "moto" 
    elif verify_is_cadeia_valida(head(final_da_placa)) and verify_is_number(tail(final_da_placa)):
        return "carro"
    else:
        return "nada"



# Funções auxiliares


def head(lista_itens):
    if len(lista_itens) == 0:
        return []
    else:
        return lista_itens[0]


def tail(lista_itens, position=1):
    if len(lista_itens) == 0:
        return []
    else:
        return lista_itens[position:]


def verify_is_number(numero):

    if len(numero) == 1:
        return 48 <= ord(head(numero)) <= 57

    return (48 <= ord(head(numero)) <= 57) and verify_is_number(tail(numero))


def get_only_string(leteer):

    if 'A' <= leteer and leteer <= 'Z':
        return leteer
    elif ord(leteer) == 32:
        return ' '
    else:
        return ''

def verify_is_cadeia_valida(cadeia):
    if len(cadeia) == 1: return get_only_string(head(cadeia))

    return get_only_string(head(cadeia)) and verify_is_cadeia_valida(tail(cadeia))

        