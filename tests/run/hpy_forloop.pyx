#mode: run

import cython

def add():
    """
    >>> add()
    49999995000000
    """
    a = 0
    for i in range(10000000):
        a = a + i
    return a
