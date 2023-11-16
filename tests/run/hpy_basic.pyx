#mode: run

import cython

def add_int(a:int, b:int):
    """
    >>> add_int(1, 2)
    3
    """
    return a + b
