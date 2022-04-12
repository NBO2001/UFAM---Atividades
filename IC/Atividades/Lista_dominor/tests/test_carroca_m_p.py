from pytest import mark

from src.terceira_parte import carroca_m_p


@mark.parametrize(
    'mesa',
    [
        ([5, 5], [2], [1], [5]),
        ([5], [5], [0, 0], [5]),
        ([5, 5], [4], [0, 0], [3]),
    ],
)
def test_uma_ponta_sendo_carroca(mesa):
    assert carroca_m_p(mesa) == True


@mark.parametrize(
    'mesa', [([3], [2], [0], [5]), ([2], [4], [2], [3]), ([5], [4], [0], [5])]
)
def test_uma_ponta_sem_carroca(mesa):
    assert carroca_m_p(mesa) == False
