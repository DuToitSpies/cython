#mode: run

import cython

cdef class Shrubbery:
    cdef int width
    cdef int height

    def __init__(self, w, h):
        self.width = w
        self.height = h

def add_coords(a:int, b:int):
    """
    >>> add_coords(1, 2)
    3
    """
    point = Shrubbery(1, 2)
    return point.width + point.height