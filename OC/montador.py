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
        'move': {'hexVaue': 'nun', 'typeInstro': 6},
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


def isInstruction(string):

    strBrute = string.strip().split()
    strBrute = strBrute.pop(0)

    if convert_instruction(strBrute) == 'null':
        return False
    else:
        return True


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
        return False


def addrCovert(adrress):
    if isLabel(adrress):

            if existsInStackLabel(adrress):
                adrress = pilhasLabels[adrress]['value']
            else:
                pilhasLabels[adrress] = {
                    'addrOrIndex': 1,
                    'value': endLine + 2,
                }
                return adrress
    else:
        adrress = (
            adrress[2:] if isHexValue(adrress) else convertnumber(adrress)
        )

    return adrress


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


def isDecimalValue(value):

    for letter in value:

        if ord(letter) == 45 or ord(letter) == 43:
            continue

        elif not (48 <= ord(letter) <= 57) :
            return False


    return True


def isLabel(instro):

    if isHexValue(instro):
        return False
    elif isDecimalValue(instro):
        return False
    else:
        return True


def instructorProcessor(lineCode):
    global instStack
    global endLine
    global pilhasLabels

    listArgvs = lineCode.strip().lower().replace(' ', ',').split(',')

    instrutionAssemble = listArgvs.pop(0)

    instrution = convert_instruction(instrutionAssemble)

    typeInst = typeOfInstrution(instrutionAssemble)

    if typeInst == 0:
        instStack.append(instrution)
        endLine += 1

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

        adrress = addrCovert(listArgvs.pop(0))

        instStack.append(f'{instrution}')
        instStack.append(adrress)

        endLine += 2

    elif typeInst == 4:

        rb = registConvet(listArgvs.pop(0))

        secPart = binHex(f'00{rb}')

        adrress = addrCovert(listArgvs.pop(0))

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
    elif typeInst == 6:
        ra = registConvet(listArgvs.pop(0))
        rb = registConvet(listArgvs.pop(0))

        xorRB = f"e{binHex(f'{rb}{rb}')}"
        addRARB = f"8{binHex(f'{ra}{rb}')}"
        instStack.append(xorRB)
        instStack.append(addRARB)
        endLine += 2
        


def isLabelLine(string):

    if ':' in string or not ('.' in string):
        return True
    else:
        return False

def conditionProcessor(lineCode):
    global instStack
    global endLine
    global pilhasCodicoes
    global pilhasLabels

    if ":" in lineCode:

        lineCode = lineCode.strip().lower()

        lineLabel = lineCode[:-1]

        if existsInStackLabel(lineLabel):
            endhexLineValue = str(hex(endLine + 1))
            endhexLineValue = (
                endhexLineValue[2:]
                if len(endhexLineValue[2:]) == 2
                else f'0{endhexLineValue[2:]}'
            )
            indexDesteni = pilhasLabels[lineLabel]['value']

            instStack[indexDesteni] = endhexLineValue

        else:
            lineInhex = str(hex(endLine + 1))

            lineInhex = lineInhex[2:]
            lineInhex = lineInhex if len(lineInhex) == 2 else f'0{lineInhex}'

            pilhasLabels[lineLabel] = {'addrOrIndex': 0, 'value': lineInhex}
    else:

        lineCode = lineCode.strip()
        if lineCode == 'halt':
            instStack.append('40')
            endLine += 1
            startCodeIn = str(hex(endLine))[2:]
            startCodeIn = (
                startCodeIn if len(startCodeIn) == 2 else f'0{startCodeIn}'
            )
            instStack.append(startCodeIn)
            endLine += 1

def vectorProcessor(lineCode):
    global instStack
    global endLine

    lineCode = lineCode.strip().lower().split()
    value = addrCovert(lineCode[1])
    instStack.append(value)
    endLine += 1


def processLine(lineCode):

    if isInstruction(lineCode):
        return instructorProcessor(lineCode)
    elif isLabelLine(lineCode):
        return conditionProcessor(lineCode)
    else:
        return vectorProcessor(lineCode)
        


def parse_input_file(asm_file):
    global endLine
    global instStack

    with open(asm_file, 'r') as f:
        
        for line in f.readlines():
            if len(line.strip()) > 0:
                processLine(line)


def write_outputfile(memory_file):
    global instStack

    tam = len(instStack)
    cnt = 0
    with open(f'{memory_file}.m', 'w') as f:
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
