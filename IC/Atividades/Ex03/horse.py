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

def is_integer(vl):
    """
    Como não posso usar outros métodos,
    já que não foi visto em aula, verificarei se o número é inteiro apenas usando funções matématica vistas em aula.
    """
    mul = (vl*10)
    rest = mul%5
    if(not((rest))):
        
        resul_div = mul/5
        # Se o resto do for par, significa que a o número termina com 0
        return not(resul_div%2)
    else:
        return False

def possivel(x1,y1,x2,y2) -> bool:
    #Verifica se alguma cordenada é flutuante
    if (
        not is_integer(x1) or not is_integer(y1)
        or
        not is_integer(x2) or not is_integer(y2)
    ):
        return False
    # Verifica se está no tabuleiro
    elif (
        not(is_on_table(x2,y2))
        ):
        return False
    # Verifica se soma dos modulos é 3
    elif ( 
        (modulo(x1-x2) + modulo(y1-y2)) == 3 
        ):
        return True
    else:
        return False