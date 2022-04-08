try:
    from math import sqrt
except Exception as e:
    raise TypeError(f'Preciso da math lib para funcinar')


def xp(n: int) -> bool:

    if n >= 0 and n <= 100 and n % 5 == 0 and n % 3 == 0:
        return True
    else:
        return False


def amarelo(
    x1: int or float, y1: int or float, x2: int or float, y2: int or float
) -> float:
    # Get the height
    height = y2 - y1

    # Division by 2
    lA = height / 2

    # Get the hypotenuse
    lado_is = sqrt((lA ** 2) + (lA ** 2))

    # Calcuter the area
    area_is = lado_is ** 2

    return f'{area_is:.2f}'
