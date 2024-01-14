from avalicao import avaliacao
import pandas as pd
import os

if __name__ == "__main__":
  
    files_name = list()
    testes_exe = list()
    testes_pontuation = list()

    fps = os.listdir("./atividades")
    fps.sort()

    for file_name in fps:
        
        print(f"{file_name}")
        pontuacao, testes = avaliacao(file_name)

        files_name.append(file_name)
        testes_exe.append(testes)
        testes_pontuation.append(pontuacao)

    table = pd.DataFrame({'Student': files_name, 'Status_of_tests': testes_exe, 'Pontuation': testes_pontuation})

    table.to_csv('correcao.csv', index=False)

