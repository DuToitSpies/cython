#mode: run

def test_arg(arg):
    """
    >>> test_arg(1)
    1
    >>> test_arg(1.25)
    1.25
    >>> test_arg(True)
    True
    >>> test_arg("HPy")
    'HPy'
    >>> test_arg((1,2))
    (1, 2)
    >>> test_arg(None)
    
    """
    return arg
