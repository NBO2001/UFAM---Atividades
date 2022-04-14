import pandas as pd
from os import walk
from utils import decribe_data, read_base, prepare_data

for _, _, files in walk('./dados/Tabs/calculo_1/reprovados'):

    for file in files:
        base_teste = pd.read_csv(
            f'./dados/Tabs/calculo_1/reprovados/{file}',
            encoding='UTF-8',
        )
        print(base_teste['FORMA_INGRESSO'].unique())

        base_teste = base_teste.loc[
            base_teste['FORMA_INGRESSO'] != 'SISU - AC (Ampla Concorrência)'
        ]
        base_teste = base_teste.loc[
            base_teste['FORMA_INGRESSO'] != 'PSC - AC (Ampla Concorrência)'
        ]

        print(base_teste.tail())
