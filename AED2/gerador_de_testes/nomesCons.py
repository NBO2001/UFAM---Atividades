from nomes_and_dominios import getNome,getEmailDominio,sobreNome
from random import randrange


def new_name():

    sobre_nome = randrange(2,4)
    id_name = randrange(0,19999)
    
    id_email = randrange(0,6103)

    nome = getNome(id_name).capitalize()
    email = f"{nome.lower()}@{getEmailDominio(id_email)}"

    for _ in range(sobre_nome):
        id_sobreNome = randrange(0,253)
        nome = f"{nome} {sobreNome(id_sobreNome)}"

    return {
        "name": nome,
        "email": email
    }

