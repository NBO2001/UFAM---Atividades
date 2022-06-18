def head(lista_values):
    if len(lista_values) == 0:
        return []
    else:
        return lista_values[0]


def tail(lista_values):
    if len(lista_values) == 0:
        return []
    else:
        return lista_values[1:]


def semrep(xs):
    if xs == []:
        return xs
    elif [head(xs) for x in tail(xs) if head(xs) == x] == []:
        return [head(xs)] + semrep(tail(xs))
    else:
        return semrep(tail(xs))


print(semrep([]))
