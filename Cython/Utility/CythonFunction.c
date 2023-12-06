
//////////////////// CythonFunctionShared.proto ////////////////////

#define __Pyx_CyFunction_USED

#define __Pyx_CYFUNCTION_STATICMETHOD  0x01
#define __Pyx_CYFUNCTION_CLASSMETHOD   0x02
#define __Pyx_CYFUNCTION_CCLASS        0x04
#define __Pyx_CYFUNCTION_COROUTINE     0x08

#define __Pyx_CyFunction_GetClosure(f) \
    (((__pyx_CyFunctionObject *) (f))->func_closure)

#if PY_VERSION_HEX < 0x030900B1 || (CYTHON_COMPILING_IN_LIMITED_API && !CYTHON_USING_HPY)
  #define __Pyx_CyFunction_GetClassObj(f) \
      (((__pyx_CyFunctionObject *) (f))->func_classobj)
#else
  #define __Pyx_CyFunction_GetClassObj(f) \
      ((PyObject*) ((PyCMethodObject *) (f))->mm_class)
#endif
#define __Pyx_CyFunction_SetClassObj(f, classobj)  \
    __Pyx__CyFunction_SetClassObj((__pyx_CyFunctionObject *) (f), (classobj))

#define __Pyx_CyFunction_Defaults(type, f) \
    ((type *)(((__pyx_CyFunctionObject *) (f))->defaults))
#define __Pyx_CyFunction_SetDefaultsGetter(f, g) \
    ((__pyx_CyFunctionObject *) (f))->defaults_getter = (g)

#if !CYTHON_USING_HPY
    #define __pyx_CyFunctionObject_FuncDef __pyx_CyFunctionObject *
#else
    #define __pyx_CyFunctionObject_FuncDef HPy
#endif

typedef struct {
#if !CYTHON_USING_HPY
#if CYTHON_COMPILING_IN_LIMITED_API
    PyObject_HEAD
    // We can't "inherit" from func, but we can use it as a data store
    PyObject *func;
#elif PY_VERSION_HEX < 0x030900B1
    PyCFunctionObject func;
#else
    // PEP-573: PyCFunctionObject + mm_class
    PyCMethodObject func;
#endif
#if CYTHON_BACKPORT_VECTORCALL
    __pyx_vectorcallfunc func_vectorcall;
#endif
#if (CYTHON_COMPILING_IN_LIMITED_API && !CYTHON_USING_HPY)
    PyObject *func_weakreflist;
#endif
#if PY_VERSION_HEX < 0x030900B1 || (CYTHON_COMPILING_IN_LIMITED_API && !CYTHON_USING_HPY)
    // No-args super() class cell
    PyObject *func_classobj;
#endif
#if CYTHON_BACKPORT_VECTORCALL
    __pyx_vectorcallfunc func_vectorcall;
#endif
#else /* !CYTHON_USING_HPY */
    HPyDef *func;
#endif /* !CYTHON_USING_HPY */
    PYOBJECT_FIELD_TYPE func_self;
    PYOBJECT_FIELD_TYPE func_module;
    PYOBJECT_FIELD_TYPE func_dict;
    PYOBJECT_FIELD_TYPE func_name;
    PYOBJECT_FIELD_TYPE func_qualname;
    PYOBJECT_FIELD_TYPE func_doc;
    PYOBJECT_FIELD_TYPE func_globals;
    PYOBJECT_FIELD_TYPE func_code;
    PYOBJECT_FIELD_TYPE func_closure;
    // Dynamic default args and annotations
    void *defaults;
    int defaults_pyobjects;
    size_t defaults_size;  // used by FusedFunction for copying defaults
    int flags;

    // Defaults info
    PYOBJECT_FIELD_TYPE defaults_tuple;   /* Const defaults tuple */
    PYOBJECT_FIELD_TYPE defaults_kwdict;  /* Const kwonly defaults dict */
    PYOBJECT_FIELD_TYPE (*defaults_getter)(PYOBJECT_TYPE);
    PYOBJECT_FIELD_TYPE func_annotations; /* function annotations dict */

    // Coroutine marker
    PYOBJECT_FIELD_TYPE func_is_coroutine;
} __pyx_CyFunctionObject;

#if CYTHON_USING_HPY
HPyType_HELPERS(__pyx_CyFunctionObject)
#endif

#undef __Pyx_CyOrPyCFunction_Check
#define __Pyx_CyFunction_Check(obj) __Pyx_TypeCheck(obj, PYOBJECT_GLOBAL_LOAD(__pyx_CyFunctionType))
#define __Pyx_CyOrPyCFunction_Check(obj)  __Pyx_TypeCheck2(obj, __pyx_CyFunctionType, &PyCFunction_Type)
#if !CYTHON_USING_HPY
#define __Pyx_CyFunction_CheckExact(obj)  __Pyx_IS_TYPE(obj, __pyx_CyFunctionType)
#else
#define __Pyx_CyFunction_CheckExact(obj)  __Pyx_TypeCheck(obj, __pyx_CyFunctionType)
#endif
static CYTHON_INLINE int __Pyx__IsSameCyOrCFunction(HPY_CONTEXT_FIRST_ARG_DEF PYOBJECT_TYPE func, void *cfunc);/*proto*/
#undef __Pyx_IsSameCFunction
#define __Pyx_IsSameCFunction(func, cfunc)   __Pyx__IsSameCyOrCFunction(HPY_CONTEXT_FIRST_ARG_CALL func, cfunc)

static PYOBJECT_TYPE __Pyx_CyFunction_Init(HPY_CONTEXT_FIRST_ARG_DEF __pyx_CyFunctionObject_FuncDef op,
                                      PYMETHODDEF_TYPE *ml,
                                      int flags, PYOBJECT_TYPE qualname,
                                      PYOBJECT_TYPE closure,
                                      PYOBJECT_TYPE module, PYOBJECT_TYPE globals,
                                      PYOBJECT_TYPE code);

static CYTHON_INLINE void __Pyx__CyFunction_SetClassObj(HPY_CONTEXT_FIRST_ARG_DEF
                                                        __pyx_CyFunctionObject_FuncDef f,
                                                        PYOBJECT_TYPE classobj);
static CYTHON_INLINE void *__Pyx_CyFunction_InitDefaults(PyObject *m,
                                                         size_t size,
                                                         int pyobjects);
static CYTHON_INLINE void __Pyx_CyFunction_SetDefaultsTuple(HPY_CONTEXT_FIRST_ARG_DEF
                                                            PYOBJECT_TYPE m,
                                                            PYOBJECT_TYPE tuple);
static CYTHON_INLINE void __Pyx_CyFunction_SetDefaultsKwDict(HPY_CONTEXT_FIRST_ARG_DEF
                                                             PYOBJECT_TYPE m,
                                                             PYOBJECT_TYPE dict);
static CYTHON_INLINE void __Pyx_CyFunction_SetAnnotationsDict(HPY_CONTEXT_FIRST_ARG_DEF
                                                              PYOBJECT_TYPE m,
                                                              PYOBJECT_TYPE dict);


static int __pyx_CyFunction_init(HPY_CONTEXT_FIRST_ARG_DEF PYOBJECT_GLOBAL_TYPE module);

#if CYTHON_USING_HPY
HPyDef_CALL_FUNCTION(__Pyx_CyFunction_hpycall_NOARGS)
HPyDef_CALL_FUNCTION(__Pyx_CyFunction_hpycall_KEYWORDS)
#else /* CYTHON_USING_HPY */
#if CYTHON_METH_FASTCALL
static PyObject * __Pyx_CyFunction_Vectorcall_NOARGS(PyObject *func, PyObject *const *args, size_t nargsf, PyObject *kwnames);
static PyObject * __Pyx_CyFunction_Vectorcall_O(PyObject *func, PyObject *const *args, size_t nargsf, PyObject *kwnames);
static PyObject * __Pyx_CyFunction_Vectorcall_FASTCALL_KEYWORDS(PyObject *func, PyObject *const *args, size_t nargsf, PyObject *kwnames);
static PyObject * __Pyx_CyFunction_Vectorcall_FASTCALL_KEYWORDS_METHOD(PyObject *func, PyObject *const *args, size_t nargsf, PyObject *kwnames);
#endif /* CYTHON_USING_HPY */
#if CYTHON_BACKPORT_VECTORCALL
#define __Pyx_CyFunction_func_vectorcall(f) (((__pyx_CyFunctionObject*)f)->func_vectorcall)
#else
#define __Pyx_CyFunction_func_vectorcall(f) (((PyCFunctionObject*)f)->vectorcall)
#endif
#endif

//////////////////// CythonFunctionShared ////////////////////
//@substitute: naming
//@requires: CommonStructures.c::FetchCommonType
//@requires: ObjectHandling.c::PyMethodNew
//@requires: ObjectHandling.c::PyVectorcallFastCallDict
//@requires: ModuleSetupCode.c::IncludeStructmemberH
//@requires: ObjectHandling.c::PyObjectGetAttrStr

#if CYTHON_COMPILING_IN_LIMITED_API
static CYTHON_INLINE int __Pyx__IsSameCyOrCFunction(HPY_CONTEXT_FIRST_ARG_DEF PYOBJECT_TYPE func, void *cfunc) {
#if CYTHON_USING_HPY
    __pyx_CyFunctionObject *struct_func = __pyx_CyFunctionObject_AsStruct(HPY_CONTEXT_CNAME, func);
#else
    __pyx_CyFunctionObject *struct_func = (__pyx_CyFunctionObject*) func;
#endif
    if (__Pyx_CyFunction_Check(func)) {
        return PyCFunction_GetFunction(struct_func->func) == CAST_IF_CAPI(PyCFunction) cfunc; 
#if CYTHON_USING_HPY
    }
#else
    } else if (PyCFunction_Check(func)) {
        return PyCFunction_GetFunction(func) == (PyCFunction) cfunc;
    }
#endif
    return 0;
}
#else
static CYTHON_INLINE int __Pyx__IsSameCyOrCFunction(PyObject *func, void *cfunc) {
    return __Pyx_CyOrPyCFunction_Check(func) && __Pyx_CyOrPyCFunction_GET_FUNCTION(func) == (PyCFunction) cfunc;
}
#endif

static CYTHON_INLINE void __Pyx__CyFunction_SetClassObj(HPY_CONTEXT_FIRST_ARG_DEF __pyx_CyFunctionObject_FuncDef f, PYOBJECT_TYPE classobj) {
#if PY_VERSION_HEX < 0x030900B1 || (CYTHON_COMPILING_IN_LIMITED_API && !CYTHON_USING_HPY)
    __Pyx_Py_XDECREF_SET(
        __Pyx_CyFunction_GetClassObj(f),
            ((classobj) ? __Pyx_NewRef(classobj) : NULL));
#else
#if !CYTHON_USING_HPY  //Need to figure out how to port this behaviour in HPy
    __Pyx_Py_XDECREF_SET(
        // assigning to "mm_class", which is a "PyTypeObject*"
        ((PyCMethodObject *) (f))->mm_class,
        (PyTypeObject*)((classobj) ? __Pyx_NewRef(classobj) : NULL));
#endif
#endif
}

#if CYTHON_USING_HPY
HPyDef_GETSET(__Pyx_CyFunction_doc, "__doc__")
static HPy
__Pyx_CyFunction_doc_get(HPyContext *HPY_CONTEXT_CNAME, __pyx_CyFunctionObject_FuncDef op, void *closure)
{
    CYTHON_UNUSED_VAR(closure);
    __pyx_CyFunctionObject *struct_op = __pyx_CyFunctionObject_AsStruct(HPY_CONTEXT_CNAME, op);
    HPy h_doc;
    if (!HPyField_IsNull(struct_op->func_doc)) {
        h_doc = HPyField_Load(HPY_CONTEXT_CNAME, op, struct_op->func_doc);
    } else {
        h_doc = HPy_NULL;
    }
    if (HPy_IsNull(h_doc) && struct_op->func->meth.doc != NULL) {
        h_doc = HPyUnicode_FromString(HPY_CONTEXT_CNAME, struct_op->func->meth.doc);
    }
    if (HPy_IsNull(h_doc)) {
        return HPy_Dup(HPY_CONTEXT_CNAME, HPY_CONTEXT_CNAME->h_None);
    } else {
        HPyField_Store(HPY_CONTEXT_CNAME, op, &struct_op->func_doc, h_doc);
    }
    return h_doc;
}

static int
__Pyx_CyFunction_doc_set(HPyContext *HPY_CONTEXT_CNAME, __pyx_CyFunctionObject_FuncDef op, HPy value, void *context)
{
    CYTHON_UNUSED_VAR(context);
    if (HPy_IsNull(value)) {
        // Mark as deleted
        value = HPY_CONTEXT_CNAME->h_None;
    }
    __pyx_CyFunctionObject *struct_op = __pyx_CyFunctionObject_AsStruct(HPY_CONTEXT_CNAME, op);
    HPyField_Store(HPY_CONTEXT_CNAME, op, &struct_op->func_doc, value);
    return 0;
}
#endif /* CYTHON_USING_HPY */
static PYOBJECT_TYPE
__Pyx_CyFunction_get_doc(HPY_CONTEXT_FIRST_ARG_DEF __pyx_CyFunctionObject_FuncDef op, void *closure)
{
    CYTHON_UNUSED_VAR(closure);
#if !CYTHON_USING_HPY //currently no m_ml in the HPy version of op
    if (unlikely(op->func_doc == NULL)) {
#if CYTHON_COMPILING_IN_LIMITED_API
        op->func_doc = PyObject_GetAttrString(op->func, "__doc__");
        if (unlikely(!op->func_doc)) return NULL;
#else
        if (((PyCFunctionObject*)op)->m_ml->ml_doc) {
            op->func_doc = PyUnicode_FromString(((PyCFunctionObject*)op)->m_ml->ml_doc);
            if (unlikely(op->func_doc == NULL))
                return NULL;
        } else {
            Py_INCREF(Py_None);
            return Py_None;
        }
#endif   /* CYTHON_COMPILING_IN_LIMITED_API */
    }
    Py_INCREF(op->func_doc);
    return op->func_doc;
#else
    __pyx_CyFunctionObject *struct_op = __pyx_CyFunctionObject_AsStruct(HPY_CONTEXT_CNAME, op);
    return HPyField_Load(HPY_CONTEXT_CNAME, op, struct_op->func_doc);
#endif
}

static int
__Pyx_CyFunction_set_doc(HPY_CONTEXT_FIRST_ARG_DEF __pyx_CyFunctionObject_FuncDef op, PYOBJECT_TYPE value, void *context)
{
    CYTHON_UNUSED_VAR(context);
    if (API_IS_NULL(value)) {
        // Mark as deleted
        value = API_ASSIGN_NONE;
    }
#if !CYTHON_USING_HPY
    Py_INCREF(value);
    __Pyx_Py_XDECREF_SET(op->func_doc, value);
#else
    __pyx_CyFunctionObject *struct_op = __pyx_CyFunctionObject_AsStruct(HPY_CONTEXT_CNAME, op);
    PYOBJECT_FIELD_STORE(op, struct_op->func_doc, value);
#endif
    return 0;
}

static PYOBJECT_TYPE
__Pyx_CyFunction_get_name(HPY_CONTEXT_FIRST_ARG_DEF __pyx_CyFunctionObject_FuncDef op, void *context)
{
    CYTHON_UNUSED_VAR(context);
#if CYTHON_USING_HPY
    __pyx_CyFunctionObject *struct_op = __pyx_CyFunctionObject_AsStruct(HPY_CONTEXT_CNAME, op);
#else
    __pyx_CyFunctionObject *struct_op = op;
    if (unlikely(API_IS_NULL(struct_op->func_name))) {
#if CYTHON_COMPILING_IN_LIMITED_API
        op->func_name = PyObject_GetAttrString(op->func, "__name__");
#else
        op->func_name = PyUnicode_InternFromString(((PyCFunctionObject*)op)->m_ml->ml_name);
#endif  /* CYTHON_COMPILING_IN_LIMITED_API */
        if (unlikely(API_IS_NULL(struct_op->func_name)))
            return API_NULL_VALUE;
    }
    Py_INCREF(struct_op->func_name);
#endif
    return PYOBJECT_FIELD_LOAD(op, struct_op->func_name);
}

static int
__Pyx_CyFunction_set_name(HPY_CONTEXT_FIRST_ARG_DEF __pyx_CyFunctionObject_FuncDef op, PYOBJECT_TYPE value, void *context)
{
    CYTHON_UNUSED_VAR(context);
    if (unlikely(API_IS_NULL(value) || !PyUnicode_Check(HPY_LEGACY_OBJECT_AS(value)))) {
        PyErr_SetString(PyExc_TypeError,
                        "__name__ must be set to a string object");
        return -1;
    }
#if !CYTHON_USING_HPY
    Py_INCREF(value);
    __Pyx_Py_XDECREF_SET(op->func_name, value);
#else
    __pyx_CyFunctionObject *struct_op = __pyx_CyFunctionObject_AsStruct(HPY_CONTEXT_CNAME, op);
    PYOBJECT_FIELD_STORE(op, struct_op->func_name, value);
#endif
    return 0;
}

static PYOBJECT_TYPE
__Pyx_CyFunction_get_qualname(HPY_CONTEXT_FIRST_ARG_DEF __pyx_CyFunctionObject_FuncDef op, void *context)
{
    CYTHON_UNUSED_VAR(context);
#if !CYTHON_USING_HPY
    Py_INCREF(op->func_qualname);
    return op->func_qualname;
#else
    __pyx_CyFunctionObject *struct_op = __pyx_CyFunctionObject_AsStruct(HPY_CONTEXT_CNAME, op);
    return PYOBJECT_FIELD_LOAD(op, struct_op->func_qualname);
#endif
}

static int
__Pyx_CyFunction_set_qualname(HPY_CONTEXT_FIRST_ARG_DEF __pyx_CyFunctionObject_FuncDef op, PYOBJECT_TYPE value, void *context)
{
    CYTHON_UNUSED_VAR(context);
    if (unlikely(API_IS_NULL(value) || !UNICODE_CHECK(value))) {
        PyErr_SetString(PyExc_TypeError,
                        "__qualname__ must be set to a string object");
        return -1;
    }
#if !CYTHON_USING_HPY
    Py_INCREF(value);
    __Pyx_Py_XDECREF_SET(op->func_name, value);
#else
    __pyx_CyFunctionObject *struct_op = __pyx_CyFunctionObject_AsStruct(HPY_CONTEXT_CNAME, op);
    PYOBJECT_FIELD_STORE(op, struct_op->func_qualname, value);
#endif
    return 0;
}

static PYOBJECT_TYPE
__Pyx_CyFunction_get_dict(HPY_CONTEXT_FIRST_ARG_DEF __pyx_CyFunctionObject_FuncDef op, void *context)
{
#if CYTHON_USING_HPY
    __pyx_CyFunctionObject *struct_op = __pyx_CyFunctionObject_AsStruct(HPY_CONTEXT_CNAME, op);
#else
    __pyx_CyFunctionObject *struct_op = op;
#endif
    CYTHON_UNUSED_VAR(context);
    if (unlikely(API_IS_NULL(struct_op->func_dict))) {
        PYOBJECT_FIELD_STORE(op, struct_op->func_dict, DICT_NEW());
        if (unlikely(API_IS_NULL(struct_op->func_dict)))
            return API_NULL_VALUE;
    }
#if !CYTHON_USING_HPY
    Py_INCREF(struct_op->func_dict);
#endif
    return PYOBJECT_FIELD_LOAD(op, struct_op->func_dict);
}

static int
__Pyx_CyFunction_set_dict(HPY_CONTEXT_FIRST_ARG_DEF __pyx_CyFunctionObject_FuncDef op, PYOBJECT_TYPE value, void *context)
{
    CYTHON_UNUSED_VAR(context);
    if (unlikely(API_IS_NULL(value))) {
        PyErr_SetString(PyExc_TypeError,
               "function's dictionary may not be deleted");
        return -1;
    }
    if (unlikely(!DICT_CHECK(value))) {
        PyErr_SetString(PyExc_TypeError,
               "setting function's dictionary to a non-dict");
        return -1;
    }
#if !CYTHON_USING_HPY
    Py_INCREF(value);
    __Pyx_Py_XDECREF_SET(op->func_dict, value);
#else
    __pyx_CyFunctionObject *struct_op = __pyx_CyFunctionObject_AsStruct(HPY_CONTEXT_CNAME, op);
    PYOBJECT_FIELD_STORE(op, struct_op->func_dict, value);
#endif
    return 0;
}

static PYOBJECT_TYPE
__Pyx_CyFunction_get_globals(HPY_CONTEXT_FIRST_ARG_DEF __pyx_CyFunctionObject_FuncDef op, void *context)
{
    CYTHON_UNUSED_VAR(context);
#if !CYTHON_USING_HPY
    Py_INCREF(op->func_globals);
    return op->func_globals;
#else
    __pyx_CyFunctionObject *struct_op = __pyx_CyFunctionObject_AsStruct(HPY_CONTEXT_CNAME, op);
    return PYOBJECT_FIELD_LOAD(op, struct_op->func_globals);
#endif
}

static PYOBJECT_TYPE
__Pyx_CyFunction_get_closure(HPY_CONTEXT_FIRST_ARG_DEF __pyx_CyFunctionObject_FuncDef op, void *context)
{
    CYTHON_UNUSED_VAR(op);
    CYTHON_UNUSED_VAR(context);
#if !CYTHON_USING_HPY
    Py_INCREF(Py_None);
#endif
    return API_ASSIGN_NONE;
}

static PYOBJECT_TYPE
__Pyx_CyFunction_get_code(HPY_CONTEXT_FIRST_ARG_DEF __pyx_CyFunctionObject_FuncDef op, void *context)
{
#if CYTHON_USING_HPY
    __pyx_CyFunctionObject *struct_op = __pyx_CyFunctionObject_AsStruct(HPY_CONTEXT_CNAME, op);
#else
    __pyx_CyFunctionObject *struct_op = op;
#endif
    PYOBJECT_TYPE load_func_code_temp = PYOBJECT_FIELD_LOAD(op, struct_op->func_code);
    PYOBJECT_TYPE result = API_IS_NULL(load_func_code_temp) ? load_func_code_temp : API_ASSIGN_NONE;
    CYTHON_UNUSED_VAR(context);
    if (API_IS_NULL(load_func_code_temp)) {
        PYOBJECT_GLOBAL_CLOSEREF(load_func_code_temp);
    }
#if !CYTHON_USING_HPY
    Py_INCREF(result);
#endif
    return result;
}

static int
__Pyx_CyFunction_init_defaults(HPY_CONTEXT_FIRST_ARG_DEF __pyx_CyFunctionObject_FuncDef op) {
#if CYTHON_USING_HPY
    __pyx_CyFunctionObject *struct_op = __pyx_CyFunctionObject_AsStruct(HPY_CONTEXT_CNAME, op);
    PYOBJECT_TYPE res = PYOBJECT_FIELD_LOAD(op, struct_op->defaults_getter(op));
#else
    __pyx_CyFunctionObject *struct_op = op;
    PYOBJECT_TYPE res = struct_op->defaults_getter((PyObject *) op);
#endif
    int result = 0;
    if (unlikely(API_IS_NULL(res)))
        return -1;

    // Cache result
    #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS && !CYTHON_USING_HPY
    op->defaults_tuple = PyTuple_GET_ITEM(res, 0);
    Py_INCREF(op->defaults_tuple);
    op->defaults_kwdict = PyTuple_GET_ITEM(res, 1);
    Py_INCREF(op->defaults_kwdict);
    #else
    PYOBJECT_FIELD_STORE(op, struct_op->defaults_tuple, SEQUENCE_GET_ITEM(res, 0));
    PYOBJECT_TYPE load_default_tuple_temp = PYOBJECT_FIELD_LOAD(op, struct_op->defaults_tuple);
    if (unlikely(API_IS_NULL(load_default_tuple_temp))) result = -1;
    else {
        PYOBJECT_FIELD_STORE(op, struct_op->defaults_kwdict, SEQUENCE_GET_ITEM(res, 1));
        PYOBJECT_TYPE load_default_kwdict_temp = PYOBJECT_FIELD_LOAD(op, struct_op->defaults_kwdict);
        if (unlikely(API_IS_NULL(load_default_kwdict_temp))) result = -1;
    }
    PYOBJECT_GLOBAL_CLOSEREF(load_default_tuple_temp);
    #endif
    PYOBJECT_CLOSEREF(res);
    return result;
}

static int
__Pyx_CyFunction_set_defaults(HPY_CONTEXT_FIRST_ARG_DEF __pyx_CyFunctionObject_FuncDef op, PYOBJECT_TYPE value, void *context) {
    CYTHON_UNUSED_VAR(context);
    if (API_IS_NULL(value)) {
        // del => explicit None to prevent rebuilding
        value = API_ASSIGN_NONE;
    } else if (unlikely(API_IS_NOT_EQUAL(value, API_NONE_VALUE) && !TUPLE_CHECK(value))) {
        PyErr_SetString(PyExc_TypeError,
                        "__defaults__ must be set to a tuple object");
        return -1;
    }
    PyErr_WarnEx(PyExc_RuntimeWarning, "changes to cyfunction.__defaults__ will not "
                 "currently affect the values used in function calls", 1);
#if !CYTHON_USING_HPY
    Py_INCREF(value);
    __Pyx_Py_XDECREF_SET(op->defaults_tuple, value);
#else
    __pyx_CyFunctionObject *struct_op = __pyx_CyFunctionObject_AsStruct(HPY_CONTEXT_CNAME, op);
    PYOBJECT_FIELD_STORE(op, struct_op->defaults_tuple, value);
#endif
    return 0;
}

static PYOBJECT_TYPE
__Pyx_CyFunction_get_defaults(HPY_CONTEXT_FIRST_ARG_DEF __pyx_CyFunctionObject_FuncDef op, void *context) {
#if CYTHON_USING_HPY
    __pyx_CyFunctionObject *struct_op = __pyx_CyFunctionObject_AsStruct(HPY_CONTEXT_CNAME, op);
#else
    __pyx_CyFunctionObject *struct_op = op;
#endif
    PYOBJECT_TYPE result = PYOBJECT_FIELD_LOAD(op, struct_op->defaults_tuple);
    CYTHON_UNUSED_VAR(context);
    if (unlikely(API_IS_NULL(result))) {
        if (struct_op->defaults_getter) {
            if (unlikely(__Pyx_CyFunction_init_defaults(HPY_CONTEXT_FIRST_ARG_CALL op) < 0)) return API_NULL_VALUE; //First need to port init_defaults
            result = PYOBJECT_FIELD_LOAD(op, struct_op->defaults_tuple);
        } else
        {
            result = API_ASSIGN_NONE;
        }
    }
#if !CYTHON_USING_HPY
    Py_INCREF(result);
#endif
    return result;
}

static int
__Pyx_CyFunction_set_kwdefaults(HPY_CONTEXT_FIRST_ARG_DEF __pyx_CyFunctionObject_FuncDef op, PYOBJECT_TYPE value, void *context) {
    CYTHON_UNUSED_VAR(context);
    if (API_IS_NULL(value)) {
        // del => explicit None to prevent rebuilding
        value = API_ASSIGN_NONE;
    } else if (unlikely(API_IS_NOT_EQUAL(value, API_NONE_VALUE) && !DICT_CHECK(value))) {
        PyErr_SetString(PyExc_TypeError,
                        "__kwdefaults__ must be set to a dict object");
        return -1;
    }
    PyErr_WarnEx(PyExc_RuntimeWarning, "changes to cyfunction.__kwdefaults__ will not "
                 "currently affect the values used in function calls", 1);
#if !CYTHON_USING_HPY
    Py_INCREF(value);
    __Pyx_Py_XDECREF_SET(op->defaults_kwdict, value);
#else
    __pyx_CyFunctionObject *struct_op = __pyx_CyFunctionObject_AsStruct(HPY_CONTEXT_CNAME, op);
    PYOBJECT_FIELD_STORE(op, struct_op->defaults_kwdict, value);
#endif
    return 0;
}

static PYOBJECT_TYPE
__Pyx_CyFunction_get_kwdefaults(HPY_CONTEXT_FIRST_ARG_DEF __pyx_CyFunctionObject_FuncDef op, void *context) {
#if CYTHON_USING_HPY
    __pyx_CyFunctionObject *struct_op = __pyx_CyFunctionObject_AsStruct(HPY_CONTEXT_CNAME, op);
#else
    __pyx_CyFunctionObject *struct_op = op;
#endif
    PYOBJECT_TYPE result = PYOBJECT_FIELD_LOAD(op, struct_op->defaults_kwdict);
    CYTHON_UNUSED_VAR(context);
    if (unlikely(API_IS_NULL(result))) {
        if (struct_op->defaults_getter) {
            if (unlikely(__Pyx_CyFunction_init_defaults(HPY_CONTEXT_FIRST_ARG_CALL op) < 0)) return API_NULL_VALUE;
            result = PYOBJECT_FIELD_LOAD(op, struct_op->defaults_kwdict);
        } else
        {
            result = API_ASSIGN_NONE;
        }
    }
#if !CYTHON_USING_HPY
    Py_INCREF(result);
#endif
    return result;
}

static int
__Pyx_CyFunction_set_annotations(HPY_CONTEXT_FIRST_ARG_DEF __pyx_CyFunctionObject_FuncDef op, PYOBJECT_TYPE value, void *context) {
    CYTHON_UNUSED_VAR(context);
    if (API_IS_NULL(value) || API_IS_EQUAL(value, API_NONE_VALUE)) {
        value = API_NULL_VALUE;
    } else if (unlikely(!DICT_CHECK(value))) {
        PyErr_SetString(PyExc_TypeError,
                        "__annotations__ must be set to a dict object");
        return -1;
    }
#if !CYTHON_USING_HPY
    Py_XINCREF(value);
    __Pyx_Py_XDECREF_SET(op->func_annotations, value);
#else
    __pyx_CyFunctionObject *struct_op = __pyx_CyFunctionObject_AsStruct(HPY_CONTEXT_CNAME, op);
    PYOBJECT_FIELD_STORE(op, struct_op->func_annotations, value);
#endif
    return 0;
}

static PYOBJECT_TYPE
__Pyx_CyFunction_get_annotations(HPY_CONTEXT_FIRST_ARG_DEF __pyx_CyFunctionObject_FuncDef op, void *context) {
#if CYTHON_USING_HPY
    __pyx_CyFunctionObject *struct_op = __pyx_CyFunctionObject_AsStruct(HPY_CONTEXT_CNAME, op);
#else
    __pyx_CyFunctionObject *struct_op = op;
#endif
    PYOBJECT_TYPE result = PYOBJECT_FIELD_LOAD(op, struct_op->func_annotations);
    CYTHON_UNUSED_VAR(context);
    if (unlikely(API_IS_NULL(result))) {
        result = DICT_NEW();
        if (unlikely(API_IS_NULL(result))) return API_NULL_VALUE;
        PYOBJECT_FIELD_STORE(op, struct_op->func_annotations, result);
    }
#if !CYTHON_USING_HPY
    Py_INCREF(result);
#endif
    return result;
}

static PYOBJECT_TYPE
__Pyx_CyFunction_get_is_coroutine(HPY_CONTEXT_FIRST_ARG_DEF __pyx_CyFunctionObject_FuncDef op, void *context) {
#if CYTHON_USING_HPY
    __pyx_CyFunctionObject *struct_op = __pyx_CyFunctionObject_AsStruct(HPY_CONTEXT_CNAME, op);
#else
    __pyx_CyFunctionObject *struct_op = op;
#endif
    int is_coroutine;
    CYTHON_UNUSED_VAR(context);
    PYOBJECT_TYPE load_is_coroutine_temp = PYOBJECT_FIELD_LOAD(op, struct_op->func_is_coroutine);
    if (API_IS_NULL(load_is_coroutine_temp)) {
        return __Pyx_hNewRef(load_is_coroutine_temp);
    }

    is_coroutine = struct_op->flags & __Pyx_CYFUNCTION_COROUTINE;
    if (is_coroutine) {
        PYOBJECT_TYPE load_marker_temp = PYOBJECT_GLOBAL_LOAD(PYIDENT("_is_coroutine"));
        PYOBJECT_TYPE module;
        PYOBJECT_TYPE fromlist;
        LIST_BUILDER_TYPE fromlist_builder;
        PYOBJECT_TYPE marker = load_marker_temp;
        PYOBJECT_GLOBAL_CLOSEREF(load_marker_temp);
        LIST_CREATE_START(fromlist, fromlist_builder, 1);
#if !CYTHON_USING_HPY
        if (unlikely(!fromlist)) return API_NULL_VALUE;
        Py_INCREF(marker);
#if CYTHON_ASSUME_SAFE_MACROS
        PyList_SET_ITEM(fromlist, 0, marker);
#else
        if (unlikely(PyList_SetItem(fromlist, 0, marker) < 0)) {
            Py_DECREF(marker);
            Py_DECREF(fromlist);
            return API_NULL_VALUE;
        }
#endif
#else
        LIST_CREATE_ASSIGN(fromlist, fromlist_builder, 0, marker);
#endif
        LIST_CREATE_FINALISE(fromlist, fromlist_builder);
        PYOBJECT_TYPE load_asyncio_temp = PYOBJECT_GLOBAL_LOAD(PYIDENT("asyncio.coroutines"));
        module = HPY_LEGACY_OBJECT_FROM(PyImport_ImportModuleLevelObject(HPY_LEGACY_OBJECT_AS(load_asyncio_temp), NULL, NULL, HPY_LEGACY_OBJECT_AS(fromlist), 0));
        PYOBJECT_GLOBAL_CLOSEREF(load_asyncio_temp);
        PYOBJECT_CLOSEREF(fromlist);
        if (unlikely(API_IS_NULL(module))) goto ignore;
        PYOBJECT_FIELD_STORE(op, struct_op->func_is_coroutine, __Pyx_PyObject_GetAttrStr(module, marker));
        PYOBJECT_CLOSEREF(module);
        if (likely(API_IS_NOT_NULL(load_is_coroutine_temp))) {
#if CYTHON_USING_HPY
            return load_is_coroutine_temp;
#else
            __Pyx_NewRef(load_is_coroutine_temp);
#endif
        }
ignore:
        PyErr_Clear();
    }

    PYOBJECT_FIELD_STORE(op, struct_op->func_is_coroutine, __Pyx_PyBool_FromLong(HPY_CONTEXT_FIRST_ARG_CALL is_coroutine));
#if CYTHON_USING_HPY
    return PYOBJECT_FIELD_LOAD(op, struct_op->func_is_coroutine);
#else
    __Pyx_NewRef(struct_op->func_is_coroutine);
#endif
}

//static PyObject *
//__Pyx_CyFunction_get_signature(__pyx_CyFunctionObject *op, void *context) {
//    PyObject *inspect_module, *signature_class, *signature;
//    CYTHON_UNUSED_VAR(context);
//    // from inspect import Signature
//    inspect_module = PyImport_ImportModuleLevelObject(PYIDENT("inspect"), NULL, NULL, NULL, 0);
//    if (unlikely(!inspect_module))
//        goto bad;
//    signature_class = __Pyx_PyObject_GetAttrStr(inspect_module, PYIDENT("Signature"));
//    Py_DECREF(inspect_module);
//    if (unlikely(!signature_class))
//        goto bad;
//    // return Signature.from_function(op)
//    signature = PyObject_CallMethodObjArgs(signature_class, PYIDENT("from_function"), op, NULL);
//    Py_DECREF(signature_class);
//    if (likely(signature))
//        return signature;
//bad:
//    // make sure we raise an AttributeError from this property on any errors
//    if (!PyErr_ExceptionMatches(PyExc_AttributeError))
//        PyErr_SetString(PyExc_AttributeError, "failed to calculate __signature__");
//    return NULL;
//}

#if CYTHON_COMPILING_IN_LIMITED_API
static PyObject *
__Pyx_CyFunction_get_module(__pyx_CyFunctionObject *op, void *context) {
    CYTHON_UNUSED_VAR(context);
    return PyObject_GetAttrString(op->func, "__module__");
}

static int
__Pyx_CyFunction_set_module(__pyx_CyFunctionObject *op, PyObject* value, void *context) {
    CYTHON_UNUSED_VAR(context);
    return PyObject_SetAttrString(op->func, "__module__", value);
}
#endif

static PyGetSetDef __pyx_CyFunction_getsets[] = {
    {"func_doc", (getter)__Pyx_CyFunction_get_doc, (setter)__Pyx_CyFunction_set_doc, 0, 0},
    {"__doc__",  (getter)__Pyx_CyFunction_get_doc, (setter)__Pyx_CyFunction_set_doc, 0, 0},
    {"func_name", (getter)__Pyx_CyFunction_get_name, (setter)__Pyx_CyFunction_set_name, 0, 0},
    {"__name__", (getter)__Pyx_CyFunction_get_name, (setter)__Pyx_CyFunction_set_name, 0, 0},
    {"__qualname__", (getter)__Pyx_CyFunction_get_qualname, (setter)__Pyx_CyFunction_set_qualname, 0, 0},
    {"func_dict", (getter)__Pyx_CyFunction_get_dict, (setter)__Pyx_CyFunction_set_dict, 0, 0},
    {"__dict__", (getter)__Pyx_CyFunction_get_dict, (setter)__Pyx_CyFunction_set_dict, 0, 0},
    {"func_globals", (getter)__Pyx_CyFunction_get_globals, 0, 0, 0},
    {"__globals__", (getter)__Pyx_CyFunction_get_globals, 0, 0, 0},
    {"func_closure", (getter)__Pyx_CyFunction_get_closure, 0, 0, 0},
    {"__closure__", (getter)__Pyx_CyFunction_get_closure, 0, 0, 0},
    {"func_code", (getter)__Pyx_CyFunction_get_code, 0, 0, 0},
    {"__code__", (getter)__Pyx_CyFunction_get_code, 0, 0, 0},
    {"func_defaults", (getter)__Pyx_CyFunction_get_defaults, (setter)__Pyx_CyFunction_set_defaults, 0, 0},
    {"__defaults__", (getter)__Pyx_CyFunction_get_defaults, (setter)__Pyx_CyFunction_set_defaults, 0, 0},
    {"__kwdefaults__", (getter)__Pyx_CyFunction_get_kwdefaults, (setter)__Pyx_CyFunction_set_kwdefaults, 0, 0},
    {"__annotations__", (getter)__Pyx_CyFunction_get_annotations, (setter)__Pyx_CyFunction_set_annotations, 0, 0},
    {"_is_coroutine", (getter)__Pyx_CyFunction_get_is_coroutine, 0, 0, 0},
//    {"__signature__", (getter)__Pyx_CyFunction_get_signature, 0, 0, 0},
#if CYTHON_COMPILING_IN_LIMITED_API
    {"__module__", (getter)__Pyx_CyFunction_get_module, (setter)__Pyx_CyFunction_set_module, 0, 0},
#endif
    {0, 0, 0, 0, 0}
};

#if CYTHON_USING_HPY
HPyDef_MEMBER(__pyx_CyFunction_member_module, "__module__", HPyMember_OBJECT, offsetof(__pyx_CyFunctionObject, func_module))
HPyDef_MEMBER(__pyx_CyFunction_member_dictoffset, "__dictoffset__", HPyMember_HPYSSIZET, offsetof(__pyx_CyFunctionObject, func_dict), .readonly=1)
#else /* CYTHON_USING_HPY */
static PyMemberDef __pyx_CyFunction_members[] = {
#if !CYTHON_COMPILING_IN_LIMITED_API
    {"__module__", T_OBJECT, offsetof(PyCFunctionObject, m_module), 0, 0},
#endif
#if CYTHON_USE_TYPE_SPECS
    {"__dictoffset__", T_PYSSIZET, offsetof(__pyx_CyFunctionObject, func_dict), READONLY, 0},
#if CYTHON_METH_FASTCALL
#if CYTHON_BACKPORT_VECTORCALL
    {"__vectorcalloffset__", T_PYSSIZET, offsetof(__pyx_CyFunctionObject, func_vectorcall), READONLY, 0},
#else
#if !CYTHON_COMPILING_IN_LIMITED_API
    {"__vectorcalloffset__", T_PYSSIZET, offsetof(PyCFunctionObject, vectorcall), READONLY, 0},
#endif
#endif
#endif
#if CYTHON_COMPILING_IN_LIMITED_API
    {"__weaklistoffset__", T_PYSSIZET, offsetof(__pyx_CyFunctionObject, func_weakreflist), READONLY, 0},
#else
    {"__weaklistoffset__", T_PYSSIZET, offsetof(PyCFunctionObject, m_weakreflist), READONLY, 0},
#endif
#endif
    {0, 0, 0,  0, 0}
};
#endif /* CYTHON_USING_HPY */

#if CYTHON_USING_HPY
HPyDef_METH(__Pyx_CyFunction_reduce, "__reduce__", HPyFunc_VARARGS)
static HPy
__Pyx_CyFunction_reduce_impl(HPyContext *HPY_CONTEXT_CNAME, HPy self, const HPy *args, size_t nargs)
{
    CYTHON_UNUSED_VAR(args);
    CYTHON_UNUSED_VAR(nargs);
    __pyx_CyFunctionObject *struct_self = __pyx_CyFunctionObject_AsStruct(HPY_CONTEXT_CNAME, self);
    return PYOBJECT_FIELD_LOAD(self, struct_self->func_qualname);
}
#else /* CYTHON_USING_HPY */
static PYOBJECT_TYPE
__Pyx_CyFunction_reduce(__pyx_CyFunctionObject_FuncDef m, PyObject *args)
{
    CYTHON_UNUSED_VAR(args);
#if CYTHON_USING_HPY
    __pyx_CyFunctionObject *struct_m = __pyx_CyFunctionObject_AsStruct(HPY_CONTEXT_CNAME, m);
    return PYOBJECT_FIELD_LOAD(m, struct_m->func_qualname);
#else
    Py_INCREF(m->func_qualname);
    return m->func_qualname;
#endif
}

static PyMethodDef __pyx_CyFunction_methods[] = {
    {"__reduce__", (PyCFunction)__Pyx_CyFunction_reduce, METH_VARARGS, 0},
    {0, 0, 0, 0}
};
#endif /* CYTHON_USING_HPY */


#if CYTHON_COMPILING_IN_LIMITED_API
#define __Pyx_CyFunction_weakreflist(cyfunc) ((cyfunc)->func_weakreflist)
#else
#define __Pyx_CyFunction_weakreflist(cyfunc) (((PyCFunctionObject*)cyfunc)->m_weakreflist)
#endif

static PYOBJECT_TYPE __Pyx_CyFunction_Init(HPY_CONTEXT_FIRST_ARG_DEF __pyx_CyFunctionObject_FuncDef op, PYMETHODDEF_TYPE *ml, int flags, PYOBJECT_TYPE qualname,
                                       PYOBJECT_TYPE closure, PYOBJECT_TYPE module, PYOBJECT_TYPE globals, PYOBJECT_TYPE code) {
#if !CYTHON_USING_HPY
#if !CYTHON_COMPILING_IN_LIMITED_API
    PyCFunctionObject *cf = (PyCFunctionObject*) op;
#endif
    if (unlikely(op == NULL))
        return NULL;
#if CYTHON_COMPILING_IN_LIMITED_API
    // Note that we end up with a circular reference to op. This isn't
    // a disaster, but in an ideal world it'd be nice to avoid it.
    op->func = PyCFunction_NewEx(ml, (PyObject*)op, module);
    if (unlikely(!op->func)) return NULL;
#endif
    op->flags = flags;
    __Pyx_CyFunction_weakreflist(op) = NULL;
    __pyx_CyFunctionObject *struct_op = op;
    Py_XINCREF(closure);
    op->func_closure = closure;
#if !CYTHON_COMPILING_IN_LIMITED_API
    cf->m_ml = ml;
    cf->m_self = (PyObject *) op;
    Py_XINCREF(module);
    cf->m_module = module;
#endif
    __Pyx_CyFunction_weakreflist(op) = NULL;
    Py_XINCREF(closure);
    Py_INCREF(qualname);
    op->func_qualname = qualname;
    op->func_doc = NULL;
#if PY_VERSION_HEX < 0x030900B1 || (CYTHON_COMPILING_IN_LIMITED_API && !CYTHON_USING_HPY)
    op->func_classobj = NULL;
#else
    ((PyCMethodObject*)op)->mm_class = NULL;
#endif
    Py_XINCREF(code);
#else /* !CYTHON_USING_HPY */
    __pyx_CyFunctionObject *struct_op = __pyx_CyFunctionObject_AsStruct(HPY_CONTEXT_CNAME, op);
    assert(ml->kind == HPyDef_Kind_Meth);
    struct_op->func = ml;
    PYOBJECT_FIELD_STORE(op, struct_op->func_qualname, qualname);
    if (ml->meth.doc != NULL) {
        PYOBJECT_FIELD_STORE(op, struct_op->func_doc, HPyUnicode_FromString(HPY_CONTEXT_CNAME, ml->meth.doc));
    } else {
        struct_op->func_doc = HPyField_NULL;
    }
#endif /* !CYTHON_USING_HPY */
    if (unlikely(API_IS_NULL(op)))
        return API_NULL_VALUE;
    struct_op->flags = flags;
    PYOBJECT_FIELD_STORE(op, struct_op->func_self, (PYOBJECT_TYPE) op);
    PYOBJECT_FIELD_STORE(op, struct_op->func_module, module);
    PYOBJECT_FIELD_STORE(op, struct_op->func_closure, closure);
    PYOBJECT_FIELD_STORE(op, struct_op->func_dict, API_NULL_VALUE);
    PYOBJECT_FIELD_STORE(op, struct_op->func_name, API_NULL_VALUE);
    PYOBJECT_FIELD_STORE(op, struct_op->func_globals, globals);
    PYOBJECT_FIELD_STORE(op, struct_op->func_code,code);
    // Dynamic Default args
    struct_op->defaults_pyobjects = 0;
    struct_op->defaults_size = 0;
    struct_op->defaults = NULL;
    PYOBJECT_FIELD_STORE(op, struct_op->defaults_tuple, API_NULL_VALUE );
    PYOBJECT_FIELD_STORE(op, struct_op->defaults_kwdict, API_NULL_VALUE );
#if !CYTHON_USING_HPY
    PYOBJECT_FIELD_STORE(op, struct_op->defaults_getter, API_NULL_VALUE );
#endif
    PYOBJECT_FIELD_STORE(op, struct_op->func_annotations, API_NULL_VALUE );
    PYOBJECT_FIELD_STORE(op, struct_op->func_is_coroutine, API_NULL_VALUE );
#if CYTHON_USING_HPY
    switch (ml->meth.signature) {
    case HPyFunc_NOARGS:
        HPy_SetCallFunction(HPY_CONTEXT_CNAME, op, &__Pyx_CyFunction_hpycall_NOARGS);
        break;
    case HPyFunc_KEYWORDS:
        HPy_SetCallFunction(HPY_CONTEXT_CNAME, op, &__Pyx_CyFunction_hpycall_KEYWORDS);
        break;
    default:
        HPyErr_SetString(HPY_CONTEXT_CNAME, API_EXC(TypeError), "unknown signature");
        return HPy_NULL;
    }
    return op;

#else /* CYTHON_USING_HPY */
    Py_INCREF(op->func_globals);
#if CYTHON_METH_FASTCALL
    switch (ml->ml_flags & (METH_VARARGS | METH_FASTCALL | METH_NOARGS | METH_O | METH_KEYWORDS | METH_METHOD)) {
    case METH_NOARGS:
        __Pyx_CyFunction_func_vectorcall(op) = __Pyx_CyFunction_Vectorcall_NOARGS;
        break;
    case METH_O:
        __Pyx_CyFunction_func_vectorcall(op) = __Pyx_CyFunction_Vectorcall_O;
        break;
    // case METH_FASTCALL is not used
    case METH_METHOD | METH_FASTCALL | METH_KEYWORDS:
        __Pyx_CyFunction_func_vectorcall(op) = __Pyx_CyFunction_Vectorcall_FASTCALL_KEYWORDS_METHOD;
        break;
    case METH_FASTCALL | METH_KEYWORDS:
        __Pyx_CyFunction_func_vectorcall(op) = __Pyx_CyFunction_Vectorcall_FASTCALL_KEYWORDS;
        break;
    // case METH_VARARGS is not used
    case METH_VARARGS | METH_KEYWORDS:
        __Pyx_CyFunction_func_vectorcall(op) = NULL;
        break;
    default:
        PyErr_SetString(PyExc_SystemError, "Bad call flags for CyFunction");
        Py_DECREF(op);
        return NULL;
    }
#endif
    return (PyObject *) op;
#endif
}

#if !CYTHON_USING_HPY
static int
__Pyx_CyFunction_clear(__pyx_CyFunctionObject *m)
{
    Py_CLEAR(m->func_closure);
#if CYTHON_COMPILING_IN_LIMITED_API
    Py_CLEAR(m->func);
#else
    Py_CLEAR(((PyCFunctionObject*)m)->m_module);
#endif
    Py_CLEAR(m->func_dict);
    Py_CLEAR(m->func_name);
    Py_CLEAR(m->func_qualname);
    Py_CLEAR(m->func_doc);
    Py_CLEAR(m->func_globals);
    Py_CLEAR(m->func_code);
#if !CYTHON_COMPILING_IN_LIMITED_API
#if PY_VERSION_HEX < 0x030900B1
    Py_CLEAR(__Pyx_CyFunction_GetClassObj(m));
#else
    {
        PyObject *cls = (PyObject*) ((PyCMethodObject *) (m))->mm_class;
        ((PyCMethodObject *) (m))->mm_class = NULL;
        Py_XDECREF(cls);
    }
#endif
#endif
    Py_CLEAR(m->defaults_tuple);
    Py_CLEAR(m->defaults_kwdict);
    Py_CLEAR(m->func_annotations);
    Py_CLEAR(m->func_is_coroutine);

    if (m->defaults) {
        PyObject **pydefaults = __Pyx_CyFunction_Defaults(PyObject *, m);
        int i;

        for (i = 0; i < m->defaults_pyobjects; i++)
            Py_XDECREF(pydefaults[i]);

        PyObject_Free(m->defaults);
        m->defaults = NULL;
    }

    return 0;
}

static void __Pyx__CyFunction_dealloc(__pyx_CyFunctionObject *m)
{
    if (__Pyx_CyFunction_weakreflist(m) != NULL)
        PyObject_ClearWeakRefs((PyObject *) m);
    __Pyx_CyFunction_clear(m);
    __Pyx_PyHeapTypeObject_GC_Del(m);
}

static void __Pyx_CyFunction_dealloc(__pyx_CyFunctionObject *m)
{
    PyObject_GC_UnTrack(m);
    __Pyx__CyFunction_dealloc(m);
}

#else /* !CYTHON_USING_HPY */

HPyDef_SLOT(__Pyx_CyFunction_destroy, HPy_tp_destroy)
static void __Pyx_CyFunction_destroy_impl(void *ptr)
{
    __pyx_CyFunctionObject *m = (__pyx_CyFunctionObject *) ptr;
    // TODO(fa): I think only freeing defaults is left
}

#endif /* !CYTHON_USING_HPY */

#if !CYTHON_USING_HPY
static int __Pyx_CyFunction_traverse(__pyx_CyFunctionObject *m, visitproc visit, void *arg)
{
    Py_VISIT(m->func_closure);
#if CYTHON_COMPILING_IN_LIMITED_API
    Py_VISIT(m->func);
#else
    Py_VISIT(((PyCFunctionObject*)m)->m_module);
#endif
    Py_VISIT(m->func_dict);
    Py_VISIT(m->func_name);
    Py_VISIT(m->func_qualname);
    Py_VISIT(m->func_doc);
    Py_VISIT(m->func_globals);
    Py_VISIT(m->func_code);
#if !CYTHON_COMPILING_IN_LIMITED_API
    Py_VISIT(__Pyx_CyFunction_GetClassObj(m));
#endif
    Py_VISIT(m->defaults_tuple);
    Py_VISIT(m->defaults_kwdict);
    Py_VISIT(m->func_is_coroutine);

    if (m->defaults) {
        PyObject **pydefaults = __Pyx_CyFunction_Defaults(PyObject *, m);
        int i;

        for (i = 0; i < m->defaults_pyobjects; i++)
            Py_VISIT(pydefaults[i]);
    }

    return 0;
}
#else
HPyDef_SLOT(__Pyx_CyFunction_traverse, HPy_tp_traverse)
static int __Pyx_CyFunction_traverse_impl(void *m, HPyFunc_visitproc visit, void *arg)
{
    __pyx_CyFunctionObject *f = (__pyx_CyFunctionObject *) m;
    HPy_VISIT(&f->func_module);
    HPy_VISIT(&f->func_dict);
    HPy_VISIT(&f->func_closure);
    HPy_VISIT(&f->func_name);
    HPy_VISIT(&f->func_qualname);
    HPy_VISIT(&f->func_doc);
    HPy_VISIT(&f->func_globals);
    HPy_VISIT(&f->func_code);
    HPy_VISIT(&f->defaults_tuple);
    HPy_VISIT(&f->defaults_kwdict);
    HPy_VISIT(&f->func_is_coroutine);

// Need to port init_defaults first
//    if (m->defaults) {
//        PyObject **pydefaults = __Pyx_CyFunction_Defaults(PyObject *, m);
//        int i;
//
//        for (i = 0; i < m->defaults_pyobjects; i++)
//            Py_VISIT(pydefaults[i]);
//    }

    return 0;
}
#endif

#if CYTHON_USING_HPY
HPyDef_SLOT(__Pyx_CyFunction_repr, HPy_tp_repr)
static HPy
__Pyx_CyFunction_repr_impl(HPyContext *HPY_CONTEXT_CNAME, HPy op)
{
    __pyx_CyFunctionObject *struct_op = __pyx_CyFunctionObject_AsStruct(HPY_CONTEXT_CNAME, op);
    HPy qualname_field = HPyField_Load(HPY_CONTEXT_CNAME, op, struct_op->func_qualname);
    HPy result = HPyUnicode_FromFormat(HPY_CONTEXT_CNAME, "<cyfunction %U at %p>", qualname_field, struct_op);
    HPy_Close(HPY_CONTEXT_CNAME, qualname_field);
    return result;
}

#else /* CYTHON_USING_HPY  */
static PYOBJECT_TYPE
__Pyx_CyFunction_repr_impl(HPY_CONTEXT_FIRST_ARG_DEF __pyx_CyFunctionObject_FuncDef op)
{
    __pyx_CyFunctionObject *struct_op = op;
    PyObject *qualname_field = struct_op->func_qualname;
    return PYOBJECT_UNICODE_FROM_FORMAT("<cyfunction %U at %R>",
                                qualname_field, op);
}
#endif /* CYTHON_USING_HPY  */

#if !CYTHON_USING_HPY
static PyObject * __Pyx_CyFunction_CallMethod(HPY_CONTEXT_FIRST_ARG_DEF PyObject *func, PyObject *self, PyObject *arg, PyObject *kw) {
    // originally copied from PyCFunction_Call() in CPython's Objects/methodobject.c
#if CYTHON_COMPILING_IN_LIMITED_API
    PyObject *f = ((__pyx_CyFunctionObject*)func)->func;
    PyObject *py_name = NULL;
    PyCFunction meth;
    int flags;
    meth = PyCFunction_GetFunction(f);
    if (unlikely(!meth)) return NULL;
    flags = PyCFunction_GetFlags(f);
    if (unlikely(flags < 0)) return NULL;
#else
    PyCFunctionObject* f = (PyCFunctionObject*)func;
    PyCFunction meth = f->m_ml->ml_meth;
    int flags = f->m_ml->ml_flags;
#endif

    Py_ssize_t size;

    switch (flags & (METH_VARARGS | METH_KEYWORDS | METH_NOARGS | METH_O)) {
    case METH_VARARGS:
        if (likely(kw == NULL || PyDict_Size(kw) == 0))
            return (*meth)(self, arg);
        break;
    case METH_VARARGS | METH_KEYWORDS:
        return (*(PyCFunctionWithKeywords)(void*)meth)(self, arg, kw);
    case METH_NOARGS:
        if (likely(kw == NULL || PyDict_Size(kw) == 0)) {
#if CYTHON_ASSUME_SAFE_MACROS
            size = PyTuple_GET_SIZE(arg);
#else
            size = PyTuple_Size(arg);
            if (unlikely(size < 0)) return NULL;
#endif
            if (likely(size == 0))
                return (*meth)(self, NULL);
#if CYTHON_COMPILING_IN_LIMITED_API
            py_name = __Pyx_CyFunction_get_name((__pyx_CyFunctionObject*)func, NULL);
            if (!py_name) return NULL;
            PyErr_Format(PyExc_TypeError,
                "%.200S() takes no arguments (%" CYTHON_FORMAT_SSIZE_T "d given)",
                py_name, size);
            Py_DECREF(py_name);
#else
            PyErr_Format(PyExc_TypeError,
                "%.200s() takes no arguments (%" CYTHON_FORMAT_SSIZE_T "d given)",
                f->m_ml->ml_name, size);
#endif
            return NULL;
        }
        break;
    case METH_O:
        if (likely(kw == NULL || PyDict_Size(kw) == 0)) {
#if CYTHON_ASSUME_SAFE_MACROS
            size = PyTuple_GET_SIZE(arg);
#else
            size = PyTuple_Size(arg);
            if (unlikely(size < 0)) return NULL;
#endif
            if (likely(size == 1)) {
                PyObject *result, *arg0;
                #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
                arg0 = PyTuple_GET_ITEM(arg, 0);
                #else
                arg0 = __Pyx_PySequence_ITEM(arg, 0); if (unlikely(!arg0)) return NULL;
                #endif
                result = (*meth)(self, arg0);
                #if !(CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS)
                Py_DECREF(arg0);
                #endif
                return result;
            }
#if CYTHON_COMPILING_IN_LIMITED_API
            py_name = __Pyx_CyFunction_get_name((__pyx_CyFunctionObject*)func, NULL);
            if (!py_name) return NULL;
            PyErr_Format(PyExc_TypeError,
                "%.200S() takes exactly one argument (%" CYTHON_FORMAT_SSIZE_T "d given)",
                py_name, size);
            Py_DECREF(py_name);
#else
            PyErr_Format(PyExc_TypeError,
                "%.200s() takes exactly one argument (%" CYTHON_FORMAT_SSIZE_T "d given)",
                f->m_ml->ml_name, size);
#endif

            return NULL;
        }
        break;
    default:
        PyErr_SetString(PyExc_SystemError, "Bad call flags for CyFunction");
        return NULL;
    }
#if CYTHON_COMPILING_IN_LIMITED_API
    py_name = __Pyx_CyFunction_get_name((__pyx_CyFunctionObject*)func, NULL);
    if (!py_name) return NULL;
    PyErr_Format(PyExc_TypeError, "%.200S() takes no keyword arguments",
                 py_name);
    Py_DECREF(py_name);
#else
    PyErr_Format(PyExc_TypeError, "%.200s() takes no keyword arguments",
                 f->m_ml->ml_name);
#endif
    return NULL;
}

static CYTHON_INLINE PyObject *__Pyx_CyFunction_Call(HPY_CONTEXT_FIRST_ARG_DEF PyObject *func, PyObject *arg, PyObject *kw) {
    PyObject *self, *result;
#if CYTHON_COMPILING_IN_LIMITED_API
    // PyCFunction_GetSelf returns a borrowed reference
    self = PyCFunction_GetSelf(((__pyx_CyFunctionObject*)func)->HPY_CONTEXT_FIRST_ARG_CALL func);
    if (unlikely(!self) && PyErr_Occurred()) return NULL;
#else
    self = ((PyCFunctionObject*)func)->m_self;
#endif
    result = __Pyx_CyFunction_CallMethod(func, self, arg, kw);
    return result;
}

static PYOBJECT_TYPE __Pyx_CyFunction_CallAsMethod(HPY_CONTEXT_FIRST_ARG_DEF PYOBJECT_TYPE func, PYOBJECT_TYPE args, PYOBJECT_TYPE kw) {
    PyObject *result;
    __pyx_CyFunctionObject *cyfunc = (__pyx_CyFunctionObject *) func;

#if CYTHON_METH_FASTCALL
    // Prefer vectorcall if available. This is not the typical case, as
    // CPython would normally use vectorcall directly instead of tp_call.
     __pyx_vectorcallfunc vc = __Pyx_CyFunction_func_vectorcall(cyfunc);
    if (vc) {
#if CYTHON_ASSUME_SAFE_MACROS
        return __Pyx_PyVectorcall_FastCallDict(func, vc, &PyTuple_GET_ITEM(args, 0), (size_t)PyTuple_GET_SIZE(args), kw);
#else
        // avoid unused function warning
        (void) &__Pyx_PyVectorcall_FastCallDict;
        return PyVectorcall_Call(func, args, kw);
#endif
    }
#endif

    if ((cyfunc->flags & __Pyx_CYFUNCTION_CCLASS) && !(cyfunc->flags & __Pyx_CYFUNCTION_STATICMETHOD)) {
        Py_ssize_t argc;
        PyObject *new_args;
        PyObject *self;

#if CYTHON_ASSUME_SAFE_MACROS
        argc = PyTuple_GET_SIZE(args);
#else
        argc = PyTuple_Size(args);
        if (unlikely(!argc) < 0) return NULL;
#endif
        new_args = PyTuple_GetSlice(args, 1, argc);

        if (unlikely(!new_args))
            return NULL;

        self = PyTuple_GetItem(args, 0);
        if (unlikely(!self)) {
            Py_DECREF(new_args);
            PyErr_Format(PyExc_TypeError,
                         "unbound method %.200S() needs an argument",
                         cyfunc->func_qualname);
            return NULL;
        }

        result = __Pyx_CyFunction_CallMethod(HPY_CONTEXT_FIRST_ARG_CALL func, self, new_args, kw);
        Py_DECREF(new_args);
    } else {
        result = __Pyx_CyFunction_Call(func, args, kw);
    }
    return result;
}
#endif /* CYTHON_USING_HPY  */

#if CYTHON_METH_FASTCALL
// Check that kwnames is empty (if you want to allow keyword arguments,
// simply pass kwnames=NULL) and figure out what to do with "self".
// Return value:
//  1: self = args[0]
//  0: self = cyfunc->func.m_self
// -1: error
static CYTHON_INLINE int __Pyx_CyFunction_Vectorcall_CheckArgs(HPY_CONTEXT_FIRST_ARG_DEF __pyx_CyFunctionObject *cyfunc, ssize_t nargs, PYOBJECT_TYPE kwnames)
{
    int ret = 0;
    if ((cyfunc->flags & __Pyx_CYFUNCTION_CCLASS) && !(cyfunc->flags & __Pyx_CYFUNCTION_STATICMETHOD)) {
        if (unlikely(nargs < 1)) {
            PyErr_Format(PyExc_TypeError, "%.200s() needs an argument",
                         "");
                         // ((PyCFunctionObject*)cyfunc)->m_ml->ml_name);
            return -1;
        }
        ret = 1;
    }
    if (unlikely(API_IS_NOT_NULL(kwnames)) && unlikely(TUPLE_GET_SIZE(kwnames))) {
        PyErr_Format(PyExc_TypeError,
                     "%.200s() takes no keyword arguments",
                     "");
                     // ((PyCFunctionObject*)cyfunc)->m_ml->ml_name);
        return -1;
    }
    return ret;
}

#if CYTHON_USING_HPY
static HPy __Pyx_CyFunction_hpycall_NOARGS_impl(HPyContext *HPY_CONTEXT_CNAME, HPy func, const HPy *args, size_t nargs, HPy kwnames)
{
    __pyx_CyFunctionObject *cyfunc = __pyx_CyFunctionObject_AsStruct(HPY_CONTEXT_CNAME, func);
    HPyDef *def = cyfunc->func;
    assert(def->kind == HPyDef_Kind_Meth);
    HPy result, self;
    int self_needs_close = 0;
    switch (__Pyx_CyFunction_Vectorcall_CheckArgs(HPY_CONTEXT_CNAME, cyfunc, nargs, kwnames)) {
    case 1:
        self = args[0];
        args += 1;
        nargs -= 1;
        break;
    case 0:
        self = HPyField_Load(HPY_CONTEXT_CNAME, func, cyfunc->func_self);
        self_needs_close = 1;
        break;
    default:
        return HPy_NULL;
    }

    if (unlikely(nargs != 0)) {
        HPyErr_Format(HPY_CONTEXT_CNAME, API_EXC(TypeError),
            "%.200s() takes no arguments (%" CYTHON_FORMAT_SSIZE_T "d given)",
            def->meth.name, nargs);
        return HPy_NULL;
    }
    HPyFunc_noargs func_noargs = def->meth.impl;
    result = func_noargs(HPY_CONTEXT_CNAME, self);
    if (self_needs_close) {
        HPy_Close(HPY_CONTEXT_CNAME, self);
    }
    return result;
}

static HPy __Pyx_CyFunction_hpycall_KEYWORDS_impl(HPyContext *HPY_CONTEXT_CNAME, HPy func, const HPy *args, size_t nargs, HPy kwnames)
{
    __pyx_CyFunctionObject *cyfunc = __pyx_CyFunctionObject_AsStruct(HPY_CONTEXT_CNAME, func);
    HPyDef *def = cyfunc->func;
    assert(def->kind == HPyDef_Kind_Meth);
    HPy result, self;
    int self_needs_close = 0;

    switch (__Pyx_CyFunction_Vectorcall_CheckArgs(HPY_CONTEXT_CNAME, cyfunc, nargs, kwnames)) {
    case 1:
        self = args[0];
        args += 1;
        nargs -= 1;
        break;
    case 0:
        self = HPyField_Load(HPY_CONTEXT_CNAME, func, cyfunc->func_self);
        self_needs_close = 1;
        break;
    default:
        return HPy_NULL;
    }

    HPyFunc_keywords func_keywords = def->meth.impl;
    result = func_keywords(HPY_CONTEXT_CNAME, self, args, nargs, kwnames);
    if (self_needs_close) {
        HPy_Close(HPY_CONTEXT_CNAME, self);
    }
    return result;
}

#else /* CYTHON_USING_HPY */
static PyObject * __Pyx_CyFunction_Vectorcall_NOARGS(PyObject *func, PyObject *const *args, size_t nargsf, PyObject *kwnames)
{
    __pyx_CyFunctionObject *cyfunc = (__pyx_CyFunctionObject *)func;
    PyMethodDef* def = ((PyCFunctionObject*)cyfunc)->m_ml;
#if CYTHON_BACKPORT_VECTORCALL
    Py_ssize_t nargs = (Py_ssize_t)nargsf;
#else
    Py_ssize_t nargs = PyVectorcall_NARGS(nargsf);
#endif
    PyObject *self;
    switch (__Pyx_CyFunction_Vectorcall_CheckArgs(cyfunc, nargs, kwnames)) {
    case 1:
        self = args[0];
        args += 1;
        nargs -= 1;
        break;
    case 0:
        self = ((PyCFunctionObject*)cyfunc)->m_self;
        break;
    default:
        return NULL;
    }

    if (unlikely(nargs != 0)) {
        PyErr_Format(PyExc_TypeError,
            "%.200s() takes no arguments (%" CYTHON_FORMAT_SSIZE_T "d given)",
            def->ml_name, nargs);
        return NULL;
    }
    return def->ml_meth(self, NULL);
}

static PyObject * __Pyx_CyFunction_Vectorcall_O(PyObject *func, PyObject *const *args, size_t nargsf, PyObject *kwnames)
{
    __pyx_CyFunctionObject *cyfunc = (__pyx_CyFunctionObject *)func;
    PyMethodDef* def = ((PyCFunctionObject*)cyfunc)->m_ml;
#if CYTHON_BACKPORT_VECTORCALL
    Py_ssize_t nargs = (Py_ssize_t)nargsf;
#else
    Py_ssize_t nargs = PyVectorcall_NARGS(nargsf);
#endif
    PyObject *self;
    switch (__Pyx_CyFunction_Vectorcall_CheckArgs(cyfunc, nargs, kwnames)) {
    case 1:
        self = args[0];
        args += 1;
        nargs -= 1;
        break;
    case 0:
        self = ((PyCFunctionObject*)cyfunc)->m_self;
        break;
    default:
        return NULL;
    }

    if (unlikely(nargs != 1)) {
        PyErr_Format(PyExc_TypeError,
            "%.200s() takes exactly one argument (%" CYTHON_FORMAT_SSIZE_T "d given)",
            def->ml_name, nargs);
        return NULL;
    }
    return def->ml_meth(self, args[0]);
}

static PyObject * __Pyx_CyFunction_Vectorcall_FASTCALL_KEYWORDS(PyObject *func, PyObject *const *args, size_t nargsf, PyObject *kwnames)
{
    __pyx_CyFunctionObject *cyfunc = (__pyx_CyFunctionObject *)func;
    PyMethodDef* def = ((PyCFunctionObject*)cyfunc)->m_ml;
#if CYTHON_BACKPORT_VECTORCALL
    Py_ssize_t nargs = (Py_ssize_t)nargsf;
#else
    Py_ssize_t nargs = PyVectorcall_NARGS(nargsf);
#endif
    PyObject *self;
    switch (__Pyx_CyFunction_Vectorcall_CheckArgs(cyfunc, nargs, NULL)) {
    case 1:
        self = args[0];
        args += 1;
        nargs -= 1;
        break;
    case 0:
        self = ((PyCFunctionObject*)cyfunc)->m_self;
        break;
    default:
        return NULL;
    }

    return ((_PyCFunctionFastWithKeywords)(void(*)(void))def->ml_meth)(self, args, nargs, kwnames);
}

static PyObject * __Pyx_CyFunction_Vectorcall_FASTCALL_KEYWORDS_METHOD(PyObject *func, PyObject *const *args, size_t nargsf, PyObject *kwnames)
{
    __pyx_CyFunctionObject *cyfunc = (__pyx_CyFunctionObject *)func;
    PyMethodDef* def = ((PyCFunctionObject*)cyfunc)->m_ml;
    PyTypeObject *cls = (PyTypeObject *) __Pyx_CyFunction_GetClassObj(cyfunc);
#if CYTHON_BACKPORT_VECTORCALL
    Py_ssize_t nargs = (Py_ssize_t)nargsf;
#else
    Py_ssize_t nargs = PyVectorcall_NARGS(nargsf);
#endif
    PyObject *self;
    switch (__Pyx_CyFunction_Vectorcall_CheckArgs(cyfunc, nargs, NULL)) {
    case 1:
        self = args[0];
        args += 1;
        nargs -= 1;
        break;
    case 0:
        self = ((PyCFunctionObject*)cyfunc)->m_self;
        break;
    default:
        return NULL;
    }

    return ((__Pyx_PyCMethod)(void(*)(void))def->ml_meth)(self, cls, args, (size_t)nargs, kwnames);
}
#endif /* !CYTHON_USING_HPY */
#endif

#if CYTHON_USING_HPY
HPyDef_SLOT(__Pyx_CyFunction_call, HPy_tp_call)
static HPy __Pyx_CyFunction_call_impl(HPyContext *HPY_CONTEXT_CNAME, HPy func, const HPy *args, size_t nargs, HPy kwnames)
{
    HPyErr_SetString(HPY_CONTEXT_CNAME, API_EXC(TypeError), "unsupported generic call");
    return HPy_NULL;
}
#endif

#if CYTHON_USE_TYPE_SPECS
#if CYTHON_USING_HPY

HPyDef_SLOT(__pyx_CyFunction_descr_get, HPy_tp_descr_get)
static HPy __pyx_CyFunction_descr_get_impl(HPyContext *ctx, HPy func, HPy self, HPy typ) {
    return __Pyx_PyMethod_New(ctx, func, self, typ);
}

static HPyDef *__pyx_CyFunctionType_HPyDefines[] = {
    &__Pyx_CyFunction_repr,
    &__Pyx_CyFunction_call,
    &__Pyx_CyFunction_traverse,
    &__Pyx_CyFunction_destroy,
    &__Pyx_CyFunction_reduce,
    &__pyx_CyFunction_member_module,
    &__pyx_CyFunction_member_dictoffset,
    // {Py_tp_getset, (void *)__pyx_CyFunction_getsets},
    &__Pyx_CyFunction_doc,
    // {Py_tp_descr_get, (void *)__Pyx_PyMethod_New},
    &__pyx_CyFunction_descr_get,
    NULL
};

static HPyType_Spec __pyx_CyFunctionType_spec = {
    __PYX_TYPE_MODULE_PREFIX "cython_function_or_method",
    .basicsize = sizeof(__pyx_CyFunctionObject),
    .itemsize = 0,
    .flags = HPy_TPFLAGS_DEFAULT | HPy_TPFLAGS_HAVE_GC | HPy_TPFLAGS_BASETYPE, /*tp_flags*/
    .builtin_shape = SHAPE(__pyx_CyFunctionObject),
    .defines = __pyx_CyFunctionType_HPyDefines
};
#else /* CYTHON_USING_HPY */
static PyType_Slot __pyx_CyFunctionType_slots[] = {
    {Py_tp_repr, (void *)__Pyx_CyFunction_repr_impl},
    {Py_tp_call, (void *)__Pyx_CyFunction_CallAsMethod},
    {Py_tp_traverse, (void *)__Pyx_CyFunction_traverse_impl},
    {Py_tp_dealloc, (void *)__Pyx_CyFunction_dealloc},
    {Py_tp_clear, (void *)__Pyx_CyFunction_clear},
    {Py_tp_methods, (void *)__pyx_CyFunction_methods},
    {Py_tp_members, (void *)__pyx_CyFunction_members},
    {Py_tp_getset, (void *)__pyx_CyFunction_getsets},
{Py_tp_descr_get, (void *)__Pyx_PyMethod_New},
    {0, 0},
};

static PyType_Spec __pyx_CyFunctionType_spec = {
    __PYX_TYPE_MODULE_PREFIX "cython_function_or_method",
    sizeof(__pyx_CyFunctionObject),
    0,
#ifdef Py_TPFLAGS_METHOD_DESCRIPTOR
    Py_TPFLAGS_METHOD_DESCRIPTOR |
#endif
#if (defined(_Py_TPFLAGS_HAVE_VECTORCALL) && CYTHON_METH_FASTCALL)
    _Py_TPFLAGS_HAVE_VECTORCALL |
#endif
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HAVE_GC | Py_TPFLAGS_BASETYPE, /*tp_flags*/
    __pyx_CyFunctionType_slots
};
#endif /* CYTHON_USING_HPY */
#else /* CYTHON_USE_TYPE_SPECS */
#if CYTHON_USING_HPY
#error "HPy needs CYTHON_USE_TYPE_SPECS"
#endif

static PyTypeObject __pyx_CyFunctionType_type = {
    PyVarObject_HEAD_INIT(0, 0)
    __PYX_TYPE_MODULE_PREFIX "cython_function_or_method",  /*tp_name*/
    sizeof(__pyx_CyFunctionObject),   /*tp_basicsize*/
    0,                                  /*tp_itemsize*/
    (destructor) __Pyx_CyFunction_dealloc, /*tp_dealloc*/
#if !CYTHON_METH_FASTCALL
    0,                                  /*tp_print*/
#elif CYTHON_BACKPORT_VECTORCALL
    (printfunc)offsetof(__pyx_CyFunctionObject, func_vectorcall), /*tp_vectorcall_offset backported into tp_print*/
#else
    offsetof(PyCFunctionObject, vectorcall), /*tp_vectorcall_offset*/
#endif
    0,                                  /*tp_getattr*/
    0,                                  /*tp_setattr*/
    0,                                  /*tp_as_async*/
    (reprfunc) __Pyx_CyFunction_repr_impl,   /*tp_repr*/
    0,                                  /*tp_as_number*/
    0,                                  /*tp_as_sequence*/
    0,                                  /*tp_as_mapping*/
    0,                                  /*tp_hash*/
    __Pyx_CyFunction_CallAsMethod,      /*tp_call*/
    0,                                  /*tp_str*/
    0,                                  /*tp_getattro*/
    0,                                  /*tp_setattro*/
    0,                                  /*tp_as_buffer*/
#ifdef Py_TPFLAGS_METHOD_DESCRIPTOR
    Py_TPFLAGS_METHOD_DESCRIPTOR |
#endif
#if defined(_Py_TPFLAGS_HAVE_VECTORCALL) && CYTHON_METH_FASTCALL
    _Py_TPFLAGS_HAVE_VECTORCALL |
#endif
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HAVE_GC | Py_TPFLAGS_BASETYPE, /*tp_flags*/
    0,                                  /*tp_doc*/
    (traverseproc) __Pyx_CyFunction_traverse,   /*tp_traverse*/
    (inquiry) __Pyx_CyFunction_clear,   /*tp_clear*/
    0,                                  /*tp_richcompare*/
    offsetof(PyCFunctionObject, m_weakreflist),         /*tp_weaklistoffset*/
    0,                                  /*tp_iter*/
    0,                                  /*tp_iternext*/
    __pyx_CyFunction_methods,           /*tp_methods*/
    __pyx_CyFunction_members,           /*tp_members*/
    __pyx_CyFunction_getsets,           /*tp_getset*/
    0,                                  /*tp_base*/
    0,                                  /*tp_dict*/
    __Pyx_PyMethod_New,                 /*tp_descr_get*/
    0,                                  /*tp_descr_set*/
    offsetof(__pyx_CyFunctionObject, func_dict),/*tp_dictoffset*/
    0,                                  /*tp_init*/
    0,                                  /*tp_alloc*/
    0,                                  /*tp_new*/
    0,                                  /*tp_free*/
    0,                                  /*tp_is_gc*/
    0,                                  /*tp_bases*/
    0,                                  /*tp_mro*/
    0,                                  /*tp_cache*/
    0,                                  /*tp_subclasses*/
    0,                                  /*tp_weaklist*/
    0,                                  /*tp_del*/
    0,                                  /*tp_version_tag*/
    0,                                  /*tp_finalize*/
#if PY_VERSION_HEX >= 0x030800b1 && (!CYTHON_COMPILING_IN_PYPY || PYPY_VERSION_NUM >= 0x07030800)
    0,                                  /*tp_vectorcall*/
#endif
#if __PYX_NEED_TP_PRINT_SLOT
    0,                                  /*tp_print*/
#endif
#if PY_VERSION_HEX >= 0x030C0000
    0,                                  /*tp_watched*/
#endif
#if CYTHON_COMPILING_IN_PYPY && PY_VERSION_HEX >= 0x03090000 && PY_VERSION_HEX < 0x030a0000
    0,                                          /*tp_pypy_flags*/
#endif
};
#endif  /* CYTHON_USE_TYPE_SPECS */


static int __pyx_CyFunction_init(HPY_CONTEXT_FIRST_ARG_DEF PYOBJECT_GLOBAL_TYPE module) {
#if CYTHON_USE_TYPE_SPECS
    PYOBJECT_TYPE cyFunctionType = __Pyx_FetchCommonTypeFromSpec(HPY_CONTEXT_FIRST_ARG_CALL module, __pyx_CyFunctionType_spec, API_NULL_VALUE);
    PYOBJECT_GLOBAL_STORE(__pyx_CyFunctionType, cyFunctionType);
    PYOBJECT_GLOBAL_CLOSEREF(cyFunctionType);
    int cyFunctionType_is_null = API_IS_NULL(cyFunctionType);
#else
    CYTHON_UNUSED_VAR(module);
    __pyx_CyFunctionType = __Pyx_FetchCommonType(&__pyx_CyFunctionType_type);
    int cyFunctionType_is_null = API_IS_NULL(__pyx_CyFunctionType);
#endif
    if (unlikely(cyFunctionType_is_null)) {
        return -1;
    }
    return 0;
}

static CYTHON_INLINE void *__Pyx_CyFunction_InitDefaults(PyObject *func, size_t size, int pyobjects) {
    __pyx_CyFunctionObject *m = (__pyx_CyFunctionObject *) func;

    m->defaults = PyObject_Malloc(size);
    if (unlikely(!m->defaults))
        return PyErr_NoMemory();
    memset(m->defaults, 0, size);
    m->defaults_pyobjects = pyobjects;
    m->defaults_size = size;
    return m->defaults;
}

static CYTHON_INLINE void __Pyx_CyFunction_SetDefaultsTuple(HPY_CONTEXT_FIRST_ARG_DEF PYOBJECT_TYPE func, PYOBJECT_TYPE tuple) {
#if !CYTHON_USING_HPY
    __pyx_CyFunctionObject *m = (__pyx_CyFunctionObject *) func;
    m->defaults_tuple = tuple;
    Py_INCREF(tuple);
#else
    __pyx_CyFunctionObject *m = __pyx_CyFunctionObject_AsStruct(HPY_CONTEXT_CNAME, func);
    PYOBJECT_FIELD_STORE(func, m->defaults_tuple, tuple);
#endif
}

static CYTHON_INLINE void __Pyx_CyFunction_SetDefaultsKwDict(HPY_CONTEXT_FIRST_ARG_DEF PYOBJECT_TYPE func, PYOBJECT_TYPE dict) {
#if !CYTHON_USING_HPY
    __pyx_CyFunctionObject *m = (__pyx_CyFunctionObject *) func;
    m->defaults_kwdict = dict;
    Py_INCREF(dict);
#else
    __pyx_CyFunctionObject *m = __pyx_CyFunctionObject_AsStruct(HPY_CONTEXT_CNAME, func);
    PYOBJECT_FIELD_STORE(func, m->defaults_kwdict, dict);
#endif
}

static CYTHON_INLINE void __Pyx_CyFunction_SetAnnotationsDict(HPY_CONTEXT_FIRST_ARG_DEF PYOBJECT_TYPE func, PYOBJECT_TYPE dict) {
#if !CYTHON_USING_HPY
    __pyx_CyFunctionObject *m = (__pyx_CyFunctionObject *) func;
    m->func_annotations = dict;
    Py_INCREF(dict);
#else
    __pyx_CyFunctionObject *m = __pyx_CyFunctionObject_AsStruct(HPY_CONTEXT_CNAME, func);
    PYOBJECT_FIELD_STORE(func, m->func_annotations, dict);
#endif
}


//////////////////// CythonFunction.proto ////////////////////

static PYOBJECT_TYPE __Pyx_CyFunction_New(HPY_CONTEXT_FIRST_ARG_DEF
                                      PYMETHODDEF_TYPE *ml,
                                      int flags, PYOBJECT_TYPE qualname,
                                      PYOBJECT_TYPE closure,
                                      PYOBJECT_TYPE module, PYOBJECT_TYPE globals,
                                      PYOBJECT_TYPE code);

//////////////////// CythonFunction ////////////////////
//@requires: CythonFunctionShared

static PYOBJECT_TYPE __Pyx_CyFunction_New(HPY_CONTEXT_FIRST_ARG_DEF PYMETHODDEF_TYPE *ml, int flags, PYOBJECT_TYPE qualname,
                                      PYOBJECT_TYPE closure, PYOBJECT_TYPE module, PYOBJECT_TYPE globals, PYOBJECT_TYPE code) {
#if !CYTHON_USING_HPY
    PYOBJECT_TYPE op = __Pyx_CyFunction_Init(HPY_CONTEXT_FIRST_ARG_CALL
        PyObject_GC_New(__pyx_CyFunctionObject, __pyx_CyFunctionType),
        ml, flags, qualname, closure, module, globals, code
    );
    if (likely(op)) {
        PyObject_GC_Track(op);
    }
    return op;
#else
    __pyx_CyFunctionObject *func_obj;
    HPy __pyx_HPyCyFunctionType = HPyGlobal_Load(HPY_CONTEXT_CNAME, __pyx_CyFunctionType);
    HPy func = HPy_New(HPY_CONTEXT_CNAME, __pyx_HPyCyFunctionType, &func_obj);
    HPy_Close(HPY_CONTEXT_CNAME, __pyx_HPyCyFunctionType);
    HPy op = __Pyx_CyFunction_Init(
        HPY_CONTEXT_FIRST_ARG_CALL func, ml, flags, qualname, closure, module, globals, code
    );
    return op;

#endif
}

//////////////////// CyFunctionClassCell.proto ////////////////////
static int __Pyx_CyFunction_InitClassCell(PyObject *cyfunctions, PyObject *classobj);/*proto*/

//////////////////// CyFunctionClassCell ////////////////////
//@requires: CythonFunctionShared

static int __Pyx_CyFunction_InitClassCell(PyObject *cyfunctions, PyObject *classobj) {
    Py_ssize_t i, count = PyList_GET_SIZE(cyfunctions);

    for (i = 0; i < count; i++) {
        __pyx_CyFunctionObject *m = (__pyx_CyFunctionObject *)
#if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
            PyList_GET_ITEM(cyfunctions, i);
#else
            __Pyx_PySequence_ITEM(cyfunctions, i);
        if (unlikely(!m))
            return -1;
#endif
        __Pyx_CyFunction_SetClassObj(m, classobj);
#if !(CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS)
        Py_DECREF((PyObject*)m);
#endif
    }
    return 0;
}


//////////////////// FusedFunction.proto ////////////////////

typedef struct {
    __pyx_CyFunctionObject func;
    PyObject *__signatures__;
    PyObject *self;
} __pyx_FusedFunctionObject;

static PyObject *__pyx_FusedFunction_New(PyMethodDef *ml, int flags,
                                         PyObject *qualname, PyObject *closure,
                                         PyObject *module, PyObject *globals,
                                         PyObject *code);

static int __pyx_FusedFunction_clear(__pyx_FusedFunctionObject *self);
static int __pyx_FusedFunction_init(PyObject *module);

#define __Pyx_FusedFunction_USED

//////////////////// FusedFunction ////////////////////
//@requires: CythonFunctionShared

static PyObject *
__pyx_FusedFunction_New(PyMethodDef *ml, int flags,
                        PyObject *qualname, PyObject *closure,
                        PyObject *module, PyObject *globals,
                        PyObject *code)
{
    PyObject *op = __Pyx_CyFunction_Init(
        HPY_CONTEXT_FIRST_ARG_CALL
        // __pyx_CyFunctionObject is correct below since that's the cast that we want.
        PyObject_GC_New(__pyx_CyFunctionObject, __pyx_FusedFunctionType),
        ml, flags, qualname, closure, module, globals, code
    );
    if (likely(op)) {
        __pyx_FusedFunctionObject *fusedfunc = (__pyx_FusedFunctionObject *) op;
        fusedfunc->__signatures__ = NULL;
        fusedfunc->self = NULL;
        PyObject_GC_Track(op);
    }
    return op;
}

static void
__pyx_FusedFunction_dealloc(__pyx_FusedFunctionObject *self)
{
    PyObject_GC_UnTrack(self);
    Py_CLEAR(self->self);
    Py_CLEAR(self->__signatures__);
    __Pyx__CyFunction_dealloc((__pyx_CyFunctionObject *) self);
}

static int
__pyx_FusedFunction_traverse(__pyx_FusedFunctionObject *self,
                             visitproc visit,
                             void *arg)
{
    Py_VISIT(self->self);
    Py_VISIT(self->__signatures__);
    return __Pyx_CyFunction_traverse((__pyx_CyFunctionObject *) self, visit, arg);
}

static int
__pyx_FusedFunction_clear(__pyx_FusedFunctionObject *self)
{
    Py_CLEAR(self->self);
    Py_CLEAR(self->__signatures__);
    return __Pyx_CyFunction_clear((__pyx_CyFunctionObject *) self);
}


static PyObject *
__pyx_FusedFunction_descr_get(PyObject *self, PyObject *obj, PyObject *type)
{
    __pyx_FusedFunctionObject *func, *meth;

    func = (__pyx_FusedFunctionObject *) self;

    if (func->self || func->func.flags & __Pyx_CYFUNCTION_STATICMETHOD) {
        // Do not allow rebinding and don't do anything for static methods
        Py_INCREF(self);
        return self;
    }

    if (obj == Py_None)
        obj = NULL;

    if (func->func.flags & __Pyx_CYFUNCTION_CLASSMETHOD)
        obj = type;

    if (obj == NULL) {
        // We aren't actually binding to anything, save the effort of rebinding
        Py_INCREF(self);
        return self;
    }

    meth = (__pyx_FusedFunctionObject *) __pyx_FusedFunction_New(
                    ((PyCFunctionObject *) func)->m_ml,
                    ((__pyx_CyFunctionObject *) func)->flags,
                    ((__pyx_CyFunctionObject *) func)->func_qualname,
                    ((__pyx_CyFunctionObject *) func)->func_closure,
                    ((PyCFunctionObject *) func)->m_module,
                    ((__pyx_CyFunctionObject *) func)->func_globals,
                    ((__pyx_CyFunctionObject *) func)->func_code);
    if (unlikely(!meth))
        return NULL;

    // defaults needs copying fully rather than just copying the pointer
    // since otherwise it will be freed on destruction of meth despite
    // belonging to func rather than meth
    if (func->func.defaults) {
        PyObject **pydefaults;
        int i;

        if (unlikely(!__Pyx_CyFunction_InitDefaults(
                (PyObject*)meth,
                func->func.defaults_size,
                func->func.defaults_pyobjects))) {
            Py_XDECREF((PyObject*)meth);
            return NULL;
        }
        memcpy(meth->func.defaults, func->func.defaults, func->func.defaults_size);

        pydefaults = __Pyx_CyFunction_Defaults(PyObject *, meth);
        for (i = 0; i < meth->func.defaults_pyobjects; i++)
            Py_XINCREF(pydefaults[i]);
    }

    __Pyx_CyFunction_SetClassObj(meth, __Pyx_CyFunction_GetClassObj(func));

    Py_XINCREF(func->__signatures__);
    meth->__signatures__ = func->__signatures__;

    Py_XINCREF(func->func.defaults_tuple);
    meth->func.defaults_tuple = func->func.defaults_tuple;

    Py_XINCREF(obj);
    meth->self = obj;

    return (PyObject *) meth;
}

static PyObject *
_obj_to_string(PyObject *obj)
{
    if (PyUnicode_CheckExact(obj))
        return __Pyx_NewRef(obj);
    else if (PyType_Check(obj))
        return PyObject_GetAttr(obj, PYIDENT("__name__"));
    else
        return PyObject_Unicode(obj);
}

static PyObject *
__pyx_FusedFunction_getitem(__pyx_FusedFunctionObject *self, PyObject *idx)
{
    PyObject *signature = NULL;
    PyObject *unbound_result_func;
    PyObject *result_func = NULL;

    if (unlikely(self->__signatures__ == NULL)) {
        PyErr_SetString(PyExc_TypeError, "Function is not fused");
        return NULL;
    }

    if (PyTuple_Check(idx)) {
        Py_ssize_t n = PyTuple_GET_SIZE(idx);
        PyObject *list = PyList_New(n);
        int i;

        if (unlikely(!list))
            return NULL;

        for (i = 0; i < n; i++) {
            PyObject *string;
#if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
            PyObject *item = PyTuple_GET_ITEM(idx, i);
#else
            PyObject *item = __Pyx_PySequence_ITEM(idx, i);  if (unlikely(!item)) goto __pyx_err;
#endif
            string = _obj_to_string(item);
#if !(CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS)
            Py_DECREF(item);
#endif
            if (unlikely(!string)) goto __pyx_err;
            PyList_SET_ITEM(list, i, string);
        }

        signature = PyUnicode_Join(PYUNICODE("|"), list);
__pyx_err:;
        Py_DECREF(list);
    } else {
        signature = _obj_to_string(idx);
    }

    if (unlikely(!signature))
        return NULL;

    unbound_result_func = PyObject_GetItem(self->__signatures__, signature);

    if (likely(unbound_result_func)) {
        if (self->self) {
            __pyx_FusedFunctionObject *unbound = (__pyx_FusedFunctionObject *) unbound_result_func;

            // TODO: move this to InitClassCell
            __Pyx_CyFunction_SetClassObj(unbound, __Pyx_CyFunction_GetClassObj(self));

            result_func = __pyx_FusedFunction_descr_get(unbound_result_func,
                                                        self->self, self->self);
        } else {
            result_func = unbound_result_func;
            Py_INCREF(result_func);
        }
    }

    Py_DECREF(signature);
    Py_XDECREF(unbound_result_func);

    return result_func;
}

static PyObject *
__pyx_FusedFunction_callfunction(PyObject *func, PyObject *args, PyObject *kw)
{
     __pyx_CyFunctionObject *cyfunc = (__pyx_CyFunctionObject *) func;
    int static_specialized = (cyfunc->flags & __Pyx_CYFUNCTION_STATICMETHOD &&
                              !((__pyx_FusedFunctionObject *) func)->__signatures__);

    if ((cyfunc->flags & __Pyx_CYFUNCTION_CCLASS) && !static_specialized) {
        return __Pyx_CyFunction_CallAsMethod(func, args, kw);
    } else {
        return __Pyx_CyFunction_Call(func, args, kw);
    }
}

// Note: the 'self' from method binding is passed in in the args tuple,
//       whereas PyCFunctionObject's m_self is passed in as the first
//       argument to the C function. For extension methods we need
//       to pass 'self' as 'm_self' and not as the first element of the
//       args tuple.

static PyObject *
__pyx_FusedFunction_call(PyObject *func, PyObject *args, PyObject *kw)
{
    __pyx_FusedFunctionObject *binding_func = (__pyx_FusedFunctionObject *) func;
    Py_ssize_t argc = PyTuple_GET_SIZE(args);
    PyObject *new_args = NULL;
    __pyx_FusedFunctionObject *new_func = NULL;
    PyObject *result = NULL;
    int is_staticmethod = binding_func->func.flags & __Pyx_CYFUNCTION_STATICMETHOD;

    if (binding_func->self) {
        // Bound method call, put 'self' in the args tuple
        PyObject *self;
        Py_ssize_t i;
        new_args = PyTuple_New(argc + 1);
        if (unlikely(!new_args))
            return NULL;

        self = binding_func->self;

        Py_INCREF(self);
        PyTuple_SET_ITEM(new_args, 0, self);
        self = NULL;

        for (i = 0; i < argc; i++) {
#if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
            PyObject *item = PyTuple_GET_ITEM(args, i);
            Py_INCREF(item);
#else
            PyObject *item = __Pyx_PySequence_ITEM(args, i);  if (unlikely(!item)) goto bad;
#endif
            PyTuple_SET_ITEM(new_args, i + 1, item);
        }

        args = new_args;
    }

    if (binding_func->__signatures__) {
        PyObject *tup;
        if (is_staticmethod && binding_func->func.flags & __Pyx_CYFUNCTION_CCLASS) {
            // FIXME: this seems wrong, but we must currently pass the signatures dict as 'self' argument
            tup = PyTuple_Pack(3, args,
                               kw == NULL ? Py_None : kw,
                               binding_func->func.defaults_tuple);
            if (unlikely(!tup)) goto bad;
            new_func = (__pyx_FusedFunctionObject *) __Pyx_CyFunction_CallMethod(
                HPY_CONTEXT_FIRST_ARG_CALL func, binding_func->__signatures__, tup, NULL);
        } else {
            tup = PyTuple_Pack(4, binding_func->__signatures__, args,
                               kw == NULL ? Py_None : kw,
                               binding_func->func.defaults_tuple);
            if (unlikely(!tup)) goto bad;
            new_func = (__pyx_FusedFunctionObject *) __pyx_FusedFunction_callfunction(func, tup, NULL);
        }
        Py_DECREF(tup);

        if (unlikely(!new_func))
            goto bad;

        __Pyx_CyFunction_SetClassObj(new_func, __Pyx_CyFunction_GetClassObj(binding_func));

        func = (PyObject *) new_func;
    }

    result = __pyx_FusedFunction_callfunction(func, args, kw);
bad:
    Py_XDECREF(new_args);
    Py_XDECREF((PyObject *) new_func);
    return result;
}

static PyMemberDef __pyx_FusedFunction_members[] = {
    {"__signatures__",
     T_OBJECT,
     offsetof(__pyx_FusedFunctionObject, __signatures__),
     READONLY,
     0},
    {"__self__", T_OBJECT_EX, offsetof(__pyx_FusedFunctionObject, self), READONLY, 0},
    {0, 0, 0, 0, 0},
};

static PyGetSetDef __pyx_FusedFunction_getsets[] = {
    // __doc__ is None for the fused function type, but we need it to be
    // a descriptor for the instance's __doc__, so rebuild the descriptor in our subclass
    // (all other descriptors are inherited)
    {"__doc__",  (getter)__Pyx_CyFunction_get_doc, (setter)__Pyx_CyFunction_set_doc, 0, 0},
    {0, 0, 0, 0, 0}
};

#if CYTHON_USE_TYPE_SPECS
static PyType_Slot __pyx_FusedFunctionType_slots[] = {
    {Py_tp_dealloc, (void *)__pyx_FusedFunction_dealloc},
    {Py_tp_call, (void *)__pyx_FusedFunction_call},
    {Py_tp_traverse, (void *)__pyx_FusedFunction_traverse},
    {Py_tp_clear, (void *)__pyx_FusedFunction_clear},
    {Py_tp_members, (void *)__pyx_FusedFunction_members},
    {Py_tp_getset, (void *)__pyx_FusedFunction_getsets},
    {Py_tp_descr_get, (void *)__pyx_FusedFunction_descr_get},
    {Py_mp_subscript, (void *)__pyx_FusedFunction_getitem},
    {0, 0},
};

static PyType_Spec __pyx_FusedFunctionType_spec = {
    __PYX_TYPE_MODULE_PREFIX "fused_cython_function",
    sizeof(__pyx_FusedFunctionObject),
    0,
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HAVE_GC | Py_TPFLAGS_BASETYPE, /*tp_flags*/
    __pyx_FusedFunctionType_slots
};

#else  /* !CYTHON_USE_TYPE_SPECS */

static PyMappingMethods __pyx_FusedFunction_mapping_methods = {
    0,
    (binaryfunc) __pyx_FusedFunction_getitem,
    0,
};

static PyTypeObject __pyx_FusedFunctionType_type = {
    PyVarObject_HEAD_INIT(0, 0)
    __PYX_TYPE_MODULE_PREFIX "fused_cython_function",  /*tp_name*/
    sizeof(__pyx_FusedFunctionObject), /*tp_basicsize*/
    0,                                  /*tp_itemsize*/
    (destructor) __pyx_FusedFunction_dealloc, /*tp_dealloc*/
    0,                                  /*tp_print*/
    0,                                  /*tp_getattr*/
    0,                                  /*tp_setattr*/
    0,                                  /*tp_as_async*/
    0,                                  /*tp_repr*/
    0,                                  /*tp_as_number*/
    0,                                  /*tp_as_sequence*/
    &__pyx_FusedFunction_mapping_methods, /*tp_as_mapping*/
    0,                                  /*tp_hash*/
    (ternaryfunc) __pyx_FusedFunction_call, /*tp_call*/
    0,                                  /*tp_str*/
    0,                                  /*tp_getattro*/
    0,                                  /*tp_setattro*/
    0,                                  /*tp_as_buffer*/
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HAVE_GC | Py_TPFLAGS_BASETYPE, /*tp_flags*/
    0,                                  /*tp_doc*/
    (traverseproc) __pyx_FusedFunction_traverse,   /*tp_traverse*/
    (inquiry) __pyx_FusedFunction_clear,/*tp_clear*/
    0,                                  /*tp_richcompare*/
    0,                                  /*tp_weaklistoffset*/
    0,                                  /*tp_iter*/
    0,                                  /*tp_iternext*/
    0,                                  /*tp_methods*/
    __pyx_FusedFunction_members,        /*tp_members*/
    __pyx_FusedFunction_getsets,           /*tp_getset*/
    // NOTE: tp_base may be changed later during module initialisation when importing CyFunction across modules.
    &__pyx_CyFunctionType_type,         /*tp_base*/
    0,                                  /*tp_dict*/
    __pyx_FusedFunction_descr_get,      /*tp_descr_get*/
    0,                                  /*tp_descr_set*/
    0,                                  /*tp_dictoffset*/
    0,                                  /*tp_init*/
    0,                                  /*tp_alloc*/
    0,                                  /*tp_new*/
    0,                                  /*tp_free*/
    0,                                  /*tp_is_gc*/
    0,                                  /*tp_bases*/
    0,                                  /*tp_mro*/
    0,                                  /*tp_cache*/
    0,                                  /*tp_subclasses*/
    0,                                  /*tp_weaklist*/
    0,                                  /*tp_del*/
    0,                                  /*tp_version_tag*/
    0,                                  /*tp_finalize*/
#if PY_VERSION_HEX >= 0x030800b1 && (!CYTHON_COMPILING_IN_PYPY || PYPY_VERSION_NUM >= 0x07030800)
    0,                                  /*tp_vectorcall*/
#endif
#if __PYX_NEED_TP_PRINT_SLOT
    0,                                  /*tp_print*/
#endif
#if PY_VERSION_HEX >= 0x030C0000
    0,                                  /*tp_watched*/
#endif
#if CYTHON_COMPILING_IN_PYPY && PY_VERSION_HEX >= 0x03090000 && PY_VERSION_HEX < 0x030a0000
    0,                                          /*tp_pypy_flags*/
#endif
};
#endif

static int __pyx_FusedFunction_init(PyObject *module) {
#if CYTHON_USE_TYPE_SPECS
    PyObject *bases = PyTuple_Pack(1, __pyx_CyFunctionType);
    if (unlikely(!bases)) {
        return -1;
    }
    __pyx_FusedFunctionType = __Pyx_FetchCommonTypeFromSpec(module, &__pyx_FusedFunctionType_spec, bases);
    Py_DECREF(bases);
#else
    CYTHON_UNUSED_VAR(module);
    // Set base from __Pyx_FetchCommonTypeFromSpec, in case it's different from the local static value.
    __pyx_FusedFunctionType_type.tp_base = __pyx_CyFunctionType;
    __pyx_FusedFunctionType = __Pyx_FetchCommonType(&__pyx_FusedFunctionType_type);
#endif
    if (unlikely(__pyx_FusedFunctionType == NULL)) {
        return -1;
    }
    return 0;
}

//////////////////// ClassMethod.proto ////////////////////

#include "descrobject.h"
CYTHON_UNUSED static PyObject* __Pyx_Method_ClassMethod(PyObject *method); /*proto*/

//////////////////// ClassMethod ////////////////////

static PyObject* __Pyx_Method_ClassMethod(PyObject *method) {
#if CYTHON_COMPILING_IN_PYPY && PYPY_VERSION_NUM <= 0x05080000
    if (PyObject_TypeCheck(method, &PyWrapperDescr_Type)) {
        // cdef classes
        return PyClassMethod_New(method);
    }
#else
#if CYTHON_COMPILING_IN_PYPY
    // special C-API function only in PyPy >= 5.9
    if (PyMethodDescr_Check(method))
#else
    if (__Pyx_TypeCheck(method, &PyMethodDescr_Type))
#endif
    {
        // cdef classes
        PyMethodDescrObject *descr = (PyMethodDescrObject *)method;
        PyTypeObject *d_type = descr->d_common.d_type;
        return PyDescr_NewClassMethod(d_type, descr->d_method);
    }
#endif
    else if (PyMethod_Check(method)) {
        // python classes
        return PyClassMethod_New(PyMethod_GET_FUNCTION(method));
    }
    else {
        return PyClassMethod_New(method);
    }
}
