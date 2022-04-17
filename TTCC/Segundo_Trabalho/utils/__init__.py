import pandas as pd


def read_base(
    path: str,
    colluns: list = [
        'ID_PESSOA',
        'DESCR_SITUACAO',
        'DESCR_PERIODO',
        'MEDIA_FINAL',
        'ANO',
    ],
    with_loc=True,
    encond='ISO-8859-1',
):
    dt_notas_md = pd.read_csv(f'{path}', encoding=encond, sep=';')

    try:
        dt_notas_md = dt_notas_md.loc[dt_notas_md['ID_PESSOA'] != '#N/D']
        dt_notas_md['ID_PESSOA'] = pd.to_numeric(
            dt_notas_md['ID_PESSOA'], errors='coerce'
        ).convert_dtypes()
    except:
        dt_notas_md = pd.read_csv(f'{path}', encoding='ISO-8859-1', sep=';')

    if with_loc:
        return dt_notas_md.loc[:, colluns]
    else:
        return dt_notas_md


def save_table(
    table: pd.DataFrame, name: str = 'Analizy', path: str = './dados/Tabs/'
):
    table.to_csv(f'{path}{name}.csv', encoding='utf-8')


def decribe_data(table: pd.DataFrame, path: str = './dados/Tabs/'):

    ano = ((table['ANO']).unique())[0]
    situan = ((table['DESCR_PERIODO']).unique())[0]

    table = table.loc[table['NUM_VERSAO'] == '2016/1']

    alunos_aprovados = table.loc[table['DESCR_SITUACAO'] == 'Aprovado']
    save_table(alunos_aprovados, f'alunos_aprovados_{ano}_{situan}', path)

    total_alunos = len(table['ID_PESSOA'].unique())
    
    quatidade_aprovados = len(alunos_aprovados['ID_PESSOA'].unique())

    alunos_reprovados_por_falta = table.loc[
        table['DESCR_SITUACAO'] != 'Aprovado'
    ]
    
    save_table(
        alunos_reprovados_por_falta,
        f'reprovados_{ano}_{situan}',
        path,
    )

    quatidade_reprovados = len(alunos_reprovados_por_falta['ID_PESSOA'].unique())

    return (
        ano,
        situan,
        total_alunos,
        quatidade_aprovados,
        quatidade_reprovados,
    )


def print_itens(table):
    (
        ano,
        situan,
        total_alunos,
        quatidade_aprovados,
        quatidade_reprovados_por_falta,
    ) = decribe_data(table)
    print(f'Ano: {ano}')
    print(f'Total de alunos: {total_alunos}')
    print(f'Aprovados {quatidade_aprovados}')
    print(f'Reprovados total: { quatidade_reprovados_por_falta}\n ----- \n')

    print('\n--------\n')


def prepare_data(datas):
    anos = []
    situans = []
    total_alunos = []
    alunos_aprovados = []
    total_de_reprovados = []

    for data in datas:
        ano, situan, alunos_t, alunos_p, alunos_rnf = data
        anos.append(ano)
        situans.append(situan)
        total_alunos.append(alunos_t)
        alunos_aprovados.append(alunos_p)
        total_de_reprovados.append(alunos_rnf)

    return {
        'Ano': anos,
        'Periodo': situans,
        'Alunos_Aprovados': alunos_aprovados,
        'Alunos_Reprovados': total_de_reprovados,
        'Total_de_Alunos': total_alunos,
    }
