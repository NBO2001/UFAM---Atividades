def norep(xs):

    if len(xs) == 0:
        return []

    else:
        return [head(xs)] + norep(tira(head(xs), tail(xs)))


# AUxiliares


def head(lista_itens):
    if len(lista_itens) == 0:
        return []
    else:
        return lista_itens[0]


def tira(k, xs):

    if len(xs) == 0:
        return []
    elif head(xs) != k:
        return [head(xs)] + tira(k, tail(xs))
    else:
        return tira(k, tail(xs))


def tail(lista_itens, position=1):
    if len(lista_itens) == 0:
        return []
    else:
        return lista_itens[position:]
