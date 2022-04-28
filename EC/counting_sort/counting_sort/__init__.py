
def maior_numero(lista_valores: list) -> int:
    
    bigger_number = 0

    for number in lista_valores:
        if number > bigger_number:
            bigger_number = number

    return bigger_number


def sort(lista_valores: list) -> list:

    maior_element = maior_numero(lista_valores)

    bucket = [0]*(maior_element+1)
  
    for number in lista_valores:

        bucket[number] += 1
  

    lista_ord = []

    for buck in range(len((bucket))):

        lista_ord = lista_ord + [buck]*bucket[buck]


    return lista_ord