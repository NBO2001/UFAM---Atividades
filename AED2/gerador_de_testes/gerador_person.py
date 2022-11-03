from adrress import contrie
from altura_peso_idade import altura_generator,peso_generator, idade_generator
from cpf_rg_cnh import cnh_generato,cpf_generator,rg_generator
from nomesCons import new_name


def new_person(
    id=(False,0),
    nome=False, 
    altura=False, 
    peso=False, 
    idade=False,
    cpf=False,
    rg=False,
    cnh=False,
    email=False,
    ):
    
    person = {}
    
    id_s, id_val = id

    nomes_cont = new_name()

    if id_s:
        person["id"] = id_val

    if nome:
        person["nome"] = nomes_cont["name"]

    if altura:
        person["altura"] = altura_generator()
    
    if peso:
        person["peso"] = peso_generator()

    if idade:
        person["idade"] = idade_generator()

    if cpf:
        person["cpf"] = cpf_generator()

    if rg:
        person["rg"] = rg_generator()

    if cnh:
        person["cnh"] = cnh_generato()

    if email:
        person["email"] = nomes_cont["email"]
    
    
    return person
    