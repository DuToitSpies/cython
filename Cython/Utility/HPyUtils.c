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

static HPyType_SpecParam* get_temp_specparams(HPyContext *ctx) {
    HPyType_SpecParam temp_params[] = {
            { HPyType_SpecParam_Base, ctx->h_LongType },
            { (HPyType_SpecParam_Kind)0 }
    };
    return temp_params;
}
#endif