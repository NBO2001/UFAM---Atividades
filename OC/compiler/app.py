
def convertStrInHex(caracter):
    return(str(hex(ord(caracter))))

def printOnlyC(caracter, register):
    print(f"data {register} {convertStrInHex(caracter)}")
    print(f"out data,{register}")

def printOperation(value):
    cont = 2
    print(f"data r0 0x80")
    print(f"out addr,r0")
    for c in value:
        cont += 3
        printOnlyC(c, "r1")
    print("xor r0,r0")
    print(f"out addr,r0")
    cont += 3
    print(f"jmp {str(hex(cont))}")




name = '''Teus cabelos me enlouquecem. ;-;
            ass., NBO'''

printOperation(name)