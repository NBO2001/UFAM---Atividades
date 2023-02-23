import code
import sys

instStack = []
pilhasCodicoes = []
endLine = -1
pilhasLabels = {}


def existsInStackLabel(key):
    global pilhasLabels

    if key in pilhasLabels.keys():
        return True
    else:
        return False


def consultInstro(instruction):

    codes = {
        'add': {'hexVaue': '8', 'typeInstro': 2},
        'shr': {'hexVaue': '9', 'typeInstro': 2},
        'shl': {'hexVaue': 'a', 'typeInstro': 2},
        'not': {'hexVaue': 'b', 'typeInstro': 2},
        'and': {'hexVaue': 'c', 'typeInstro': 2},
        'or': {'hexVaue': 'd', 'typeInstro': 2},
        'xor': {'hexVaue': 'e', 'typeInstro': 2},
        'cmp': {'hexVaue': 'f', 'typeInstro': 2},
        'ld': {'hexVaue': '0', 'typeInstro': 2},
        'st': {'hexVaue': '1', 'typeInstro': 2},
        'data': {'hexVaue': '2', 'typeInstro': 4},
        'jmpr': {'hexVaue': '3', 'typeInstro': 1},
        'jmp': {'hexVaue': '40', 'typeInstro': 3},
        'jc': {'hexVaue': '58', 'typeInstro': 3},
        'ja': {'hexVaue': '54', 'typeInstro': 3},
        'je': {'hexVaue': '52', 'typeInstro': 3},
        'jz': {'hexVaue': '51', 'typeInstro': 3},
        'jca': {'hexVaue': '5c', 'typeInstro': 3},
        'jce': {'hexVaue': '5a', 'typeInstro': 3},
        'jcz': {'hexVaue': '59', 'typeInstro': 3},
        'jae': {'hexVaue': '56', 'typeInstro': 3},
        'jez': {'hexVaue': '53', 'typeInstro': 3},
        'jaz': {'hexVaue': '55', 'typeInstro': 3},
        'jcae': {'hexVaue': '5e', 'typeInstro': 3},
        'jcaz': {'hexVaue': '5d', 'typeInstro': 3},
        'jcez': {'hexVaue': '5b', 'typeInstro': 3},
        'jaez': {'hexVaue': '57', 'typeInstro': 3},
        'jcaez': {'hexVaue': '5f', 'typeInstro': 3},
        'clf': {'hexVaue': '60', 'typeInstro': 0},
        'in': {'hexVaue': '7', 'typeInstro': 5},
        'out': {'hexVaue': '7', 'typeInstro': 5},
    }

    if not instruction in codes.keys():
        return 'null'

    return codes[instruction]


def convert_instruction(instruction):
    intro = consultInstro(instruction)
    return intro['hexVaue'] if intro != 'null' else 'null'


def typeOfInstrution(instruction):
    intro = consultInstro(instruction)
    return intro['typeInstro'] if intro != 'null' else 'null'


def isOutInput(inOut):
    return inOut == 'in' or inOut == 'out'


def isCondition(string):

    strBrute = string.strip().split()
    strBrute = strBrute.pop(0)

    if convert_instruction(strBrute) != 'null':
        return True
    else:
        return False


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


def inOrOut(string):
    if string == 'in':
        return 0
    else:
        return 1


def dataOrAddr(string):

    if string == 'data':
        return 0
    else:
        return 1


def isHexValue(value):
    if '0x' in value:
        return True
    else:
        return


def convertnumber(number):

    num = int(number)

    binNum = ''
    cont = 0
    while cont < 8:

        if num & 1:
            binNum = f'1{binNum}'
        else:
            binNum = f'0{binNum}'

        num = num >> 1
        cont += 1

    hexValue = f'{binHex(binNum[:4])}{binHex(binNum[4:])}'
    return hexValue


def instructorProcessor(lineCode):
    global instStack
    global endLine

    listArgvs = lineCode.strip().lower().replace(' ', ',').split(',')

    instrutionAssemble = listArgvs.pop(0)

    instrution = convert_instruction(instrutionAssemble)

    typeInst = typeOfInstrution(instrutionAssemble)

    if typeInst == 0:
        instStack.append(instrution)

    elif typeInst == 1:

        rb = registConvet(listArgvs.pop(0))

        secPart = binHex(f'00{rb}')

        instStack.append(f'{instrution}{secPart}')
        endLine += 1

    elif typeInst == 2:

        ra = registConvet(listArgvs.pop(0))
        rb = registConvet(listArgvs.pop(0))

        secPart = binHex(f'{ra}{rb}')
        instStack.append(f'{instrution}{secPart}')

        endLine += 1

    elif typeInst == 3:

        adrress = listArgvs.pop(0)[2:]

        instStack.append(f'{instrution}')
        instStack.append(adrress)

        endLine += 2

    elif typeInst == 4:

        rb = registConvet(listArgvs.pop(0))

        secPart = binHex(f'00{rb}')

        tmpAddr = listArgvs.pop(0)
        adrress = (
            tmpAddr[2:] if isHexValue(tmpAddr) else convertnumber(tmpAddr)
        )

        instStack.append(f'{instrution}{secPart}')
        instStack.append(adrress)

        endLine += 2

    elif typeInst == 5:

        dtOrOut = listArgvs.pop(0)
        rb = registConvet(listArgvs.pop(0))
        secPart = binHex(
            f'{inOrOut(instrutionAssemble)}{dataOrAddr(dtOrOut)}{rb}'
        )
        instStack.append(f'{instrution}{secPart}')
        endLine += 1


def isLabelLine(string):

    if ':' in string:
        return True
    else:
        return False


def createComparator(string):

    global instStack
    global endLine
    global pilhasCodicoes

    string = string.split()
    ra = string.pop(0)
    flag = string.pop(0)
    rb = string.pop(0)

    instStack.append('60')
    endLine += 1

    ra = registConvet(ra)
    rb = registConvet(rb)

    if flag == '==' or flag == '>' or flag == '<':

        secPart = binHex(f'{ra}{rb}') if flag != '<' else binHex(f'{rb}{ra}')
        instruction = f'f{secPart}'

        instStack.append(instruction)
        endLine += 1

        jmpInst = '52' if flag == '==' else '54'

        instStack.append(jmpInst)
        endLine += 1

        startCodeIn = str(hex(endLine + 4))[2:]
        startCodeIn = (
            startCodeIn if len(startCodeIn) == 2 else f'0{startCodeIn}'
        )

        instStack.append(startCodeIn)
        endLine += 1

        return 1
    elif flag == '!=':
        secPart = binHex(f'{ra}{rb}')
        instruction = f'f{secPart}'

        instStack.append(instruction)
        endLine += 1

        jmpInst = '52'

        instStack.append(jmpInst)
        endLine += 1

        instStack.append('ENDIF')
        endLine += 1
        pilhasCodicoes.append(endLine)
        return 0


def conditionProcessor(lineCode):
    global instStack
    global endLine
    global pilhasCodicoes

    if isLabelLine(lineCode):

        lineCode = lineCode.split()
        lineLabel = lineCode[:-1]
        breakpoint()
        pass
    else:
        pass


def processLine(lineCode):

    if not isCondition(lineCode):

        return conditionProcessor(lineCode)
    else:
        return instructorProcessor(lineCode)


def parse_input_file(asm_file):
    global endLine
    global instStack

    with open(asm_file, 'r') as f:

        for line in f.readlines():

            processLine(line)


def write_outputfile(memory_file):
    global instStack

    tam = len(instStack)
    cnt = 0
    with open(memory_file, 'w') as f:
        f.write('v3.0 hex words plain\n')

        for i in range(16):

            for j in range(16):

                if cnt < tam:
                    f.write(f'{instStack[cnt]}\t')
                    cnt += 1
                else:
                    f.write(f'00\t')

            f.write(f'\n')


def main(asm_file, memory_file):
    global endLine
    global instStack

    parse_input_file(asm_file)
    write_outputfile(memory_file)


if __name__ == '__main__':

    n = len(sys.argv)

    assert n == 3, 'Ivalidade arguments'

    main(sys.argv[1], sys.argv[2])

"""
 -> Tudo Minuscula
 -> Separacao entre operador e operando devem ser um espaco
 -> Separacao entre operando deve ser uma vigula (sem espaco)
 -> Numero podem ser hexa ou decimais (se for decimal pode ser negativo)
 -> nao pode ter linhas vazias
 -> Nao pode ter linhas com apenas cometarios
 -> Os comentarios comecam com #
 -> Labels sao indentificaados por : (sem espacos e carate especial)
"""
