from time import sleep, time_ns

from utils import binaryRandom, bsum, convertInDecimal


def printResul(fortuna_infortunio):

    valorEmDecimal = convertInDecimal(
        fortuna_infortunio, 2, complementoDeDois=True
    )

    if valorEmDecimal >= 0:
        print(f'\033[92m Fortuna! {valorEmDecimal} \033[00m')
    else:
        print(f'\033[91m Infortúnio! {valorEmDecimal} \033[00m')


def roda_da_fortuna(fortuna_infortúnio, tentativa):
    
    roda = geradorDeRoda(fortuna_infortúnio)

    sua_sorte = binaryRandom(seed=time_ns())

    binariosSomados = bsum(fortuna_infortúnio, sua_sorte, 4)

    fortuna_infortúnio = binariosSomados

    rodaRoda(roda, convertInDecimal( sua_sorte ,2)+1,revese=True)

    printResul(fortuna_infortúnio)

    sleep(0.8)

    (print(f'Você tem {tentativa} tentativas')) if tentativa != 0 else None

    return fortuna_infortúnio

def geradorDeRoda(fortuna_infortunio):

    decimalValue = convertInDecimal( fortuna_infortunio ,2,True)
    
    testeRodaA = [f'{"+" if nun >= 0 else ""}{nun}' for nun in range(-8,decimalValue)  if nun != decimalValue ]

    testeRodaB = [f'{"+" if nun >= 0 else ""}{nun}' for nun in range(decimalValue+1,8) ]

    if len(testeRodaA) < 8:

        quantosFalta = len(testeRodaA) - 8 
        
        testeRodaA = testeRodaB[quantosFalta:] + testeRodaA

        testeRodaB = testeRodaB[:7]
    elif len(testeRodaA) > 8:

        quantosExcedem = len(testeRodaA) - 8

        testeRodaB = testeRodaB + testeRodaA[:quantosExcedem]

        testeRodaA = testeRodaA[quantosExcedem:] 
    
    roda = testeRodaA + [f"{'+' if decimalValue >= 0 else ''}{decimalValue}"] + testeRodaB

    return roda


def app():

#    fortuna_infortunio = binaryRandom()
    fortuna_infortunio = '1001'

    print(f'A roda está em {convertInDecimal( fortuna_infortunio ,2,True)} {chr(2)}')

    roda = geradorDeRoda(fortuna_infortunio)
 
    rodaRoda(roda)

    sua_sorte = binaryRandom(seed=time_ns())
    
    binariosSomados = bsum(fortuna_infortunio, sua_sorte, quatidadeBytes=4)

    fortuna_infortunio = binariosSomados
    
    rodaRoda(roda, convertInDecimal( sua_sorte ,2)+1,revese=True)

    printResul(fortuna_infortunio)
    
    continue_is = input('Você quer (s) jogar ou (d) desistir?')
    if continue_is != 's':
        return 1

    for tentativa in range(3, 0, -1):

        print(f'Fortuna ou Infortúnio! O que será?')

        sleep(0.8)

        roda_da_fortuna(fortuna_infortunio, tentativa - 1)

        if (tentativa - 1) != 0:

            continue_is = input('p de Para ou c de Continua? ')
            if continue_is != 'c':
                break
    
    return 1


def rodaRoda(roda,quantidadeDeVezes=1, revese=False):

    while quantidadeDeVezes:
        for nun in range(len(roda)):
            if nun != 8:
                print(f'{roda[nun]} ', end='')
            else:
                print(f'\033[95m{roda[nun]} \033[00m', end='')
        
        print('\r',end='')
        sleep(0.4)
        
        if revese == False:
            roda = [roda[15]] + roda[:-1]
            
        elif revese == True:
            roda = roda[1:] + [roda[0]]

        quantidadeDeVezes -= 1
    
    print("")



# teste = ['-8','-7','-6','-5','-4','-3','-2','-1','+0', '+1','+2','+3','+4','+5','+6','+7']
# rodaRoda(teste,15)


if '__main__' == __name__:
    app()
