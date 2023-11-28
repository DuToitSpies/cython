import cython

class Circle:
    def __init__(self):
        self.radius = 10

    def radius_getter(self):
        return self.radius

def circle_init():
    """
    >>> circle_init()
    10
    """
    loop = Circle()
    return loop.radius

def get_circle_radius(circle):
    """
    >>> loop = Circle()
    >>> get_circle_radius(loop)
    10
    """
    return circle.radius