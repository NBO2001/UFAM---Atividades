# Authors: Marcelo Cipiano e Natanael Bezerra de Oliveira

# Para execução do código é necessário usar o python >= 3.9

# Para jogar digite no terminal: python3 app.py

from time import sleep, time_ns

# Soma bit a bit
def sumBinary(binaryA: str, binaryB: str, resto: str = '0') -> tuple:

    if binaryA == '1' and binaryB == '1' and resto == '0':
        return ('0', '1')
    elif binaryA == '1' and binaryB == '1' and resto == '1':
        return ('1', '1')
    elif ((binaryA == '1') ^ (binaryB == '1')) and resto == '1':
        return ('0', '1')
    elif ((binaryA == '1') ^ (binaryB == '1')) and resto == '0':
        return ('1', '0')
    elif ((binaryA == '0') and (binaryB == '0')) and resto == '0':
        return ('0', '0')
    elif ((binaryA == '0') and (binaryB == '0')) and resto == '1':
        return ('1', '0')


# Soma qualquer número binario com qualquer outro numero binário.
def bsum(valueBinaryA: str, valueBinaryB: str, quatidadeBytes: int = 8):

    # Padroniza os binários
    if len(valueBinaryA) != len(valueBinaryB):

        if len(valueBinaryA) > len(valueBinaryB):

            valueBinaryB = (
                '0' * (len(valueBinaryA) - len(valueBinaryB))
            ) + valueBinaryB

        else:

            valueBinaryA = (
                '0' * (len(valueBinaryB) - len(valueBinaryA))
            ) + valueBinaryA

    arraySobras = ['0' for i in range(0, len(valueBinaryA) + 1)]
    contaResultado = ''

    for i in range((len(valueBinaryA)), 0, -1):

        resultadoDaSoma, sobraDaSoma = sumBinary(
            valueBinaryA[i - 1], valueBinaryB[i - 1], arraySobras[i]
        )

        contaResultado = f'{resultadoDaSoma}{contaResultado}'

        arraySobras[i - 1] = sobraDaSoma

        if (i - 1) == 0:
            contaResultado = f'{sobraDaSoma}{contaResultado}'

    return contaResultado[-quatidadeBytes:]


# Converte qualquer valor de qualquer base em decimal.
def convertInDecimal(
    anyNumber: str, anyBase: int, complementoDeDois: bool = False
) -> int:

    # Gerar um dicionario de simbulos
    dictiorySymbulos = {
        f'{number if number < 10 else chr(number+55)}': number
        for number in range(0, 36)
    }

    posicaoNow = len(anyNumber) - 1

    acumulador = 0

    for symbulo in anyNumber:

        # Procura o valor do simbolo no dicionário, após multiplica ele pela base de entrada elevada a posição atual.
        if (posicaoNow == (len(anyNumber) - 1)) and complementoDeDois:

            valorTemporario = -dictiorySymbulos[symbulo] * (
                anyBase**posicaoNow
            )
            acumulador += valorTemporario

        else:
            acumulador += dictiorySymbulos[symbulo] * (anyBase**posicaoNow)

        posicaoNow -= 1

    return acumulador


# Função para converter um número decimal para qualquer outra base.
def convertDecimalInAnyBase(decimalValue: int, anyBase: int) -> str:

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


# Função para gerar números aleatórios.
def binaryRandom(quantidadeBytes: int = 4, seed: int = 15) -> str:

    numeroAletório = (time_ns()) ** 2

    binaryAleatorio = convertDecimalInAnyBase(
        (numeroAletório + seed + time_ns()), 2
    )[-quantidadeBytes:]

    return binaryAleatorio


# Função para mostrar o resultado da roleta formatado com cores.
def printResul(fortuna_infortunio: str):

    valorEmDecimal = convertInDecimal(
        fortuna_infortunio, 2, complementoDeDois=True
    )

    if valorEmDecimal >= 0:
        print(f'\033[92m Fortuna! +{valorEmDecimal} \033[00m')
    else:
        print(f'\033[91m Infortúnio! {valorEmDecimal} \033[00m')


# Gera a partir de um número binário os 8 digitos antes dele e os 7 digitos após ele, em complemento de 2
def geradorDeRoda(fortuna_infortunio: str):

    decimalValue = convertInDecimal(fortuna_infortunio, 2, True)

    rodaLadoA = [
        f'{"+" if nun >= 0 else ""}{nun}'
        for nun in range(-8, decimalValue)
        if nun != decimalValue
    ]

    rodaLadoB = [
        f'{"+" if nun >= 0 else ""}{nun}' for nun in range(decimalValue + 1, 8)
    ]

    if len(rodaLadoA) < 8:

        quantosFalta = len(rodaLadoA) - 8

        rodaLadoA = rodaLadoB[quantosFalta:] + rodaLadoA

        rodaLadoB = rodaLadoB[:7]
    elif len(rodaLadoA) > 8:

        quantosExcedem = len(rodaLadoA) - 8

        rodaLadoB = rodaLadoB + rodaLadoA[:quantosExcedem]

        rodaLadoA = rodaLadoA[quantosExcedem:]

    roda = (
        rodaLadoA
        + [f"{'+' if decimalValue >= 0 else ''}{decimalValue}"]
        + rodaLadoB
    )

    return roda


# Função para 'Rodar' a roda no terminal, por padão a função 'roda' a roda em sentido horário.
def rodaRoda(
    roda: list, quantidadeDeVezes: int = 1, reverse: bool = True
) -> None:

    while quantidadeDeVezes:

        for nun in range(len(roda)):

            if nun != 8:

                print(f'{roda[nun]} ', end='')

            else:

                print(f'\033[95m{roda[nun]} \033[00m', end='')

        print('\r', end='')

        sleep(0.3)

        if not reverse:

            roda = [roda[15]] + roda[:-1]

        elif reverse:
            roda = roda[1:] + [roda[0]]

        quantidadeDeVezes -= 1

    print('')


def roda_da_fortuna(fortuna_infortúnio: str, tentativa: int) -> str:

    roda = geradorDeRoda(fortuna_infortúnio)

    sua_sorte = binaryRandom(seed=time_ns())

    binariosSomados = bsum(fortuna_infortúnio, sua_sorte, quatidadeBytes=4)

    if fortuna_infortúnio != binariosSomados:

        fortuna_infortúnio = binariosSomados
    else:
        while fortuna_infortúnio == binariosSomados:

            sua_sorte = binaryRandom(seed=time_ns())

            binariosSomados = bsum(
                fortuna_infortúnio, sua_sorte, quatidadeBytes=4
            )

        fortuna_infortúnio = binariosSomados

    sua_sorte_em_decimal = convertInDecimal(sua_sorte, 2)

    rodaRoda(roda, sua_sorte_em_decimal + 1, reverse=True)

    printResul(fortuna_infortúnio)

    sleep(0.8)

    (print(f'Você tem {tentativa} tentativas')) if tentativa != 0 else None

    return fortuna_infortúnio


# Função que inicia o jogo.
def app():

    fortuna_infortunio = binaryRandom(seed=time_ns())

    roda = geradorDeRoda(fortuna_infortunio)

    fortuna_infortunio_em_decimal = convertInDecimal(
        fortuna_infortunio, 2, True
    )


    rodaRoda(roda)
    
    print(f'A roleta está em {fortuna_infortunio_em_decimal}')

    print('Girando roleta . . .')

    sua_sorte = binaryRandom(seed=(time_ns() + 2))

    binarios_somados = bsum(fortuna_infortunio, sua_sorte, quatidadeBytes=4)

    fortuna_infortunio = binarios_somados

    sua_sorte_em_decimal = convertInDecimal(sua_sorte, 2)

    rodaRoda(roda, sua_sorte_em_decimal + 1, reverse=True)

    printResul(fortuna_infortunio)

    continue_sim_ou_nao = input('Você quer (s) jogar ou (d) desistir? ')

    if continue_sim_ou_nao != 's':
        return 1

    for tentativa in range(3, 0, -1):

        print(f'Fortuna ou Infortúnio! O que será?')

        sleep(0.8)

        roda_da_fortuna(fortuna_infortunio, tentativa - 1)

        if (tentativa - 1) != 0:

            para_ou_continua = input('p de Para ou c de Continua? ')
            if para_ou_continua != 'c':
                break

    return 1


if '__main__' == __name__:
    app()
