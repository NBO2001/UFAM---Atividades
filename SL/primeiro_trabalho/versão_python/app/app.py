def convertInDecimal(anyNumber: str, anyBase: int) -> int:

    dictiorySymbulos = {
        f'{number if number < 10 else chr(number+55)}': number
        for number in range(0, 16)
    }

    ultimaPosicaoDoNumero = len(anyNumber) - 1

    acumulador = 0

    for symbulo in anyNumber:

        acumulador += dictiorySymbulos[symbulo] * (
            anyBase**ultimaPosicaoDoNumero
        )

        ultimaPosicaoDoNumero -= 1

    return acumulador


def main():

    pass


main()
