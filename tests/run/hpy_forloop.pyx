#mode: run

import cython

def add():
    """
    >>> add()
    4999999950000000
    """
    a = 0
    for i in range(100000000):
        a = a + i
    return a
