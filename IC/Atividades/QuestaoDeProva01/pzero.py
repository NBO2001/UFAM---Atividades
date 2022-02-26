
def progressao_aritimetica(primeiro_termo,segundo_termo,terceiro_termo):
    # (2,4,6,8) r = 2 => (4,6,2)
    if(
        ( (primeiro_termo-segundo_termo) == terceiro_termo )
        or
        ( (terceiro_termo-primeiro_termo) == segundo_termo )
        or
        ( (segundo_termo-primeiro_termo) == terceiro_termo )
        or
        ( (primeiro_termo-terceiro_termo) == segundo_termo)
        or
        ((terceiro_termo-segundo_termo) == primeiro_termo )
        or
        ( (segundo_termo-terceiro_termo) == primeiro_termo )
    ):
        return True
    else:
        return False

def progressao_geometrica(primeiro_termo,segundo_termo,terceiro_termo):
    # (1,2,4,8) r = 2 => (4,8,2)
    if(
        ( (primeiro_termo/segundo_termo) == terceiro_termo )
        or
        ( (terceiro_termo/primeiro_termo) == segundo_termo )
        or
        ( (segundo_termo/primeiro_termo) == terceiro_termo )
        or
        ( (primeiro_termo/terceiro_termo) == segundo_termo)
        or
        ((terceiro_termo/segundo_termo) == primeiro_termo )
        or
        ( (segundo_termo/terceiro_termo) == primeiro_termo )
    ):
        return True
    else:
        return False

def orx(a,b):
    if (a or b) and (a != b):
        return True
    else:
        return False

def pag(a,b,c):
    if ( progressao_aritimetica(a,b,c) or progressao_geometrica(a,b,c)):
        return True
    else:
        return False


def pgp(vl,i):
    if i >= 60:
        return  ((vl*60)/100)
    elif i >= 2 and i <= 10:
        return  ((vl*50)/100)
    elif i >=0 and i < 2:
        return  ((vl*10)/100)
    else:
        return  vl