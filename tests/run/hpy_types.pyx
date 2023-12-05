import cython

class Shape:
    def __init__(self, colour):
        self.colour = colour

    def get_colour(self):
        return self.colour

    def set_colour(self, colour):
        self.colour = colour

class Circle(Shape):
    def __init__(self, colour, radius):
        Shape.__init__(self, colour)
        self.radius = radius

    def get_radius(self):
        return self.radius

    def set_radius(self, radius):
        self.radius = radius

def get_circle_radius(circle):
    """
    >>> loop = Circle("red", 11)
    >>> get_circle_radius(loop)
    11
    """
    return circle.get_radius()
