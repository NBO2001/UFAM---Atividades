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
    table.to_csv(f'{path}{name}.csv', encoding='utf-8', index=False)


def decribe_data(table: pd.DataFrame, path: str = './dados/Tabs/'):

    ano = ((table['ANO']).unique())[0]
    situan = ((table['DESCR_PERIODO']).unique())[0]

    alunos_aprovados = table.loc[table['DESCR_SITUACAO'] == 'Aprovado']
    save_table(alunos_aprovados, f'alunos_aprovados_{ano}_{situan}', path)

    total_alunos, _ = table.shape

    quatidade_aprovados, _ = alunos_aprovados.shape

    alunos_reprovados_por_falta = table.loc[
        table['DESCR_SITUACAO'] == 'Reprovado por Freqüência'
    ]
    save_table(
        alunos_reprovados_por_falta,
        f'reprovados_por_falta_{ano}_{situan}',
        path,
    )

    quatidade_reprovados_por_falta, _ = alunos_reprovados_por_falta.shape
    alunos_reprovados_por_nota = table.loc[
        table['DESCR_SITUACAO'] == 'Reprovado por Nota'
    ]
    save_table(
        alunos_reprovados_por_nota, f'reprovados_por_nota_{ano}_{situan}', path
    )
    quatidade_reprovados_por_nota, _ = alunos_reprovados_por_nota.shape

    return (
        ano,
        situan,
        total_alunos,
        quatidade_aprovados,
        quatidade_reprovados_por_falta,
        quatidade_reprovados_por_nota,
    )


def print_itens(table):
    (
        ano,
        situan,
        total_alunos,
        quatidade_aprovados,
        quatidade_reprovados_por_falta,
        quatidade_reprovados_por_nota,
    ) = decribe_data(table)
    print(f'Ano: {ano}')
    print(f'Total de alunos: {total_alunos}')
    print(f'Aprovados {quatidade_aprovados}')
    print(
        f'Reprovados total: { quatidade_reprovados_por_falta + quatidade_reprovados_por_nota}\n ----- \n'
    )
    print(f'Reprovados por falta: {quatidade_reprovados_por_falta}')
    print(f'Reprovados por nota: {quatidade_reprovados_por_nota}')

    print('\n--------\n')


def prepare_data(datas):
    anos = []
    situans = []
    total_alunos = []
    alunos_aprovados = []
    total_de_reprovados = []
    alunos_reprovados_por_nota = []
    alunos_aprovados_por_falta = []

    for data in datas:
        ano, situan, alunos_t, alunos_p, alunos_rn, alunos_rf = data
        anos.append(ano)
        situans.append(situan)
        total_alunos.append(alunos_t)
        alunos_aprovados.append(alunos_p)
        total_de_reprovados.append(alunos_rn + alunos_rf)
        alunos_reprovados_por_nota.append(alunos_rn)
        alunos_aprovados_por_falta.append(alunos_rf)

    return {
        'Ano': anos,
        'Periodo': situans,
        'Alunos_Aprovados': alunos_aprovados,
        'Alunos_Reprovados': total_de_reprovados,
        'Total_de_Alunos': total_alunos,
    }
