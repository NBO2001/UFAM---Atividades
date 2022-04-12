import pandas as pd
from utils import decribe_data, read_base, prepare_data


base_teste = pd.read_csv("./dados/Tabs/calculo_1/alunos_aprovados_2014_ 1° Semestre.csv", encoding="UTF-8")

base_teste = pd.read_excel("./dados/tx_rend_escolas_2020/tx_rend_escolas_2020.xlsx")

print(base_teste['FORMA_INGRESSO'].unique())

base_teste = base_teste.loc[base_teste['FORMA_INGRESSO'] != 'SISU - AC (Ampla Concorrência)']
base_teste = base_teste.loc[base_teste['FORMA_INGRESSO'] != 'PSC - AC (Ampla Concorrência)']

print(base_teste.tail())
