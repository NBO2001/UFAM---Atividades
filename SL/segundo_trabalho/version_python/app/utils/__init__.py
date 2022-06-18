from datetime import timedelta
from time import localtime, time_ns


def random():
    d = timedelta(microseconds=-1)

    valorAleatorio = (d.microseconds * (localtime().tm_sec) + time_ns()) ** 2

    return valorAleatorio


def binaryRandom(quantidadeBytes=4, seed=0):

    numeroAletório = random()

    binaryAleatorio = convertDecimalInAnyBase(
        (numeroAletório + seed + time_ns()), 2
    )[-quantidadeBytes:]

    return binaryAleatorio


def qualValorEmDeci():
    return convertInDecimal(binaryRandom(), 2, True)


def sumBinary(binaryA, binaryB, resto='0'):

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


# Soma um binario '1010' + '10101'
def bsum(valueBinaryA: str, valueBinaryB: str, quatidadeBytes: int = 8):

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


# Qualquer base para decimal
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


# Função principal, responsável por fazer a integração entre as duas funções anteriores
def app(valorOriginal, baseDeEntrada=10, baseDestiny=10):

    arrayRetorn = []

    itsNumebrInDecimalis = convertInDecimal(valorOriginal, baseDeEntrada)

    itsNumebrInDestiny = convertDecimalInAnyBase(
        itsNumebrInDecimalis, baseDestiny
    )

    arrayRetorn.append(itsNumebrInDestiny)

    if baseDestiny != 10:
        arrayRetorn.append(baseDestiny)

    return arrayRetorn
