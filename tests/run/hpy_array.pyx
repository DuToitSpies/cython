#mode: run

def create_array():
    """
    >>> create_array()
    [1, 2, 'a', 'b', True]
    """
    arr = [1, 2, 'a', 'b', True]
    return arr

def array_pop(arr, index):
    """
    >>> arr = [1, 2, 'a', 'b', True]
    >>> array_pop(arr, 2)
    [1, 2, 'b', True]
    """
    arr.pop(index)
    return arr

def array_append(arr, value):
    """
    >>> arr = [1, 2, 'a', 'b', True]
    >>> array_append(arr, 3)
    [1, 2, 'a', 'b', True, 3]
    """
    arr.append(value)
    return arr

def array_extend(arr, new_arr):
    """
    >>> arr = [1, 2, 'a', 'b', True]
    >>> new_arr = [3, 4, '#']
    >>> array_extend(arr, new_arr)
    [1, 2, 'a', 'b', True, 3, 4, '#']
    """
    arr.extend(new_arr)
    return arr

def array_clear(arr):
    """
    >>> arr = [1, 2, 'a', 'b', True]
    >>> array_clear(arr)

    """
    return arr.clear()

def array_copy(arr):
    """
    >>> arr = [1, 2, 'a', 'b', True]
    >>> array_copy(arr)
    [1, 2, 'a', 'b', True]
    """
    arr2 = arr.copy()
    return arr2

def array_count(arr):
    """
    >>> arr = [1, 2, 'a', 'b', False, 1]
    >>> array_count(arr)
    2
    """
    return arr.count(1)

def array_index(arr, val):
    """
    >>> arr = [1, 2, 'a', 'b', False, 1]
    >>> array_index(arr, 1)
    0
    >>> array_index(arr, 2)
    1
    """
    return arr.index(val)

def array_insert(arr, index, val):
    """
    >>> arr = [1, 2, 'a', 'b', False, 1]
    >>> array_insert(arr, 3, 4)
    [1, 2, 'a', 4, 'b', False, 1]
    """
    arr.insert(index, val)
    return arr

def array_remove(arr, value):
    """
    >>> arr = [1, 2, 'a', 'b', False, 1]
    >>> array_remove(arr, 1)
    [2, 'a', 'b', False, 1]
    """
    arr.remove(value)
    return arr

def array_reverse(arr):
    """
    >>> arr = [1, 2, 'a', 'b', False]
    >>> array_reverse(arr)
    [False, 'b', 'a', 2, 1]
    """
    arr.reverse()
    return arr

def array_sort(arr):
    """
    >>> arr = [1, 2, 10, 3, 11, -5, 6]
    >>> array_sort(arr)
    [-5, 1, 2, 3, 6, 10, 11]
    """
    arr.sort()
    return arr