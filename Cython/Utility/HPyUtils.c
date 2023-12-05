/////////////// HPyInitCode ///////////////
//@substitute: naming

#if CYTHON_USING_HPY
  //HPy Context Macros
  #define HPY_CONTEXT_CNAME $hpy_context_cname
  #define HPY_CONTEXT_TYPE HPyContext *
  #define HPY_CONTEXT_ONLY_ARG_DEF HPY_CONTEXT_TYPE HPY_CONTEXT_CNAME
  #define HPY_CONTEXT_ONLY_ARG_CALL HPY_CONTEXT_CNAME
  #define HPY_CONTEXT_FIRST_ARG_DEF HPY_CONTEXT_TYPE HPY_CONTEXT_CNAME,
  #define HPY_CONTEXT_FIRST_ARG_CALL HPY_CONTEXT_CNAME,

  //Handle/PyObject Macros
  #define PYOBJECT_TYPE HPy
  #define PYOBJECT_TYPE_NO_POINTER HPy
  #define PYTYPEOBJECT_TYPE HPy
  #define PYOBJECT_FIELD_TYPE HPyField
  #define PYOBJECT_FIELD_STORE(owner, field, h) HPyField_Store(HPY_CONTEXT_CNAME, owner, &field, h)
  #define PYOBJECT_FIELD_LOAD(owner, field) HPyField_Load(HPY_CONTEXT_CNAME, owner, field)
  #define PYOBJECT_GLOBAL_TYPE HPyGlobal
  #define PYTYPEOBJECT_GLOBAL_TYPE HPyGlobal
  #define PYOBJECT_GLOBAL_STORE(global, h) HPyGlobal_Store(HPY_CONTEXT_CNAME, &global, h)
  #define PYOBJECT_GLOBAL_LOAD(global) HPyGlobal_Load(HPY_CONTEXT_CNAME, global)
  #define CAPI_IS_POINTER
  #define CAPI_NEEDS_DEREFERENCE
  #define CAST_IF_CAPI(type)

  //Create New and Close References
  #define PYOBJECT_NEWREF(h) HPy_Dup(HPY_CONTEXT_CNAME, h)
  #define PYOBJECT_XNEWREF(h) HPy_Dup(HPY_CONTEXT_CNAME, h)
  #define PYOBJECT_CLOSEREF(h) HPy_Close(HPY_CONTEXT_CNAME, h)
  #define PYOBJECT_XCLOSEREF(h) HPy_Close(HPY_CONTEXT_CNAME, h)
  #define PYOBJECT_CLEAR(h) HPy_Close(HPY_CONTEXT_CNAME, h)
  #define PYOBJECT_GLOBAL_CLOSEREF(ref) HPy_Close(HPY_CONTEXT_CNAME, ref)
  #define REFNANNY_CLOSEREF(func, h) PYOBJECT_CLOSEREF(h)

  //HPy to/from PyObject Functions
  #define HPY_LEGACY_OBJECT_FROM(o) HPy_FromPyObject(HPY_CONTEXT_CNAME, o)
  #define HPY_LEGACY_OBJECT_AS(o) HPy_AsPyObject(HPY_CONTEXT_CNAME, o)
  #define HPY_LEGACY_OBJECT_ARRAY_AS(o, ssize) HPy_AsPyObjectArray(HPY_CONTEXT_CNAME, o, ssize)

  //NULL/None Values and functions
  #define API_NULL_VALUE HPy_NULL
  #define API_DEFAULT_VALUE HPy_NULL
  #define API_IS_NULL(h) HPy_IsNull(h)
  #define API_IS_NOT_NULL(h) !HPy_IsNull(h)
  #define API_NONE_VALUE HPY_CONTEXT_CNAME->h_None
  #define API_ASSIGN_NONE HPy_Dup(HPY_CONTEXT_CNAME, HPY_CONTEXT_CNAME->h_None)

  //Boolean Values and Functions
  #define API_TRUE HPY_CONTEXT_CNAME->h_True
  #define API_FALSE HPY_CONTEXT_CNAME->h_False
  #define API_IS_TRUE(h) HPy_IsTrue(HPY_CONTEXT_CNAME, h)
  #define API_IS_FALSE(h) !HPy_IsTrue(HPY_CONTEXT_CNAME, h)

  //General Methods
  #define API_IS_EQUAL(a, b) HPy_Is(HPY_CONTEXT_CNAME, a, b)
  #define API_IS_NOT_EQUAL(a, b) !HPy_Is(HPY_CONTEXT_CNAME, a, b)
  #define API_RICH_COMPARE(h1, h2, op) HPy_RichCompare(HPY_CONTEXT_CNAME, h1, h2, op)
  #define API_RICH_COMPARE_BOOL(h1, h2, op) HPy_RichCompareBool(HPY_CONTEXT_CNAME, h1, h2, op)

  //API Call Macros
  #define API_CALL_FUNC(callable, args, nargs, kwnames) HPy_Call(HPY_CONTEXT_CNAME, callable, args, nargs, kwnames)

  //Type Objects
  #define API_LONG_TYPE HPY_CONTEXT_CNAME->h_LongType
  #define API_SSIZE_T HPy_ssize_t
  #define API_STRING_TYPE HPY_CONTEXT_CNAME->h_UnicodeType
  #define API_STRING_TYPE_DEREF API_STRING_TYPE
  #define API_DICT_TYPE HPY_CONTEXT_CNAME->h_DictType
  #define API_DICT_TYPE_DEREF API_DICT_TYPE

  //Type Checks
  #define LONG_CHECK(l) HPyNumber_Check(HPY_CONTEXT_CNAME, l)
  #define FLOAT_CHECK_EXACT(f) HPyNumber_Check(HPY_CONTEXT_CNAME, f)
  #define UNICODE_CHECK(u) HPyUnicode_Check(HPY_CONTEXT_CNAME, u)
  #define DICT_CHECK(o) HPyDict_Check(HPY_CONTEXT_CNAME, o)
  #define DICT_CHECK_EXACT(o) HPyDict_Check(HPY_CONTEXT_CNAME, o)
  #define TUPLE_CHECK(o) HPyTuple_Check(HPY_CONTEXT_CNAME, o)
  #define PYOBJECT_TYPE_CHECK(o, t) HPy_TypeCheck(HPY_CONTEXT_CNAME, o, t)
  #define LIST_CHECK(h) HPyList_Check(HPY_CONTEXT_CNAME, h)
  #define LIST_CHECK_EXACT(h) HPyList_Check(HPY_CONTEXT_CNAME, h)

  //Integer Type - From
  #define PYOBJECT_INT_FROM_LONG(i) HPyLong_FromLong(HPY_CONTEXT_CNAME, i)
  #define PYOBJECT_INT_FROM_UNSIGNED_LONG(i) HPyLong_FromUnsignedLong(HPY_CONTEXT_CNAME, i)

  //Integer Type - To
  #define PYOBJECT_INT_AS_LONG_NOERROR(l) HPyLong_AsLong(HPY_CONTEXT_CNAME, l)

  //Long Type - From
  #define PYOBJECT_LONG_FROM_LONG(i) HPyLong_FromLong(HPY_CONTEXT_CNAME, i)
  #define PYOBJECT_LONG_FROM_LONGLONG(i) HPyLong_FromLongLong(HPY_CONTEXT_CNAME, i)
  #define PYOBJECT_LONG_FROM_UNSIGNED_LONG(i) HPyLong_FromUnsignedLong(HPY_CONTEXT_CNAME, i)
  #define PYOBJECT_LONG_FROM_UNSIGNED_LONGLONG(i) HPyLong_FromUnsignedLongLong(HPY_CONTEXT_CNAME, i)
  #define PYOBJECT_LONG_FROM_SSIZE_T(i) HPyLong_FromSsize_t(HPY_CONTEXT_CNAME, i)

  //Long Type - To
  #define PYOBJECT_LONG_AS_SSIZE(l) HPyLong_AsSsize_t(HPY_CONTEXT_CNAME, l)
  #define PYOBJECT_LONG_AS_UNSIGNED_LONG(l) HPyLong_AsUnsignedLong(HPY_CONTEXT_CNAME, l)

  //Float Type - From
  #define PYOBJECT_FLOAT_FROM_DOUBLE(f) HPyFloat_FromDouble(HPY_CONTEXT_CNAME, f)

  //Float Type - To
  #define PYOBJECT_FLOAT_AS_DOUBLE(f) HPyFloat_AsDouble(HPY_CONTEXT_CNAME, f)

  //Unicode Type - From
  #define PYOBJECT_UNICODE_FROM_STRING(s) HPyUnicode_FromString(HPY_CONTEXT_CNAME, s)
  #define PYOBJECT_UNICODE_FROM_FORMAT(format_str, ...) HPyUnicode_FromFormat(HPY_CONTEXT_CNAME, format_str, __VA_ARGS__)

  //Unicode Type - To

  //Bytes Type - From
  #define BYTES_FROM_STR_AND_SIZE(str, size) HPyBytes_FromStringAndSize(HPY_CONTEXT_CNAME, str, size)

  //Bytes Type - To

  //Dict Type
  #define DICT_NEW() HPyDict_New(HPY_CONTEXT_CNAME)
  #define DICT_COPY(o) HPyDict_Copy(HPY_CONTEXT_CNAME, o)
  #define DICT_CONTAINS(dict, key) HPy_Contains(HPY_CONTEXT_CNAME, dict, key)
  #define DICT_GET_ITEM(o, attr_name) HPyDict_GetItem(HPY_CONTEXT_CNAME, o, attr_name)
  #define DICT_SET_ITEM(o, attr_name, attr_val) HPy_SetItem(HPY_CONTEXT_CNAME, o, attr_name, attr_val)
  #define DICT_GET_ITEM_STR(o, attr_name) HPyDict_GetItem_s(HPY_CONTEXT_CNAME, o, attr_name)
  #define DICT_SET_ITEM_STR(o, attr_name, attr_val) HPy_SetItem_s(HPY_CONTEXT_CNAME, o, attr_name, attr_val)
  #define DICT_GET_ITEM_WITH_ERROR(o, attr_name) HPyDict_GetItem(HPY_CONTEXT_CNAME, o, attr_name)

  //Sequence Type
  #define SEQUENCE_GET_ITEM(h, pos) HPy_GetItem_i(HPY_CONTEXT_CNAME, h, pos)
  #define SEQUENCE_SET_ITEM(h, pos, o) HPy_SetItem_i(HPY_CONTEXT_CNAME, h, pos, o)

  //Tuple Type
  #define TUPLE_CREATE_EMPTY() HPyTuple_FromArray(HPY_CONTEXT_CNAME, NULL, 0)
  #define TUPLE_GET_ITEM(h, pos) HPy_GetItem(HPY_CONTEXT_CNAME, h, PYOBJECT_LONG_FROM_LONG(pos))
  #define TUPLE_GET_ITEM_SAFE(h, pos) HPy_GetItem(HPY_CONTEXT_CNAME, h, PYOBJECT_LONG_FROM_LONG(pos))
  #define TUPLE_GET_SIZE(h) HPy_Length(HPY_CONTEXT_CNAME, h)
  #define TUPLE_GET_SIZE_SAFE(h) HPy_Length(HPY_CONTEXT_CNAME, h)
  #define TUPLE_BUILDER_TYPE HPyTupleBuilder
  #define TUPLE_CREATE_START(target, builder, size) builder = HPyTupleBuilder_New(HPY_CONTEXT_CNAME, size)
  #define TUPLE_CREATE_ASSIGN(tuple, builder, index, item) HPyTupleBuilder_Set(HPY_CONTEXT_CNAME, builder, index, item)
  #define TUPLE_CREATE_FINALISE(target, builder) target = HPyTupleBuilder_Build(HPY_CONTEXT_CNAME, builder);
  #define TUPLE_PACK(num_args, ...) HPyTuple_Pack(HPY_CONTEXT_CNAME, num_args, __VA_ARGS__)

  //List Type
  #define LIST_CREATE_EMPTY() HPyList_New(HPY_CONTEXT_CNAME, 0)
  #define LIST_NEW(i) HPyList_New(HPY_CONTEXT_CNAME, i)
  #define LIST_GET_ITEM(h, pos) HPy_GetItem(HPY_CONTEXT_CNAME, h, PYOBJECT_LONG_FROM_LONG(pos))
  #define LIST_GET_SIZE(h) HPy_Length(HPY_CONTEXT_CNAME, h)
  #define LIST_GET_SIZE_SAFE(h) HPy_Length(HPY_CONTEXT_CNAME, h)
  #define LIST_APPEND(list, h) HPyList_Append(HPY_CONTEXT_CNAME, list, h)
  #define LIST_BUILDER_TYPE HPyListBuilder
  #define LIST_CREATE_START(target, builder, size) builder = HPyListBuilder_New(HPY_CONTEXT_CNAME, size)
  #define LIST_CREATE_ASSIGN(tuple, builder, index, item) HPyListBuilder_Set(HPY_CONTEXT_CNAME, builder, index, item)
  #define LIST_CREATE_FINALISE(target, builder) target = HPyListBuilder_Build(HPY_CONTEXT_CNAME, builder);

  //PyObject/HPy Handle Type
  #define PYOBJECT_GET_ITEM(o, attr_name) HPy_GetItem(HPY_CONTEXT_CNAME, o, attr_name)
  #define PYOBJECT_SET_ITEM(o, attr_name, attr_val) HPy_SetItem(HPY_CONTEXT_CNAME, o, attr_name, attr_val)
  #define PYOBJECT_GET_ATTR(o, attr_name) HPy_GetAttr(HPY_CONTEXT_CNAME, o, attr_name)
  #define PYOBJECT_SET_ATTR(o, attr_name, attr_val) HPy_SetAttr(HPY_CONTEXT_CNAME, o, attr_name, attr_val)
  #define PYOBJECT_GET_ATTR_STR(o, attr_name) HPy_GetAttr_s(HPY_CONTEXT_CNAME, o, attr_name)
  #define PYOBJECT_SET_ATTR_STR(o1, attr_name, o2) HPy_SetAttr_s(HPY_CONTEXT_CNAME, o1, attr_name, o2)
  #define PYOBJECT_HASH(o) HPy_Hash(HPY_CONTEXT_CNAME, o)

  //Type Type
  #define TYPESPEC_TYPE HPyType_Spec
  #define TYPE_FROM_MOD_AND_SPEC(m, s, b) HPyType_FromModuleAndSpec(HPY_CONTEXT_CNAME, m, &s, b)
  #define TYPESPEC_GET(s, field) s.field
  #define TYPE_CHECK(o) HPy_TypeCheck(HPY_CONTEXT_CNAME, (o), HPY_CONTEXT_CNAME->h_TypeType)
  #define TYPE_AS_PYOBJECT(t) t
  #define GET_TYPE(o) HPy_Type(HPY_CONTEXT_CNAME, o)
  #define OBJ_IS_TYPE(o, t) HPy_TypeCheck(HPY_CONTEXT_CNAME, o, t)
  #define TYPE_IS_SUBTYPE(sub, t) HPyType_IsSubtype(HPY_CONTEXT_CNAME, sub, t)

  //Error & Exception Macros
  #define PYERR_OCCURRED() HPyErr_Occurred(HPY_CONTEXT_CNAME)
  #define PYERR_CLEAR() HPyErr_Clear(HPY_CONTEXT_CNAME)
  #define PYERR_EXCEPTIONMATCHES(exc) HPyErr_ExceptionMatches(HPY_CONTEXT_CNAME, (exc))
  #define API_EXC(name) (HPY_CONTEXT_CNAME->h_ ## name)

  //Module Macros
  #define PYMODULEDEF_TYPE HPyModuleDef
  #define PYMODULE_GETDICT_ATTR(mod) HPy_GetAttr_s(HPY_CONTEXT_CNAME, mod, "__dict__")

  //Function Macros
  #define PYMETHODDEF_TYPE HPyDef

#else
  //HPy Context Macros
  #define HPY_CONTEXT_CNAME
  #define HPY_CONTEXT_ONLY_ARG_DEF void
  #define HPY_CONTEXT_ONLY_ARG_CALL
  #define HPY_CONTEXT_FIRST_ARG_DEF
  #define HPY_CONTEXT_FIRST_ARG_CALL

  //Handle/PyObject Macros
  #define PYOBJECT_TYPE PyObject *
  #define PYOBJECT_TYPE_NO_POINTER PyObject
  #define PYTYPEOBJECT_TYPE PyTypeObject *
  #define PYOBJECT_FIELD_TYPE PyObject *
  #define PYOBJECT_FIELD_STORE(owner, field, h) field = h
  #define PYOBJECT_FIELD_LOAD(owner, field) field
  #define PYOBJECT_GLOBAL_TYPE PyObject *
  #define PYTYPEOBJECT_GLOBAL_TYPE PyTypeObject *
  #define PYOBJECT_GLOBAL_STORE(global, h) global = h
  #define PYOBJECT_GLOBAL_LOAD(global) global
  #define CAPI_IS_POINTER * //Some types are sometimes pointers and sometimes not (i.e. PyModuleDef) where the type is always the same in HPy
  #define CAPI_NEEDS_DEREFERENCE &
  #define CAST_IF_CAPI(type) (type)

  //Create New and Close References
  #define PYOBJECT_NEWREF(h) (Py_INCREF(h), h)
  #define PYOBJECT_XNEWREF(h) (Py_XINCREF(h), h)
  #define PYOBJECT_CLOSEREF(h) Py_DECREF(h)
  #define PYOBJECT_XCLOSEREF(h) Py_XDECREF(h)
  #define PYOBJECT_GLOBAL_CLOSEREF(ref) /* nop */
  #define PYOBJECT_CLEAR(h) Py_CLEAR(h)
  #define REFNANNY_CLOSEREF(func, h) func(h)

  //HPy to/from PyObject Functions
  #define HPY_LEGACY_OBJECT_FROM(o) o
  #define HPY_LEGACY_OBJECT_AS(o) o
  #define HPY_LEGACY_OBJECT_ARRAY_AS(o, ssize) o

  //NULL/None Values and functions
  #define API_NULL_VALUE NULL
  #define API_DEFAULT_VALUE 0
  #define API_IS_NULL(h) !h
  #define API_IS_NOT_NULL(h) h
  #define API_NONE_VALUE Py_None
  #define API_ASSIGN_NONE Py_None

  //Boolean Values and Functions
  #define API_TRUE Py_True
  #define API_FALSE Py_False
  #define API_IS_TRUE(h) PyObject_IsTrue(h)
  #define API_IS_FALSE(h) !PyObject_Not(h)

  //General Methods
  #define API_IS_EQUAL(a, b) a==b
  #define API_IS_NOT_EQUAL(a, b) a!=b
  #define API_RICH_COMPARE(h1, h2, op) PyObject_RichCompare(h1, h2, op)
  #define API_RICH_COMPARE_BOOL(h1, h2, op) PyObject_RichCompareBool(h1, h2, op)

  //API Call Macros
  #define API_CALL_FUNC(callable, args, nargs, kwnames) PyObject_Call(callable, args, kwnames)

  //Type Objects
  #define API_LONG_TYPE PyLong_Type
  #define API_SSIZE_T Py_ssize_t
  #define API_STRING_TYPE PyString_Type
  #define API_STRING_TYPE_DEREF &PyString_Type
  #define API_DICT_TYPE PyDict_Type
  #define API_DICT_TYPE_DEREF &PyDict_Type

  //Number Type Checks
  #define LONG_CHECK(l) PyLong_Check(l)
  #define FLOAT_CHECK_EXACT(f) PyFloat_CheckExact(f)
  #define UNICODE_CHECK(u) PyUnicode_Check(u)
  #define DICT_CHECK(o) PyDict_Check(o)
  #define DICT_CHECK_EXACT(o) PyDict_CheckExact(o)
  #define TUPLE_CHECK(o) PyTuple_Check(o)
  #define PYOBJECT_TYPE_CHECK(o, t) PyObject_TypeCheck(o, t)
  #define LIST_CHECK(h) PyList_Check(h)
  #define LIST_CHECK_EXACT(h) PyList_CheckExact(h)


  //Integer Type - From
  #define PYOBJECT_INT_FROM_LONG(i) PyInt_FromLong(i)
  #define PYOBJECT_INT_FROM_UNSIGNED_LONG(i) PyInt_FromUnsignedLong(i)

  //Integer Type - To
  #define PYOBJECT_INT_AS_LONG_NOERROR(l) PyInt_AS_LONG(l)

  //Long Type - From
  #define PYOBJECT_LONG_FROM_LONG(i) PyLong_FromLong(i)
  #define PYOBJECT_LONG_FROM_LONGLONG(i) PyLong_FromLongLong(i)
  #define PYOBJECT_LONG_FROM_UNSIGNED_LONG(i) PyLong_FromUnsignedLong(i)
  #define PYOBJECT_LONG_FROM_UNSIGNED_LONGLONG(i) PyLong_FromUnsignedLongLong(i)
  #define PYOBJECT_LONG_FROM_SSIZE_T(i) PyLong_FromSsize_t(i)

  //Long Type - To
  #define PYOBJECT_LONG_AS_SSIZE(l) PyLong_AsSsize_t(l)
  #define PYOBJECT_LONG_AS_UNSIGNED_LONG(l) PyLong_AsUnsignedLong(l)

  //Float Type - From
  #define PYOBJECT_FLOAT_FROM_DOUBLE(f) PyFloat_FromDouble(f)

  //Float Type - To
  #define PYOBJECT_FLOAT_AS_DOUBLE(f) PyFloat_AsDouble(f)

  //Unicode Type - From
  #define PYOBJECT_UNICODE_FROM_STRING(s) PyUnicode_FromString(s)
  #define PYOBJECT_UNICODE_FROM_FORMAT(format_str, ...) PyUnicode_FromFormat(format_str, __VA_ARGS__)

  //Unicode Type - To

  //Bytes Type - From
  #define BYTES_FROM_STR_AND_SIZE(str, size) PyBytes_FromStringAndSize(str, size)

  //Bytes Type - To

  //Dict Type
  #define DICT_NEW() PyDict_New()
  #define DICT_COPY(o) PyDict_Copy(o)
  #define DICT_CONTAINS(o, key) PyDict_Contains(o, key)
  #define DICT_GET_ITEM(o, attr_name) PyDict_GetItem(o, attr_name)
  #define DICT_SET_ITEM(o, attr_name, attr_val) PyDict_SetItem(o, attr_name, attr_val)
  #define DICT_GET_ITEM_STR(o, attr_name) PyDict_GetItemString(o, attr_name)
  #define DICT_SET_ITEM_STR(o, attr_name, attr_val) PyDict_SetItemString(o, attr_name, attr_val)
  #define DICT_GET_ITEM_WITH_ERROR(o, attr_name) PyDict_GetItemWithError(o, attr_name)

  //Sequence Type
  #define SEQUENCE_GET_ITEM(h, pos) __Pyx_PySequence_ITEM(h, pos)
  #define SEQUENCE_SET_ITEM(h, pos, o) PySequence_SetItem(h, pos, o)

  //Tuple Type
  #define TUPLE_CREATE_EMPTY() PyTuple_New(0)
  #define TUPLE_GET_ITEM(h, pos) __Pyx_PySequence_ITEM(h, pos)
  #define TUPLE_GET_ITEM_SAFE(h, pos) PyTuple_GetItem(h, pos)
  #define TUPLE_GET_SIZE(h) PyTuple_GET_SIZE(h)
  #define TUPLE_GET_SIZE_SAFE(h) PyTuple_Size(h)
  #define TUPLE_BUILDER_TYPE PyObject * //Not used, just needed to prevent errors
  #define TUPLE_CREATE_START(target, builder, size) target=PyTuple_New(size)
  #define TUPLE_CREATE_ASSIGN(tuple, builder, index, item) __Pyx_PyTuple_SET_ITEM(tuple, index, item)
  #define TUPLE_CREATE_FINALISE(target, null)
  #define TUPLE_PACK(num_args, ...) PyTuple_Pack(num_args, __VA_ARGS__)

  //List Type
  #define LIST_CREATE_EMPTY() PyList_New(0)
  #define LIST_NEW(i) PyList_New(i)
  #define LIST_GET_ITEM(h, pos) __Pyx_PySequence_ITEM(HPY_CONTEXT_CNAME, h, pos)
  #define LIST_APPEND(list, h) PyList_Append(list, h)
  #define LIST_GET_SIZE(h) PyList_GET_SIZE(h)
  #define LIST_GET_SIZE_SAFE(h) PyList_Size(h)
  #define LIST_BUILDER_TYPE PyObject * //Not used, just needed to prevent errors
  #define LIST_CREATE_START(target, builder, size) target=PyList_New(size)
  #define LIST_CREATE_ASSIGN(tuple, builder, index, item) __Pyx_PyList_SET_ITEM(tuple, index, item)
  #define LIST_CREATE_FINALISE(target, null)

  //PyObject/HPy Handle Type
  #define PYOBJECT_GET_ITEM(o, attr_name) PyObject_GetItem(o, attr_name)
  #define PYOBJECT_SET_ITEM(o, attr_name, attr_val) PyObject_SetItem(o, attr_name, attr_val)
  #define PYOBJECT_GET_ATTR(o, attr_name) PyObject_GetAttr(o, attr_name)
  #define PYOBJECT_SET_ATTR(o, attr_name, attr_val) PyObject_SetAttr(o, attr_name, attr_val)
  #define PYOBJECT_GET_ATTR_STR(o, attr_name) PyObject_GetAttrString(o, attr_name)
  #define PYOBJECT_SET_ATTR_STR(o1, attr_name, o2) PyObject_SetAttrString(o1, attr_name, o2)
  #define PYOBJECT_HASH(o) PyObject_Hash(o)

  //Type Type
  #define TYPESPEC_TYPE PyType_Spec
  #define TYPE_FROM_MOD_AND_SPEC(m, s, b) PyType_FromModuleAndSpec(m, s, b)
  #define TYPESPEC_GET(s, field) s->field
  #define TYPE_CHECK(o) PyType_Check(o)
  #define TYPE_AS_PYOBJECT(t) (PyObject*)&##t
  #define GET_TYPE(o) Py_TYPE(o)
  #define OBJ_IS_TYPE(o, t) Py_IS_TYPE(o, t)
  #define TYPE_IS_SUBTYPE(sub, t) PyType_IsSubtype(sub, t)

  //Error & Exception Macros
  #define PYERR_OCCURRED() (!!PyErr_Occurred())
  #define PYERR_CLEAR() PyErr_Clear()
  #define PYERR_EXCEPTIONMATCHES(exc) PyErr_ExceptionMatches((exc))
  #define API_EXC(name) (PyExc_ ## name)

  //Module Macros
  #define PYMODULEDEF_TYPE struct PyModuleDef
  #define PYMODULE_GETDICT_ATTR(mod) PyModule_GetDict(mod)

  //Function Macros
  #define PYMETHODDEF_TYPE PyMethodDef

#endif

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

static CYTHON_INLINE HPy HPyDict_GetItem(HPyContext *ctx, HPy mp, HPy key)
{
    HPy res = HPy_GetItem(ctx, mp, key);
    if (HPy_IsNull(res)) {
        HPyErr_Clear(ctx);
    }
    return res;
}

static CYTHON_INLINE HPy HPyDict_GetItem_s(HPyContext *ctx, HPy mp, const char *key)
{
    HPy res = HPy_GetItem_s(ctx, mp, key);
    if (HPy_IsNull(res)) {
        HPyErr_Clear(ctx);
    }
    return res;
}

#endif
