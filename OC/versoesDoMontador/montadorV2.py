import code
import sys

instStack = []
pilhasCodicoes = []
endLine = -1


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

    if not instruction in codes.keys():
        return 'null'

    return codes[instruction]


def typeOfInstrution(instruction):

    codes = {
        'add': 2,
        'shr': 2,
        'shl': 2,
        'not': 2,
        'and': 2,
        'or': 2,
        'xor': 2,
        'cmp': 2,
        'ld': 2,
        'st': 2,
        'data': 4,
        'jmpr': 1,
        'jmp': 3,
        'jc': 3,
        'ja': 3,
        'je': 3,
        'jz': 3,
        'jca': 3,
        'jce': 3,
        'jcz': 3,
        'jae': 3,
        'jez': 3,
        'jaz': 3,
        'jcae': 3,
        'jcaz': 3,
        'jcez': 3,
        'jaez': 3,
        'jcaez': 3,
        'clf': 0,
        'in': 5,
        'out': 5,
    }

    return codes[instruction]


def isOutInput(inOut):
    return inOut == 'in' or inOut == 'out'


def isCondition(string):

    strBrute = string.strip().split()
    strBrute = strBrute.pop(0)

    if not convert_instruction(strBrute):
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


# 0001
def isHexValue(value):
    if '0x' in value:
        return True
    else:
        return


# 0000 0011 => 1111 = f 1101 = d
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


def isCodeStart(string):

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

    if isCodeStart(lineCode):

        code = lineCode.strip().lower().split('(')

        conditionTag = code.pop(0)

        contition = code.pop(0).replace('):', '')

        if conditionTag == 'if':

            if createComparator(contition):
                instStack.append('40')
                instStack.append('ENDIF')
                endLine += 2
                pilhasCodicoes.append(endLine)
        elif conditionTag == 'while':
            pilhasCodicoes.append(endLine + 1)
            if createComparator(contition):
                instStack.append('40')
                instStack.append('ENDIF')
                endLine += 2
                pilhasCodicoes.append(endLine)

    else:
        code = lineCode.strip().lower()

        if code == 'endif':

            startCodeIn = str(hex(endLine + 1))[2:]
            startCodeIn = (
                startCodeIn if len(startCodeIn) == 2 else f'0{startCodeIn}'
            )

            instStack[pilhasCodicoes.pop()] = startCodeIn
        elif code == 'endwhile':
            endWhile = pilhasCodicoes.pop()
            startLoop = pilhasCodicoes.pop()

            instStack.append('40')

            startCodeIn = str(hex(startLoop))[2:]
            startCodeIn = (
                startCodeIn if len(startCodeIn) == 2 else f'0{startCodeIn}'
            )
            instStack.append(startCodeIn)

            endLine += 2

            startCodeIn = str(hex(endLine + 1))[2:]
            startCodeIn = (
                startCodeIn if len(startCodeIn) == 2 else f'0{startCodeIn}'
            )

            instStack[endWhile] = startCodeIn

        elif code == 'halt':
            instStack.append('40')
            startCodeIn = str(hex(endLine + 1))[2:]
            startCodeIn = (
                startCodeIn if len(startCodeIn) == 2 else f'0{startCodeIn}'
            )
            instStack.append(startCodeIn)


def processLine(lineCode):

    if isCondition(lineCode):
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
