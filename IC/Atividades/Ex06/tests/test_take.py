from src.Ex06 import drop, head, init, last, rfinal, tail, take


def test_retornado_os_5_primeiros_elementos():
    assert take(5, [5, 8, 9, 7, 4, 6, 2, 8]) == [5, 8, 9, 7, 4]


def test_retornado_os_3_primeiros_elementos():
    assert take(3, [5, 84, 58, 8, 9, 7, 4, 6, 2, 8]) == [5, 84, 58]


def test_retornado_os_0_primeiros_elementos():
    assert take(0, [5, 84, 58, 8, 9, 7, 4, 6, 2, 8]) == []


def test_retornado_os_5_ultimos_elementos():
    assert drop(5, [5, 8, 9, 7, 4, 6, 2, 8]) == [7, 4, 6, 2, 8]


def test_retornado_os_3_ultimos_elementos():
    assert drop(3, [5, 84, 58, 8, 9, 7, 4, 6, 2, 8]) == [6, 2, 8]


def test_retornado_o_primeiro_elemento():
    assert head([5, 84, 58, 8, 9, 7, 4, 6, 2, 8]) == 5


def test_retornado_o_ultimo_elemento():
    assert last([5, 84, 58, 8, 9, 7, 4, 6, 2, 8]) == 8


def test_retornado_lista_sem_ultimo_elemento():
    assert tail([5, 84, 58, 8, 9, 7, 4, 6, 2, 8]) == [
        84,
        58,
        8,
        9,
        7,
        4,
        6,
        2,
        8,
    ]


def test_retornado_lista_sem_ultimo_elemento():
    assert init([5, 84, 58, 8, 9, 7, 4, 6, 2, 8]) == [
        5,
        84,
        58,
        8,
        9,
        7,
        4,
        6,
        2,
    ]


def test_exercicio_dois():
    assert rfinal(
        [
            (22152258, 10, 90),  # Aprovado
            (22152259, 5, 80),  # Aprovado
            (22152260, 4, 50),  # Reprovado por nota e falta
            (22152261, 8, 50),  # Reprovado por falta
            (22152262, 6, 90),  # Aprovado
            (22152263, 4, 90),  # Reprovado por nota
        ]
    ) == (
        [(22152258, 10, 90), (22152259, 5, 80), (22152262, 6, 90)],
        [(22152263, 4, 90)],
        [(22152261, 8, 50)],
        [(22152260, 4, 50)],
    )
