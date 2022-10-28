#pasta de cada cada problema deve ter N arquivos X.in e N arquivos X.sol
#X.in é a entrada e X.sol é a saída do caso teste X, 1<=X<=N

#passar como argumentos o local da pasta do problema
#e local do codigo com a solucao
#codigo precisa ter sufixo da linguagem

#saida do programa:
#   primeira linha indica veredito:
#       0: certo
#       1: errado (inclui erro de apresentacao)
#       2: erro de compilacao
#       3: erro em tempo de execucao (valor de retorno != 0)
#       4: tempo limite excedido
#   se valor na primeira linha for diferente de 0,
#   linhas seguintes contem mais detalhes
#   erros de compilacao e execucao incluem saida da stderr



import subprocess
import filecmp
import sys
import glob
import pathlib


#nome usado para arquivos temporarios com codigo compilado e saida
name = 'judge_temp'
#tempo limite por caso teste em segundos
time_limit = 1

#para colocar input como argumentos na linha de comando
problem = pathlib.PurePath(sys.argv[1])
code = pathlib.PurePath(sys.argv[2])
test_cases_number = len(glob.glob1(problem, '*.in'))

#para usar input com stdin (duas linhas)
##problem = pathlib.PurePath(input())
##code = pathlib.PurePath(input())
##test_cases_number = len(glob.glob1(problem, '*.in'))


if code.suffix == '.py':
    command = ['python3', str(code)]

elif code.suffix == '.c':
    r = subprocess.run(['gcc', str(code), '-o', name, '-O2', '-static', '-lm'],
                       capture_output=True)
    if r.returncode != 0:
        print(2)
        print(r.stderr.decode('utf-8'))
        sys.exit()
    command = './' + name

else:
    r = subprocess.run(['g++', str(code), '-o', name, '-O2', '-static'],
                       capture_output=True)
    if r.returncode != 0:
        print(2)
        print(r.stderr)
        sys.exit()
    command = './' + name



for i in range(1, test_cases_number+1):
    path = str(problem) + '/' + str(i)
    inp = open(path+'.in', 'r')
    out = open(name+'.out', 'w')

    try:
        r = subprocess.run(command, stdin=inp, stdout=out,
                           stderr=subprocess.PIPE, timeout=time_limit)
    except subprocess.TimeoutExpired:
        inp.close()
        out.close()
        print(4)
        print("Primeiro teste incorreto:", i)
        sys.exit()

    inp.close()
    out.close()

    if r.returncode != 0:
        print(3)
        print("Primeiro teste incorreto:", i)
        print(r.stderr.decode('utf-8'))
        sys.exit()

    if filecmp.cmp(name+'.out', path+'.sol'):
        continue

    print(1)
    print("Primeiro teste incorreto:", i)
    print(r.stderr.decode('utf-8'))

    sys.exit()

print(0)
