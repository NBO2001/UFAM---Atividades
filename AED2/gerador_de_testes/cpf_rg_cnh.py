from random import randrange

def cpf_generator():

    return f"{randrange(0,9)}{randrange(0,9)}{randrange(0,9)}.{randrange(0,9)}{randrange(0,9)}{randrange(0,9)}.{randrange(0,9)}{randrange(0,9)}{randrange(0,9)}-{randrange(0,9)}{randrange(0,9)}"

def rg_generator():
    return f"{randrange(0,9)}{randrange(0,9)}{randrange(0,9)}{randrange(0,9)}{randrange(0,9)}{randrange(0,9)}{randrange(0,9)}-{randrange(0,9)}"

def cnh_generato():
    return f"{randrange(0,9)}{randrange(0,9)}{randrange(0,9)}{randrange(0,9)}{randrange(0,9)}{randrange(0,9)}{randrange(0,9)}{randrange(0,9)}{randrange(0,9)}{randrange(0,9)}"