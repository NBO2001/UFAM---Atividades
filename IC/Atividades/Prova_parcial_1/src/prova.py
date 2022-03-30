# A prova foi feita no papel e com pouco tempo
# Releve o péssimo nome das funções e variavéis

# Questão 1
def pontos(p1,p2): 

    a, b = p1
    c, d = p2

    if ( a + c)%5 == 0: return a+c
    if ( a + d)%5 == 0: return a+d
    if ( b + c)%5 == 0: return b+c
    if ( b + d)%5 == 0: return b+d
    else: return 0

# Questão 2
def retira_y(x, xs): return [y for y in xs if y != x]

def retira(ks, xs):

    for k in ks:
        xs = retira_y(k, xs)
    
    return xs

# Questão 3
def divs(x): return [ div_num for div_num in range(1, x+1) if (x%div_num) == 0]

# Questão 4
def tuples_equals(tups): return [(a, b) for a, b in tups if a == b]

def maior_number(list_tupes):
    maiorA, maiorB = list_tupes[0]
    maior = (maiorA, maiorB)

    for c, d in list_tupes:
        
        if maiorA <= c:
            maior = (c, d)
    
    return maior

def nomax(m):
    maiorA, maiorB = maior_number(tuples_equals(m))
    return [ (a,b) for a,b in m if maiorA !=a and maiorB != b]