'''
Program-Name: ConversorDeBases
Author: Natanael Bezerra de Oliveira
GitHub: https://github.com/NBO2001/UFAM---Atividades/tree/main/SL/primeiro_trabalho/versão_python

================================== EXPLICAÇÃO DE COMO FUNCIONA ==================================================================
Há duas formas de usar este programa.

1º Rodar o app no terminal.
    basta digitar o comando; python3 app.py

2º Importando o conversor para uma sessão python.

Vocẽ pode digitar no terminal " python3 ", na mesma pasta em que está o aquivo app.py, em seguida digite: from app import app

A função app recebe 3 parametros; valorOriginal, que replesenta o valor a ser convertido; baseDeEntrada, que representa a base de entrada; baseDestiny, que representa o valor de saida.

O retorn da função é uma lista com o tamanho até 2, em que o primeiro indice é o valor convertido e
o segundo a base (Caso a base seja diferente de 10)

================================== REQUISITOS MINIMOS ==================================================================
    
    python = "^3.9"
'''

# Converte qualquer base para base decimal
def convertInDecimal(anyNumber: str, anyBase: int) -> int:

    # Gerar um dicionario de simbulos
    dictiorySymbulos = {

        f'{number if number < 10 else chr(number+55)}': number

        for number in range(0, 36)

    }

    posicaoNow = len(anyNumber) - 1

    acumulador = 0

    for symbulo in anyNumber:

        # Procura o valor do simbolo no dicionário, após multiplica ele pela base de entrada elevada a posição atual.
        acumulador += dictiorySymbulos[symbulo] * (anyBase**posicaoNow)

        posicaoNow -= 1

    return acumulador

# Função para converter um número decimal para qualquer outra base.
def convertDecimalInAnyBase(decimalValue: int, anyBase) -> str:

    # Gerar um dicionario de simbulos
    dictiorySymbulos = {

        number: f'{number if number < 10 else chr(number+55)}'

        for number in range(0, 36)

    }

    stringRetorn = ''

    # Divissões sucessivas
    if decimalValue >= 0:

        while decimalValue > 0:

            restoDivisao = decimalValue % anyBase

            # Procura no dicionario o simbulo equivalente ao resto da divisão, após 
            # concate com o que já está armazenado no valor de retorno.
            stringRetorn = f'{dictiorySymbulos[restoDivisao]}{stringRetorn}'

            decimalValue = decimalValue // anyBase

    return stringRetorn


# Função principal, responsável por fazer a integração entre as duas funções anteriores
def app(valorOriginal, baseDeEntrada=10, baseDestiny=10):

    arrayRetorn = []

    itsNumebrInDecimalis = convertInDecimal(
        valorOriginal, baseDeEntrada
    )

    itsNumebrInDestiny = convertDecimalInAnyBase(
        itsNumebrInDecimalis, baseDestiny
    )

    arrayRetorn.append(itsNumebrInDestiny)

    if baseDestiny != 10:
        arrayRetorn.append(baseDestiny)

    return arrayRetorn


# Interatividade com o usuário do programa
if __name__ == '__main__':

    print('\033[93m') # Apenas para alterar a cor do terminal (Frescura)
    print('\033[1m') 

    print(f'{ "=" * 50 } AVISO { "=" * 50 } \n')
    print(f'Esse program está definido até a base 35 (Z).')
    print(f'Esse programa não está definido para letras minisculas, portanto use de A-Z.')
    print(f'Esse programa não funciona para números fracionários, nem negativos.')

    print(f'\n{ "=" * 48 } FIM AVISO { "=" * 48 }') 
    print('\033[0m') # Apenas para alterar a cor do terminal (Frescura)

    while True:

        numberA = input('Digite um número na base de origem: ')

        userTypedA = input('Qual a base de origem? ')
        baseA = int(userTypedA) if userTypedA else 10

        userTyped = input('Qual a base de destino? ')
        baseB = int(userTyped) if userTyped else 10
        
        numberEndIs = app(numberA, baseA, baseB)

        print('\033[92m') # Apenas para alterar a cor do terminal (Frescura)

        if len(numberEndIs) == 2:

            print(f'Esse número na base {numberEndIs[1]}  é: {numberEndIs[0]}')
        
        else:

            print(f'Esse número na base 10 é: {numberEndIs[0]}')

        print('\033[94m') # Apenas para alterar a cor do terminal (Frescura)

        if input('Deseja converter outro numero? [S/N]') == 'N':
            break

        print('\033[0m') # Apenas para alterar a cor do terminal (Frescura)
