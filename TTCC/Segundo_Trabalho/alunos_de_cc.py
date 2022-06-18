import pdb
import pandas as pd
from os import walk
from utils import decribe_data, read_base, save_table


def seach_in_ac(folder, direce_lis, label='Sem_Cota'):

    anos = []
    alunos = []
    desc_p = []

    in_file = tuple(walk(f'./dados/Tabs/{folder}'))

    for file in in_file[0][2]:
        # breakpoint()
        base_teste = pd.read_csv(
            f'./dados/Tabs/{folder}/{file}',
            encoding='UTF-8',
        )
        # print(base_teste['FORMA_INGRESSO'].unique())

        for cota in direce_lis:
            try:
                base_teste = base_teste.loc[
                    base_teste['FORMA_INGRESSO'] != cota
                ]
            except:
                breakpoint()
                print('Error')

        if len(base_teste['ANO']):
            anos.append(base_teste['ANO'].unique()[0])
            desc_p.append(base_teste['DESCR_PERIODO'].unique()[0])

            alunos.append(len(base_teste['ID_PESSOA'].unique()))

    return {'Anos': anos, 'Desc_p': desc_p, f'T_a_{label}': alunos}


def seach_in(folder):

    anos = []
    alunos = []
    desc_p = []
    for _, _, files in walk(f'./dados/Tabs/{folder}'):

        for file in files:
            base_teste = pd.read_csv(
                f'./dados/Tabs/{folder}/{file}',
                encoding='UTF-8',
            )
            # print(base_teste['FORMA_INGRESSO'].unique())

            base_teste = base_teste.loc[
                base_teste['FORMA_INGRESSO']
                != 'SISU - AC (Ampla Concorrência)'
            ]
            base_teste = base_teste.loc[
                base_teste['FORMA_INGRESSO'] != 'PSC - AC (Ampla Concorrência)'
            ]

            base_teste = base_teste.loc[
                base_teste['FORMA_INGRESSO']
                != 'PECG - Programa Estudantil Convênio de Graduação'
            ]
            base_teste = base_teste.loc[
                base_teste['FORMA_INGRESSO']
                != 'SISU - AC (Ampla Concorrência)'
                'Transferência Ex-Ofício (Obrigatória)'
            ]

            if len(base_teste['ANO']):
                anos.append(base_teste['ANO'].unique()[0])
                desc_p.append(base_teste['DESCR_PERIODO'].unique()[0])

                alunos.append(base_teste['ID_PESSOA'].count())

    return {'Anos': anos, 'Desc_p': desc_p, 'T_a': alunos}


# print("Reprovados_cota")
# tabl = pd.DataFrame(seach_in("calculo_1/reprovados"))
# tab1 = tabl.sort_values(by='Anos')

# tab2 = pd.DataFrame(seach_in("calculo_1/aprovados"))

# tab2 = tab2.sort_values(by='Anos')

# tab5 = tab1.groupby('Anos')['Total_alunos'].apply(sum)

# print(tab5)

# print("Aprovados")
# print(tab2)


cotas = [
    'PSC - PPI2 (Esc. Pub., Independe Renda)',
    'PSC - NDC1 (Esc. Pub., Renda até 1.5)',
    'SISU - PPI1 (Esc. Pub., Renda até 1.5)',
    'PSC - PPI1 (Esc. Pub., Renda até 1.5)',
    'SISU - NDC1 (Esc. Pub., Renda até 1.5)',
    'SISU - NDC2 (Esc. Pub., Independe Renda)',
    'SISU - PPI2 (Esc. Pub., Independe Renda)',
    'SISU - PPI2-PCD (Esc. Pub., Independe Renda - PCD)',
    'SISU - PPI1 (Esc. Pub., Renda até 1.5)',
    'PSC - PPI1-PCD (Esc. Pub., Renda até 1.5 - PCD)',
    'PSC - NDC2 (Esc. Pub., Independe Renda)',
]

ampla = [
    'SISU - AC (Ampla Concorrência)',
    'PSC - AC (Ampla Concorrência)',
    'PECG - Programa Estudantil Convênio de Graduação',
    'Mandado Judicial',
    'SISU - AC (Ampla Concorrência)' 'Transferência Ex-Ofício (Obrigatória)',
    'PSE - Reopção de Curso',
    'PSE - Portador de Diploma',
]

tabela_aprovados_sem_cota = pd.DataFrame(
    seach_in_ac('calculo_1/aprovados', cotas, 'aprovados_sn_cota')
)

tabela_aprovados_sem_cota = tabela_aprovados_sem_cota.sort_values(by='Anos')
# breakpoint()
tabela_reprovados_sem_cota = pd.DataFrame(
    seach_in_ac('calculo_1/reprovados', cotas, 'reprovados_sn_cota')
)

tabela_reprovados_sem_cota = tabela_reprovados_sem_cota.sort_values(by='Anos')
tabela_reprovados_sem_cota = tabela_reprovados_sem_cota.drop(
    columns=['Desc_p']
)
# tabela_reprovados_sem_cota = tabela_reprovados_sem_cota.groupby('Anos')['Total_alunos'].apply(sum)


result = pd.merge(
    tabela_aprovados_sem_cota, tabela_reprovados_sem_cota, on='Anos'
)


save_table(result, name='resul_ac', path='./dados/Tabs/calculo_1/')


tabela_aprovados_com_cota = pd.DataFrame(
    seach_in_ac('calculo_1/aprovados', ampla, 'aprovados_cn_cota')
)
tabela_aprovados_com_cota = tabela_aprovados_com_cota.sort_values(by='Anos')

tabela_reprovados_com_cota = pd.DataFrame(
    seach_in_ac('calculo_1/reprovados', ampla, 'reprovados_cn_cota')
)
tabela_reprovados_com_cota = tabela_reprovados_com_cota.sort_values(by='Anos')
tabela_reprovados_com_cota = tabela_reprovados_com_cota.drop(
    columns=['Desc_p']
)
# tabela_reprovados_sem_cota = tabela_reprovados_sem_cota.groupby('Anos')['Total_alunos'].apply(sum)


result_cota = pd.merge(
    tabela_aprovados_com_cota, tabela_reprovados_com_cota, on='Anos'
)
save_table(result_cota, name='resul_cotas', path='./dados/Tabs/calculo_1/')


tabela_aprovados_sem_cota = pd.DataFrame(
    seach_in_ac('ic/aprovados', cotas, 'aprovados_sn_cota')
)
tabela_aprovados_sem_cota = tabela_aprovados_sem_cota.sort_values(by='Anos')

tabela_reprovados_sem_cota = pd.DataFrame(
    seach_in_ac('ic/reprovados', cotas, 'reprovados_sn_cota')
)
tabela_reprovados_sem_cota = tabela_reprovados_sem_cota.sort_values(by='Anos')
tabela_reprovados_sem_cota = tabela_reprovados_sem_cota.drop(
    columns=['Desc_p']
)
# tabela_reprovados_sem_cota = tabela_reprovados_sem_cota.groupby('Anos')['Total_alunos'].apply(sum)


result = pd.merge(
    tabela_aprovados_sem_cota, tabela_reprovados_sem_cota, on='Anos'
)


save_table(result, name='resul_ac', path='./dados/Tabs/ic/')


tabela_aprovados_com_cota = pd.DataFrame(
    seach_in_ac('ic/aprovados', ampla, 'aprovados_cn_cota')
)
tabela_aprovados_com_cota = tabela_aprovados_com_cota.sort_values(by='Anos')

tabela_reprovados_com_cota = pd.DataFrame(
    seach_in_ac('ic/reprovados', ampla, 'reprovados_cn_cota')
)
tabela_reprovados_com_cota = tabela_reprovados_com_cota.sort_values(by='Anos')
tabela_reprovados_com_cota = tabela_reprovados_com_cota.drop(
    columns=['Desc_p']
)
# tabela_reprovados_sem_cota = tabela_reprovados_sem_cota.groupby('Anos')['Total_alunos'].apply(sum)


result_cota = pd.merge(
    tabela_aprovados_com_cota, tabela_reprovados_com_cota, on='Anos'
)
save_table(result_cota, name='resul_cotas', path='./dados/Tabs/ic/')


tabela_aprovados_sem_cota = pd.DataFrame(
    seach_in_ac('md/aprovados', cotas, 'aprovados_sn_cota')
)
tabela_aprovados_sem_cota = tabela_aprovados_sem_cota.sort_values(by='Anos')

tabela_reprovados_sem_cota = pd.DataFrame(
    seach_in_ac('md/reprovados', cotas, 'reprovados_sn_cota')
)
tabela_reprovados_sem_cota = tabela_reprovados_sem_cota.sort_values(by='Anos')
tabela_reprovados_sem_cota = tabela_reprovados_sem_cota.drop(
    columns=['Desc_p']
)
# tabela_reprovados_sem_cota = tabela_reprovados_sem_cota.groupby('Anos')['Total_alunos'].apply(sum)


result = pd.merge(
    tabela_aprovados_sem_cota, tabela_reprovados_sem_cota, on='Anos'
)


save_table(result, name='resul_ac', path='./dados/Tabs/md/')


tabela_aprovados_com_cota = pd.DataFrame(
    seach_in_ac('md/aprovados', ampla, 'aprovados_cn_cota')
)
tabela_aprovados_com_cota = tabela_aprovados_com_cota.sort_values(by='Anos')

tabela_reprovados_com_cota = pd.DataFrame(
    seach_in_ac('md/reprovados', ampla, 'reprovados_cn_cota')
)
tabela_reprovados_com_cota = tabela_reprovados_com_cota.sort_values(by='Anos')
tabela_reprovados_com_cota = tabela_reprovados_com_cota.drop(
    columns=['Desc_p']
)
# tabela_reprovados_sem_cota = tabela_reprovados_sem_cota.groupby('Anos')['Total_alunos'].apply(sum)


result_cota = pd.merge(
    tabela_aprovados_com_cota, tabela_reprovados_com_cota, on='Anos'
)
save_table(result_cota, name='resul_cotas', path='./dados/Tabs/md/')


tabela_aprovados_sem_cota = pd.DataFrame(
    seach_in_ac('ttcc/aprovados', cotas, 'aprovados_sn_cota')
)
tabela_aprovados_sem_cota = tabela_aprovados_sem_cota.sort_values(by='Anos')

tabela_reprovados_sem_cota = pd.DataFrame(
    seach_in_ac('ttcc/reprovados', cotas, 'reprovados_sn_cota')
)
tabela_reprovados_sem_cota = tabela_reprovados_sem_cota.sort_values(by='Anos')
tabela_reprovados_sem_cota = tabela_reprovados_sem_cota.drop(
    columns=['Desc_p']
)
# tabela_reprovados_sem_cota = tabela_reprovados_sem_cota.groupby('Anos')['Total_alunos'].apply(sum)


result = pd.merge(
    tabela_aprovados_sem_cota, tabela_reprovados_sem_cota, on='Anos'
)


save_table(result, name='resul_ac', path='./dados/Tabs/ttcc/')


tabela_aprovados_com_cota = pd.DataFrame(
    seach_in_ac('ttcc/aprovados', ampla, 'aprovados_cn_cota')
)
tabela_aprovados_com_cota = tabela_aprovados_com_cota.sort_values(by='Anos')

tabela_reprovados_com_cota = pd.DataFrame(
    seach_in_ac('ttcc/reprovados', ampla, 'reprovados_cn_cota')
)
tabela_reprovados_com_cota = tabela_reprovados_com_cota.sort_values(by='Anos')
tabela_reprovados_com_cota = tabela_reprovados_com_cota.drop(
    columns=['Desc_p']
)
# tabela_reprovados_sem_cota = tabela_reprovados_sem_cota.groupby('Anos')['Total_alunos'].apply(sum)


result_cota = pd.merge(
    tabela_aprovados_com_cota, tabela_reprovados_com_cota, on='Anos'
)
save_table(result_cota, name='resul_cotas', path='./dados/Tabs/ttcc/')

tabela_aprovados_com_cota = pd.DataFrame(
    seach_in_ac('ttcc/aprovados', ampla, 'aprovados_cn_cota')
)
tabela_aprovados_com_cota = tabela_aprovados_com_cota.sort_values(by='Anos')

tabela_reprovados_com_cota = pd.DataFrame(
    seach_in_ac('ttcc/reprovados', ampla, 'reprovados_cn_cota')
)
tabela_reprovados_com_cota = tabela_reprovados_com_cota.sort_values(by='Anos')
tabela_reprovados_com_cota = tabela_reprovados_com_cota.drop(
    columns=['Desc_p']
)
# tabela_reprovados_sem_cota = tabela_reprovados_sem_cota.groupby('Anos')['Total_alunos'].apply(sum)


result_cota = pd.merge(
    tabela_aprovados_com_cota, tabela_reprovados_com_cota, on='Anos'
)
save_table(result_cota, name='resul_cotas', path='./dados/Tabs/ttcc/')
