#mode: run
#tag: hpy

import cython

@cython.hpy
def add():
    """
    >>> add()
    3
    """
    return 1+2