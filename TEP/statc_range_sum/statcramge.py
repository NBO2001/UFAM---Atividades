
n, ques = [ int(y) for y in input().split() ]

lista = [ int(y) for y in input().split() ]

for i in range(ques):
    a,b = [ int(y) for y in input().split() ]
    print(sum(lista[a-1:b]))