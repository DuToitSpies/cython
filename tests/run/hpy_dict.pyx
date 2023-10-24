#mode: run

def create_dict():
    """
    >>> create_dict()
    {'a': 123, 2: 5932}
    """
    d = {'a': 123, 2: 5932}
    return d

def dict_pop(d, key):
    """
    >>> d = {'a': 123, 2: 5932}
    >>> dict_pop(d, 2)
    5932
    """
    return d.pop(key)

def dict_modify(d, pos, value):
    """
    >>> d = test = {'a': 123, 2: 5932}
    >>> dict_modify(d, 2, True)
    {'a': 123, 2: True}
    >>> dict_modify(d, 'abc', 'def')
    {'a': 123, 2: True, 'abc': 'def'}
    """
    d[pos] = value
    return d

def dict_keys(d):
    """
    >>> d = {'a': 123, 2: True, 'abc': 'def'}
    >>> dict_keys(d)
    ['a', 2, 'abc']
    """
    return d.keys()
