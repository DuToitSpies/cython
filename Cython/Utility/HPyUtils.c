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

HPy HPyType_FromModuleAndSpec(HPyContext *ctx, HPy module, HPyType_Spec *spec, HPy bases)
{
    HPyType_SpecParam temp_params[] = {
        { HPyType_SpecParam_BasesTuple, bases },
        /* unfortunately, not yet supported by HPy */
        /* { HPyType_SpecParam_Module, module }, */
        { (HPyType_SpecParam_Kind)0 }
    };
    HPy result;
    if (!HPy_IsNull(bases)) {
        result = HPyType_FromSpec(ctx, spec, temp_params);
    } else {
        /* we must not pass bases if it is HPy_NULL */
        result = HPyType_FromSpec(ctx, spec, NULL);
    }
    /* TODO(fa): remove once HPy supports 'HPyType_SpecParam_Module' */
    if (!HPy_IsNull(result) && !HPy_IsNull(module)) {
        PyHeapTypeObject *ht = (PyHeapTypeObject *) HPy_AsPyObject(ctx, result);
        ht->ht_module = HPy_AsPyObject(ctx, module);
        Py_DECREF(ht);
    }
    return result;
}
#endif
