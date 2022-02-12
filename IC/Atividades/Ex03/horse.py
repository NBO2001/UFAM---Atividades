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

    if(
        not(is_on_table)
        ):
        return False
    elif (
        modulo(x1-x2) == 2 
        and 
        modulo(y1-y2)==1
        ):
        return True
    elif(
        modulo(y1-y2) == 2
        and
        modulo(x1-x2) == 1
        ):
        return True
    else:
        return False