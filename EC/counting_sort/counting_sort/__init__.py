
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
  

    for element_bucket in range(1,len(bucket)):
       
        bucket[element_bucket] = bucket[element_bucket-1] + bucket[element_bucket]
    
    

    lista_ord = [0] * len(lista_valores)

    for number in lista_valores:
        
        lista_ord[bucket[number]-1] = number
        
        bucket[number] -= 1

    return lista_ord