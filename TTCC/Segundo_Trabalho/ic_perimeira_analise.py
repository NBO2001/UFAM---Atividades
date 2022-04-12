from os import walk
import pandas as pd
from utils import decribe_data, read_base, prepare_data,save_table

base_data = []
alunos_base = read_base(
        './dados/Anonimizados/alunos-IE08-2022-03-18.csv',
        ['ID_PESSOA', 'DT_NASCIMENTO', 'FORMA_INGRESSO', 'PERIODO_INGRESSO', 'NUM_VERSAO'],
    )

for _, _, files in walk('./dados/Anonimizados/IC/'):
    for file in files:
        merge_tables = pd.merge(read_base(f'./dados/Anonimizados/IC/{file}'),alunos_base)
        base_data.append(
            decribe_data(
                merge_tables,
                './dados/Tabs/ic/',
            )
        )


tabl = pd.DataFrame(prepare_data(base_data))


tab1 = tabl.sort_values(by='Ano')
save_table(tab1, name="Geral", path="./dados/Tabs/ic/")
