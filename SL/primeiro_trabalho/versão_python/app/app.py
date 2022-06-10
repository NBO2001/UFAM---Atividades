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


def bsum(valueBinaryA, valueBinaryB):

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

    return contaResultado


def convertInDecimal(anyNumber: str, anyBase: int) -> int:

    dictiorySymbulos = {
        f'{number if number < 10 else chr(number+55)}': number
        for number in range(0, 36)
    }

    posicaoNow = len(anyNumber) - 1

    acumulador = 0

    for symbulo in anyNumber:

        acumulador += dictiorySymbulos[symbulo] * (anyBase**posicaoNow)

        posicaoNow -= 1

    return acumulador


def convertDecimalInAnyBase(decimalValue: int, anyBase) -> str:

    dictiorySymbulos = {
        number: f'{number if number < 10 else chr(number+55)}'
        for number in range(0, 36)
    }

    stringRetorn = ''

    if decimalValue >= 0:
        while decimalValue > 0:
            restoDivisao = decimalValue % anyBase

            stringRetorn = f'{dictiorySymbulos[restoDivisao]}{stringRetorn}'

            decimalValue = decimalValue // anyBase

    return stringRetorn


def main(numberAndBaseOrigem, baseDestiny):

    itsNumebrInDecimalis = convertInDecimal(
        numberAndBaseOrigem[0], numberAndBaseOrigem[1]
    )

    itsNumebrInDestiny = convertDecimalInAnyBase(
        itsNumebrInDecimalis, baseDestiny
    )

    return itsNumebrInDestiny


if __name__ == '__main__':

    while True:
        
        numberA = input('Digite um número na base de origem: ')
        baseA = int(input('Qual a base? '))

        userTyped = input('Qual a base de destino? ')
        baseB = int(userTyped) if userTyped else 10

        numberAndBaseOrigem = (numberA, baseA)

        numberEndIs = main(numberAndBaseOrigem, baseB)

        print(numberEndIs)

        if input('Deseja converter outro numero? [S/N]') == 'N':
            break
