def conta(c):
    if c <= 5:
        return 50
    elif (c > 5) and (c <= 10):
        amais = c - 5
        return 50 + (amais * 10)
    else:
        amais = c - 5
        return 50 + (amais * 5)
