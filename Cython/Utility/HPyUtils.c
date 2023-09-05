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

#if CYTHON_USING_HPY
HPy __Pyx_Type_FromSpec(HPyContext *ctx, HPy module, HPyType_Spec *spec, HPy base)
{
    HPyType_SpecParam temp_params[] = {
        { HPyType_SpecParam_Base, ctx->h_LongType },
        { (HPyType_SpecParam_Kind)0 }
    };
    HPy type = HPyType_FromSpec(ctx, spec, temp_params);
    return type;
}
#else
static inline PyObject *__Pyx_Type_FromSpec(PyObject *module, PyType_Spec *spec, PyObject *bases)
{
    return PyType_FromModuleAndSpec(module, spec, bases);
}
#endif