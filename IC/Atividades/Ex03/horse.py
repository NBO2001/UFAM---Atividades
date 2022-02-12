"""
Explicação em: https://github.com/NBO2001/UFAM---Atividades/blob/main/IC/Atividades/Ex03/Enunciado.md
"""

#Devolve o modulo de um número
def modulo(x):
    if x > 0:
        return x
    else:
        return x*(-1)

#Verifica se está no tabuleiro de xadrez
def is_on_table(x, y)-> bool:

    vx, vy = (8,8)

    if (
        x > 0 and x <= vx
        and
        y > 0 and y <= vy
    ):
        return True
    else:
        return False

def possivel(x1,y1,x2,y2) -> bool:

    # Verifica se está no tabuleiro
    if (
        not(is_on_table)
        ):
        return False
    # Verifica se soma dos modulos é 3
    elif ( 
        (modulo(x1-x2) + modulo(y1-y2)) == 3 
        ):
        return True
    else:
        return False