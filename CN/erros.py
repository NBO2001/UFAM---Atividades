from math import pi, e, sqrt

def erro_abs(valor_real, valor_aproximado):

	return abs(valor_real - valor_aproximado)

def erro_relativo(valor_real, valor_aproximado):

	return abs(valor_real - valor_aproximado)/abs(valor_real)


def app(valor_real, valor_aproximado):
	print(f'Valor real (p): { valor_real }')
	print(f'Valor aproximado (p): { valor_aproximado }')
	print(f'Erro absoluto: {erro_abs(valor_real, valor_aproximado):.4f}')
	print(f'Erro relativo: {erro_relativo(valor_real, valor_aproximado):.4f}')

#app(pi, 22/7)
#app(pi, 3.1416)
#app(e, 2.718)
#app(sqrt(2), 1.414)
