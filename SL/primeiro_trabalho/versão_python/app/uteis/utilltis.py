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