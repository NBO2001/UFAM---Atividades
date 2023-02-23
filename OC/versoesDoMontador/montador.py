import sys

global stack


def convert_instruction(instruction):

    codes = {
        'add': '8',
        'shr': '9',
        'shl': 'a',
        'not': 'b',
        'and': 'c',
        'or': 'd',
        'xor': 'e',
        'cmp': 'f',
        'ld': '0',
        'st': '1',
        'data': '2',
        'jmpr': '3',
        'jmp': '40',
        'jc': '58',
        'ja': '54',
        'je': '52',
        'jz': '51',
        'jca': '5c',
        'jce': '5a',
        'jcz': '59',
        'jae': '56',
        'jez': '53',
        'jaz': '55',
        'jcae': '5e',
        'jcaz': '5d',
        'jcez': '5b',
        'jaez': '57',
        'jcaez': '5f',
        'clf': '60',
        'in': '7',
        'out': '7',
    }
    assert (instruction in codes.keys(), 'Invalide Key')
    return codes[instruction]


def isOutInput(inOut):
    return inOut == 'in' or inOut == 'out'


def binHex(binNumber):
    hexDic = {
        '0000': '0',
        '0001': '1',
        '0010': '2',
        '0011': '3',
        '0100': '4',
        '0101': '5',
        '0110': '6',
        '0111': '7',
        '1000': '8',
        '1001': '9',
        '1010': 'a',
        '1011': 'b',
        '1100': 'c',
        '1101': 'd',
        '1110': 'e',
        '1111': 'f',
    }
    return hexDic[binNumber]


def registConvet(rg):
    dicregistrs = {
        'r0': '00',
        'r1': '01',
        'r2': '10',
        'r3': '11',
        'addr': '1',
        'data': '0',
        'in': '0',
        'out': '1',
    }
    return dicregistrs[rg]


def convertInHexCode(listRegistrs):

    binStr = ''

    listRegistrs = listRegistrs.split(',')

    tam = len(listRegistrs)

    if tam == 1:
        binStr = f'{binStr}00'

    for register in listRegistrs:
        binStr = f'{binStr}{registConvet(register.strip())}'

    return binHex(binStr)


def isInstruction(value):

    if isinstance(value, str):

        if value[:2] == '0x':
            return False
        else:
            return True

    else:
        return False


def clearString(strValues):

    listArgvs = strValues.strip().lower().replace(' ', ',').split(',')

    intructionList = []

    n = len(listArgvs)

    secondIsInst = False

    instcode = ''
    if isInstruction(listArgvs[0]):
        instcode = f'{instcode}{convert_instruction(listArgvs[0])}'

    if n > 1 and isInstruction(listArgvs[1]):

        if not isOutInput(listArgvs[0]):
            instcode = f'{instcode}{convertInHexCode(listArgvs[1])}'

            secondIsInst = True
        else:
            lisargvs = [lsT.strip() for lsT in listArgvs[1].split(',')]

            instcode = f'{instcode}{binHex(f"{registConvet(listArgvs[0])}{registConvet(lisargvs[0])}{registConvet(lisargvs[1])}")}'

            intructionList.append(instcode)

            return intructionList

    intructionList.append(instcode)

    if n > 2 and secondIsInst:

        intructionList.append(listArgvs[2][2:])

    elif n > 1 and not secondIsInst:

        intructionList.append(listArgvs[1][2:])

    return intructionList


def parse_input_file(asm_file):

    hex_code = []

    with open(asm_file, 'r') as f:
        lines = [clearString(line) for line in f.readlines()]
        for line in lines:
            for code in line:
                if len(code) > 0:
                    hex_code.append(code)

    return hex_code


def write_outputfile(memory_file, hexaCode):

    tam = len(hexaCode)
    cnt = 0
    with open(memory_file, 'w') as f:
        f.write('v3.0 hex words plain\n')

        for i in range(16):

            for j in range(16):

                if cnt < tam:
                    f.write(f'{hexaCode[cnt]}\t')
                    cnt += 1
                else:
                    f.write(f'00\t')

            f.write(f'\n')


def main(asm_file, memory_file):

    hexaCode = parse_input_file(asm_file)
    write_outputfile(memory_file, hexaCode)


if __name__ == '__main__':

    n = len(sys.argv)

    assert n == 3, 'Ivalidade arguments'

    main(sys.argv[1], sys.argv[2])
