
def norep(xs):
    
    lista_ordenada = order_list(xs)
    list_final = []

    for element in lista_ordenada:
        if not contains_in(element,list_final):
            list_final.append(element)

    return list_final


# AUxiliares

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

def contains_in(value, list_values):

    if len(list_values) == 0:

        return False

    elif value == head(list_values):

        return True

    else:

        return contains_in(value, tail(list_values))


def append_element_ord(number, lista_of_numbers):

    if len(lista_of_numbers) == 0:
        return [number]
    elif number <= head(lista_of_numbers):

        return [number] + lista_of_numbers
    else:
        return [head(lista_of_numbers)] + append_element_ord(
            number, tail(lista_of_numbers)
        )


def order_list(lista_itns):

    if len(lista_itns) == 0:
        return []

    return append_element_ord(head(lista_itns), order_list(tail(lista_itns)))

