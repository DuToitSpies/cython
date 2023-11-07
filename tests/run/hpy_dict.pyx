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
    dict_keys(['a', 2, 'abc'])
    """
    return d.keys()

def dict_copy(d):
    """
    >>> d = {'a': 123, 2: True, 'abc': 'def'}
    >>> dict_copy(d)
    {'a': 123, 2: True, 'abc': 'def'}
    """
    c = d.copy()
    return c

def dict_clear(d):
    """
    >>> d = {'a': 123, 2: True, 'abc': 'def'}
    >>> dict_clear(d)

    """
    return d.clear()

def dict_get(d, key):
    """
    >>> d = {'a': 123, 2: True, 'abc': 'def'}
    >>> dict_get(d, 2)
    True
    """
    return d.get(2)

def dict_items(d):
    """
    >>> d = {'a': 123, 2: True, 'abc': 'def'}
    >>> dict_items(d)
    dict_items([('a', 123), (2, True), ('abc', 'def')])
    """
    return d.items()

def dict_fromkeys(keys, val):
    """
    >>> ks = (1, 2, 3)
    >>> dict_fromkeys(ks, 0)
    {1: 0, 2: 0, 3: 0}
    """
    return dict.fromkeys(keys, val)

def dict_popitem(d):
    """
    >>> d = {'a': 123, 2: 5932}
    >>> dict_popitem(d)
    (2, 5932)
    """
    return d.popitem()

def dict_setdefault(d, key, value):
    """
    >>> d = {'a': 123, 2: 5932}
    >>> dict_setdefault(d, 2, 1234)
    5932
    >>> dict_setdefault(d, 'cs', 123)
    123
    """
    return d.setdefault(key, value)

def dict_update(d1, d2):
    """
    >>> d1 = {'a': 123, 2: 5932}
    >>> d2 = {'hpy': True}
    >>> dict_update(d1, d2)
    {'a': 123, 2: 5932, 'hpy': True}
    """
    d1.update(d2)
    return d1

def dict_values(d):
    """
    >>> d = {'a': 123, 2: True, 'abc': 'def'}
    >>> dict_values(d)
    dict_values([123, True, 'def'])
    """
    return d.values()
