from gerador_person import new_person


def gere(qnt=1, delim="\n", stop_poit=1, location=0):
    if not location:
        texto = f"""{qnt}\n"""
    else:
        texto = f""""""

    for id_i in range(qnt):
        
        person = new_person(id=(True, id_i+1),nome=True,email=True, idade=True, peso=True)

        for label in person:
            texto = f"""{texto}{person[label]}{delim}"""


        texto = f"""{texto[:(len(texto)-len(delim))]}
"""
    if location:
        texto = f"""{texto}{stop_poit}"""

    return texto




arq = open("out.in","w")

arq.write(gere(qnt=30))

arq.close()