//////////////////// HPyHelperFuncs.proto ////////////////////

#if CYTHON_USING_HPY
static CYTHON_INLINE PyObject ** HPy_AsPyObjectArray(HPyContext *ctx, HPy *h_arr, HPy_ssize_t n);
#endif

//////////////////// HPyHelperFuncs ////////////////////

#if CYTHON_USING_HPY
static CYTHON_INLINE PyObject **
HPy_AsPyObjectArray(HPyContext *ctx, HPy *h_arr, HPy_ssize_t n)
{
    if (!h_arr)
        return NULL;
    PyObject **arr = PyMem_RawCalloc(n, sizeof(PyObject *));
    HPy_ssize_t i;
    for (i = 0; i < n; i++) {
        arr[i] = HPy_AsPyObject(ctx, h_arr[i]);
    }
    return arr;
}
#endif