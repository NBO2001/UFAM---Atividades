# Primeiro exercicio de Introdução a computação

# Função com o intuito de retornar a media final

# Tenho com base:
#   MF = (MEEX2) + PF
#               3


def mf(mee, pf=0):

    # Verifica os tipos das váriaveis recebidas
    if not isinstance(mee, float) and not isinstance(mee, int):
        raise TypeError(f'O valor: {mee} não é um número inteiro ou flutuante')

    if not isinstance(pf, float) and not isinstance(pf, int):
        raise TypeError(f'O valor: {pf} não é um número inteiro ou flutuante')

    # Retorna o resultado
    return ((mee * 2) + pf) / 3.0
