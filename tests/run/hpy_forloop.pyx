#mode: run

import cython

def add():
    a = 0
    for i in range(100):
        a = a + i
    return a