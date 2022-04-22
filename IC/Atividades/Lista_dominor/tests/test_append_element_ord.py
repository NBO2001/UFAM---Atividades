from src.unificada import append_element_ord


def test_append_element_ord_lista_Em_ordem_no_final():
    assert append_element_ord(5, [2, 3, 4]) == [2, 3, 4, 5]


def test_append_element_ord_lista_Em_ordem_no_meio():
    assert append_element_ord(3, [2, 4, 5]) == [2, 3, 4, 5]
