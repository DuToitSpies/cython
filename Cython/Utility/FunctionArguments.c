//////////////////// ArgTypeTest.proto ////////////////////


// Exact is 0 (False), 1 (True) or 2 (True and from annotation)
// The latter gives a small amount of extra error diagnostics
#define __Pyx_ArgTypeTest(obj, type, none_allowed, name, exact) \
    ((likely(OBJ_IS_TYPE(obj, type) | (none_allowed && (API_IS_EQUAL(obj, API_NONE_VALUE))))) ? 1 : \
        __Pyx__ArgTypeTest(HPY_CONTEXT_FIRST_ARG_CALL obj, type, name, exact))

static int __Pyx__ArgTypeTest(HPY_CONTEXT_FIRST_ARG_DEF PYOBJECT_TYPE obj, PYTYPEOBJECT_TYPE type, const char *name, int exact); /*proto*/

//////////////////// ArgTypeTest ////////////////////
//@substitute: naming

static int __Pyx__ArgTypeTest(HPY_CONTEXT_FIRST_ARG_DEF PYOBJECT_TYPE obj, PYTYPEOBJECT_TYPE type, const char *name, int exact)
{
    __Pyx_TypeName type_name;
    __Pyx_TypeName obj_type_name;
    PYOBJECT_TYPE extra_info = PYOBJECT_GLOBAL_LOAD($empty_unicode);
    int from_annotation_subclass = 0;
    if (unlikely(API_IS_NULL(type))) {
        PyErr_SetString(PyExc_SystemError, "Missing type object");
        return 0;
    }
    else if (!exact) {
        if (likely(__Pyx_TypeCheck(obj, type))) return 1;
    } else if (exact == 2) {
        // type from annotation
        if (__Pyx_TypeCheck(obj, type)) {
            from_annotation_subclass = 1;
            extra_info = PYOBJECT_GLOBAL_LOAD(PYUNICODE("Note that Cython is deliberately stricter than PEP-484 and rejects subclasses of builtin types. If you need to pass subclasses then set the 'annotation_typing' directive to False."));
        }
    }
    type_name = __Pyx_PyType_GetName(HPY_CONTEXT_FIRST_ARG_CALL type);
    obj_type_name = __Pyx_PyType_GetName(HPY_CONTEXT_FIRST_ARG_CALL GET_TYPE(obj));
    PyErr_Format(PyExc_TypeError,
        "Argument '%.200s' has incorrect type (expected " __Pyx_FMT_TYPENAME
        ", got " __Pyx_FMT_TYPENAME ")"
#if __PYX_LIMITED_VERSION_HEX < 0x030C0000
        "%s%U"
#endif
        , name, type_name, obj_type_name
#if __PYX_LIMITED_VERSION_HEX < 0x030C0000
        , (from_annotation_subclass ? ". " : ""), extra_info
#endif
        );
#if __PYX_LIMITED_VERSION_HEX >= 0x030C0000
    // Set the extra_info as a note instead. In principle it'd be possible to do this
    // from Python 3.11 up, but PyErr_GetRaisedException makes it much easier so do it
    // from Python 3.12 instead.
    if (exact == 2 && from_annotation_subclass) {
        PyObject *res;
        PyObject *vargs[2];
        vargs[0] = PyErr_GetRaisedException();
        vargs[1] = extra_info;
        res = PyObject_VectorcallMethod(PYUNICODE("add_note"), vargs, 2, NULL);
        Py_XDECREF(res);
        PyErr_SetRaisedException(vargs[0]);
    }
#endif
    __Pyx_DECREF_TypeName(type_name);
    __Pyx_DECREF_TypeName(obj_type_name);
    PYOBJECT_GLOBAL_CLOSEREF(extra_info);
    return 0;
}

//////////////////// RaiseArgTupleInvalid.proto ////////////////////

static void __Pyx_RaiseArgtupleInvalid(const char* func_name, int exact,
    Py_ssize_t num_min, Py_ssize_t num_max, Py_ssize_t num_found); /*proto*/

//////////////////// RaiseArgTupleInvalid ////////////////////

//  __Pyx_RaiseArgtupleInvalid raises the correct exception when too
//  many or too few positional arguments were found.  This handles
//  Py_ssize_t formatting correctly.

static void __Pyx_RaiseArgtupleInvalid(
    const char* func_name,
    int exact,
    Py_ssize_t num_min,
    Py_ssize_t num_max,
    Py_ssize_t num_found)
{
    Py_ssize_t num_expected;
    const char *more_or_less;

    if (num_found < num_min) {
        num_expected = num_min;
        more_or_less = "at least";
    } else {
        num_expected = num_max;
        more_or_less = "at most";
    }
    if (exact) {
        more_or_less = "exactly";
    }
    PyErr_Format(PyExc_TypeError,
                 "%.200s() takes %.8s %" CYTHON_FORMAT_SSIZE_T "d positional argument%.1s (%" CYTHON_FORMAT_SSIZE_T "d given)",
                 func_name, more_or_less, num_expected,
                 (num_expected == 1) ? "" : "s", num_found);
}


//////////////////// RaiseKeywordRequired.proto ////////////////////

static void __Pyx_RaiseKeywordRequired(const char* func_name, PyObject* kw_name); /*proto*/

//////////////////// RaiseKeywordRequired ////////////////////

static void __Pyx_RaiseKeywordRequired(const char* func_name, PyObject* kw_name) {
    PyErr_Format(PyExc_TypeError,
        "%s() needs keyword-only argument %U", func_name, kw_name);
}


//////////////////// RaiseDoubleKeywords.proto ////////////////////

static void __Pyx_RaiseDoubleKeywordsError(const char* func_name, PyObject* kw_name); /*proto*/

//////////////////// RaiseDoubleKeywords ////////////////////

static void __Pyx_RaiseDoubleKeywordsError(
    const char* func_name,
    PyObject* kw_name)
{
    PyErr_Format(PyExc_TypeError,
        "%s() got multiple values for keyword argument '%U'", func_name, kw_name);
}


//////////////////// RaiseMappingExpected.proto ////////////////////

static void __Pyx_RaiseMappingExpectedError(PyObject* arg); /*proto*/

//////////////////// RaiseMappingExpected ////////////////////

static void __Pyx_RaiseMappingExpectedError(PyObject* arg) {
    __Pyx_TypeName arg_type_name = __Pyx_PyType_GetName(Py_TYPE(arg));
    PyErr_Format(PyExc_TypeError,
        "'" __Pyx_FMT_TYPENAME "' object is not a mapping", arg_type_name);
    __Pyx_DECREF_TypeName(arg_type_name);
}


//////////////////// KeywordStringCheck.proto ////////////////////

static int __Pyx_CheckKeywordStrings(HPY_CONTEXT_FIRST_ARG_DEF PYOBJECT_TYPE kw, const char* function_name, int kw_allowed); /*proto*/

//////////////////// KeywordStringCheck ////////////////////

// __Pyx_CheckKeywordStrings raises an error if non-string keywords
// were passed to a function, or if any keywords were passed to a
// function that does not accept them.
//
// The "kw" argument is either a dict (for METH_VARARGS) or a tuple
// (for METH_FASTCALL).

static int __Pyx_CheckKeywordStrings(
    HPY_CONTEXT_FIRST_ARG_DEF
    PYOBJECT_TYPE kw,
    const char* function_name,
    int kw_allowed)
{
    PYOBJECT_TYPE key = API_DEFAULT_VALUE;
    API_SSIZE_T pos = 0;
#if CYTHON_COMPILING_IN_PYPY
    /* PyPy appears to check keywords at call time, not at unpacking time => not much to do here */
    if (!kw_allowed && PyDict_Next(kw, &pos, &key, 0))
        goto invalid_keyword;
    return 1;
#else
    if (CYTHON_METH_FASTCALL && likely(TUPLE_CHECK(kw))) {
        API_SSIZE_T kwsize;
#if CYTHON_ASSUME_SAFE_SIZE
        kwsize = PyTuple_GET_SIZE(kw);
#else
        kwsize = TUPLE_GET_SIZE(kw);
        if (kwsize < 0) return 0;
#endif
        if (unlikely(kwsize == 0))
            return 1;
        if (!kw_allowed) {
#if CYTHON_ASSUME_SAFE_MACROS
            key = PyTuple_GET_ITEM(kw, 0);
#else
            key = TUPLE_GET_ITEM(kw, pos);
            if (API_IS_NULL(key)) return 0;
#endif
            goto invalid_keyword;
        }
#if PY_VERSION_HEX < 0x03090000
        // On CPython >= 3.9, the FASTCALL protocol guarantees that keyword
        // names are strings (see https://bugs.python.org/issue37540)
        for (pos = 0; pos < kwsize; pos++) {
#if CYTHON_ASSUME_SAFE_MACROS
            key = PyTuple_GET_ITEM(kw, pos);
#else
            key = TUPLE_GET_ITEM(kw, pos);
            if (API_IS_NULL(key)) return 0;
#endif
            if (unlikely(!UNICODE_CHECK(key)))
                goto invalid_keyword_type;
        }
#endif
        return 1;
    }

    PyObject *legacy_key = NULL;

    while (PyDict_Next(HPY_LEGACY_OBJECT_AS(kw), &pos, &legacy_key, 0)) {
        if (unlikely(!UNICODE_CHECK(key)))
            goto invalid_keyword_type;
    }
    if (!kw_allowed && unlikely(API_IS_NOT_NULL(key)))
        goto invalid_keyword;
    return 1;
invalid_keyword_type:
    PyErr_Format(PyExc_TypeError,
        "%.200s() keywords must be strings", function_name);
    return 0;
#endif
invalid_keyword:
    PyErr_Format(PyExc_TypeError,
        "%s() got an unexpected keyword argument '%U'",
        function_name, key);
    return 0;
}


//////////////////// ParseKeywords.proto ////////////////////

static int __Pyx_ParseOptionalKeywords(PyObject *kwds, PyObject *const *kwvalues,
    PyObject **argnames[],
    PyObject *kwds2, PyObject *values[], Py_ssize_t num_pos_args,
    const char* function_name); /*proto*/

//////////////////// ParseKeywords ////////////////////
//@requires: RaiseDoubleKeywords

//  __Pyx_ParseOptionalKeywords copies the optional/unknown keyword
//  arguments from kwds into the dict kwds2.  If kwds2 is NULL, unknown
//  keywords will raise an invalid keyword error.
//
//  When not using METH_FASTCALL, kwds is a dict and kwvalues is NULL.
//  Otherwise, kwds is a tuple with keyword names and kwvalues is a C
//  array with the corresponding values.
//
//  Three kinds of errors are checked: 1) non-string keywords, 2)
//  unexpected keywords and 3) overlap with positional arguments.
//
//  If num_posargs is greater 0, it denotes the number of positional
//  arguments that were passed and that must therefore not appear
//  amongst the keywords as well.
//
//  This method does not check for required keyword arguments.

static int __Pyx_ParseOptionalKeywords(
    PyObject *kwds,
    PyObject *const *kwvalues,
    PyObject **argnames[],
    PyObject *kwds2,
    PyObject *values[],
    Py_ssize_t num_pos_args,
    const char* function_name)
{
    PyObject *key = 0, *value = 0;
    Py_ssize_t pos = 0;
    PyObject*** name;
    PyObject*** first_kw_arg = argnames + num_pos_args;
    int kwds_is_tuple = CYTHON_METH_FASTCALL && likely(PyTuple_Check(kwds));

    while (1) {
        // clean up key and value when the loop is "continued"
        Py_XDECREF(key); key = NULL;
        Py_XDECREF(value); value = NULL;

        if (kwds_is_tuple) {
            Py_ssize_t size;
#if CYTHON_ASSUME_SAFE_SIZE
            size = PyTuple_GET_SIZE(kwds);
#else
            size = PyTuple_Size(kwds);
            if (size < 0) goto bad;
#endif
            if (pos >= size) break;

#if CYTHON_AVOID_BORROWED_REFS
            // Get an owned reference to key.
            key = __Pyx_PySequence_ITEM(kwds, pos);
            if (!key) goto bad;
#elif CYTHON_ASSUME_SAFE_MACROS
            key = PyTuple_GET_ITEM(kwds, pos);
#else
            key = PyTuple_GetItem(kwds, pos);
            if (!key) goto bad;
#endif

            value = kwvalues[pos];
            pos++;
        }
        else
        {
            if (!PyDict_Next(kwds, &pos, &key, &value)) break;
            // It's unfortunately hard to avoid borrowed references (briefly) with PyDict_Next
#if CYTHON_AVOID_BORROWED_REFS
            // Own the reference to match the behaviour above.
            Py_INCREF(key);
#endif
        }

        name = first_kw_arg;
        while (*name && (**name != key)) name++;
        if (*name) {
            values[name-argnames] = value;
#if CYTHON_AVOID_BORROWED_REFS
            Py_INCREF(value);  /* transfer ownership of value to values */
            Py_DECREF(key);
#endif
            key = NULL;
            value = NULL;
            continue;
        }

        // Now make sure we own both references since we're doing non-trivial Python operations.
#if !CYTHON_AVOID_BORROWED_REFS
        Py_INCREF(key);
#endif
        Py_INCREF(value);

        name = first_kw_arg;
        if (likely(PyUnicode_Check(key))) {
            while (*name) {
                int cmp = (
                #if CYTHON_ASSUME_SAFE_SIZE
                    (PyUnicode_GET_LENGTH(**name) != PyUnicode_GET_LENGTH(key)) ? 1 :
                #endif
                    PyUnicode_Compare(**name, key)
                );
                if (cmp < 0 && unlikely(PyErr_Occurred())) goto bad;
                if (cmp == 0) {
                    values[name-argnames] = value;
#if CYTHON_AVOID_BORROWED_REFS
                    value = NULL;  /* ownership transferred to values */
#endif
                    break;
                }
                name++;
            }
            if (*name) continue;
            else {
                // not found after positional args, check for duplicate
                PyObject*** argname = argnames;
                while (argname != first_kw_arg) {
                    int cmp = (**argname == key) ? 0 :
                    #if CYTHON_ASSUME_SAFE_SIZE
                        (PyUnicode_GET_LENGTH(**argname) != PyUnicode_GET_LENGTH(key)) ? 1 :
                    #endif
                        // need to convert argument name from bytes to unicode for comparison
                        PyUnicode_Compare(**argname, key);
                    if (cmp < 0 && unlikely(PyErr_Occurred())) goto bad;
                    if (cmp == 0) goto arg_passed_twice;
                    argname++;
                }
            }
        } else
            goto invalid_keyword_type;

        if (kwds2) {
            if (unlikely(PyDict_SetItem(kwds2, key, value))) goto bad;
        } else {
            goto invalid_keyword;
        }
    }
    Py_XDECREF(key);
    Py_XDECREF(value);
    return 0;
arg_passed_twice:
    __Pyx_RaiseDoubleKeywordsError(function_name, key);
    goto bad;
invalid_keyword_type:
    PyErr_Format(PyExc_TypeError,
        "%.200s() keywords must be strings", function_name);
    goto bad;
invalid_keyword:
    PyErr_Format(PyExc_TypeError,
        "%s() got an unexpected keyword argument '%U'",
        function_name, key);
bad:
    Py_XDECREF(key);
    Py_XDECREF(value);
    return -1;
}


//////////////////// MergeKeywords.proto ////////////////////

static int __Pyx_MergeKeywords(HPY_CONTEXT_FIRST_ARG_DEF PYOBJECT_TYPE kwdict, PYOBJECT_TYPE source_mapping); /*proto*/

//////////////////// MergeKeywords ////////////////////
//@requires: RaiseDoubleKeywords
//@requires: Optimize.c::dict_iter

static int __Pyx_MergeKeywords(HPY_CONTEXT_FIRST_ARG_DEF PYOBJECT_TYPE kwdict, PYOBJECT_TYPE source_mapping) {
    PYOBJECT_TYPE iter, CAPI_IS_POINTER key = API_NULL_VALUE, CAPI_IS_POINTER value = API_NULL_VALUE;
    int source_is_dict, result;
    API_SSIZE_T orig_length, ppos = 0;
    PYOBJECT_TYPE items_loader = HPY_LEGACY_OBJECT_AS(PYIDENT("items"));

    iter = HPY_LEGACY_OBJECT_FROM(__Pyx_dict_iterator(HPY_LEGACY_OBJECT_AS(source_mapping), 0, HPY_LEGACY_OBJECT_AS(items_loader), &orig_length, &source_is_dict));
    if (unlikely(API_IS_NULL(iter))) {
        // slow fallback: try converting to dict, then iterate
        PYOBJECT_TYPE args;
        if (unlikely(!PyErr_ExceptionMatches(PyExc_AttributeError))) goto bad;
        PyErr_Clear();
        args = TUPLE_PACK(1, source_mapping);
        if (likely(API_IS_NOT_NULL(args))) {
#if CYTHON_USING_HPY
            PYOBJECT_TYPE fallback = API_CALL_FUNC(HPY_CONTEXT_CNAME->h_DictType, args, 0, NULL);
#else
            PYOBJECT_TYPE fallback = API_CALL_FUNC((PyObject*)&PyDict_Type, args, 0, NULL);
#endif
            PYOBJECT_CLOSEREF(args);
            if (likely(API_IS_NOT_NULL(fallback))) {
                iter = __Pyx_dict_iterator(HPY_LEGACY_OBJECT_AS(fallback), 1, HPY_LEGACY_OBJECT_AS(items_loader), &orig_length, &source_is_dict);
                PYOBJECT_CLOSEREF(fallback);
            }
        }
        if (unlikely(API_IS_NULL(iter))) goto bad;
    }

    while (1) {
        result = __Pyx_dict_iter_next(HPY_LEGACY_OBJECT_AS(iter), orig_length, &ppos, &HPY_LEGACY_OBJECT_AS(key), &HPY_LEGACY_OBJECT_AS(value), API_NULL_VALUE, source_is_dict);
        if (unlikely(result < 0)) goto bad;
        if (!result) break;

        if (unlikely(DICT_CONTAINS(kwdict, key))) {
            __Pyx_RaiseDoubleKeywordsError("function", HPY_LEGACY_OBJECT_AS(key));
            result = -1;
        } else {
            result = DICT_SET_ITEM(kwdict, key, value);
        }
        PYOBJECT_CLOSEREF(key);
        PYOBJECT_CLOSEREF(value);
        if (unlikely(result < 0)) goto bad;
    }
    PYOBJECT_XCLOSEREF(iter);
    PYOBJECT_CLOSEREF(items_loader);
    return 0;

bad:
    Py_XDECREF(iter);
    PYOBJECT_CLOSEREF(items_loader);
    return -1;
}


/////////////// fastcall.proto ///////////////

// We define various functions and macros with two variants:
//..._FASTCALL and ..._VARARGS

// The first is used when METH_FASTCALL is enabled and the second is used
// otherwise. If the Python implementation does not support METH_FASTCALL
// (because it's an old version of CPython or it's not CPython at all),
// then the ..._FASTCALL macros simply alias ..._VARARGS

#if CYTHON_AVOID_BORROWED_REFS
    // This is the only case where we request an owned reference.
    #define __Pyx_Arg_VARARGS(args, i) SEQUENCE_GET_ITEM(args, i)
#elif CYTHON_ASSUME_SAFE_MACROS
    #define __Pyx_Arg_VARARGS(args, i) PyTuple_GET_ITEM(args, i)
#else
    #define __Pyx_Arg_VARARGS(args, i) PyTuple_GetItem(args, i)
#endif
#if CYTHON_AVOID_BORROWED_REFS
    #define __Pyx_Arg_NewRef_VARARGS(arg) __Pyx_NewRef(arg)
    #define __Pyx_Arg_XDECREF_VARARGS(arg) Py_XDECREF(arg)
#else
    #define __Pyx_Arg_NewRef_VARARGS(arg) arg  /* no-op */
    #define __Pyx_Arg_XDECREF_VARARGS(arg)     /* no-op - arg is borrowed */
#endif
#define __Pyx_NumKwargs_VARARGS(kwds) DICT_GET_SIZE(kwds)
#define __Pyx_KwValues_VARARGS(args, nargs) NULL
#define __Pyx_GetKwValue_VARARGS(kw, kwvalues, s) __Pyx_PyDict_GetItemStrWithError(kw, s)
#define __Pyx_KwargsAsDict_VARARGS(kw, kwvalues) DICT_COPY(kw)
#if CYTHON_METH_FASTCALL
    #define __Pyx_Arg_FASTCALL(args, i) args[i]
    #define __Pyx_NumKwargs_FASTCALL(kwds) TUPLE_GET_SIZE(kwds)
    #define __Pyx_KwValues_FASTCALL(args, nargs) ((args) + (nargs))
    static CYTHON_INLINE PYOBJECT_TYPE __Pyx_GetKwValue_FASTCALL(HPY_CONTEXT_FIRST_ARG_DEF PYOBJECT_TYPE kwnames, PYOBJECT_TYPE const *kwvalues, PYOBJECT_TYPE s);
  #if CYTHON_COMPILING_IN_CPYTHON && PY_VERSION_HEX >= 0x030d0000
    CYTHON_UNUSED static PyObject *__Pyx_KwargsAsDict_FASTCALL(PyObject *kwnames, PyObject *const *kwvalues);/*proto*/
  #else
    #define __Pyx_KwargsAsDict_FASTCALL(kw, kwvalues) _PyStack_AsDict(kwvalues, kw)
  #endif
    #define __Pyx_Arg_NewRef_FASTCALL(arg) arg  /* no-op, __Pyx_Arg_FASTCALL is direct and this needs
                                                   to have the same reference counting */
    #define __Pyx_Arg_XDECREF_FASTCALL(arg)     /* no-op - arg was returned from array */
#else
    #define __Pyx_Arg_FASTCALL __Pyx_Arg_VARARGS
    #define __Pyx_NumKwargs_FASTCALL __Pyx_NumKwargs_VARARGS
    #define __Pyx_KwValues_FASTCALL __Pyx_KwValues_VARARGS
    #define __Pyx_GetKwValue_FASTCALL __Pyx_GetKwValue_VARARGS
    #define __Pyx_KwargsAsDict_FASTCALL __Pyx_KwargsAsDict_VARARGS
    #define __Pyx_Arg_NewRef_FASTCALL(arg) __Pyx_Arg_NewRef_VARARGS(arg)
    #define __Pyx_Arg_XDECREF_FASTCALL(arg) __Pyx_Arg_XDECREF_VARARGS(arg)
#endif

#if CYTHON_COMPILING_IN_CPYTHON && CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
#define __Pyx_ArgsSlice_VARARGS(args, start, stop) __Pyx_PyTuple_FromArray(HPY_CONTEXT_FIRST_ARG_CALL &__Pyx_Arg_VARARGS(args, start), stop - start)
#define __Pyx_ArgsSlice_FASTCALL(args, start, stop) __Pyx_PyTuple_FromArray(HPY_CONTEXT_FIRST_ARG_CALL &__Pyx_Arg_FASTCALL(args, start), stop - start)
#else
/* Not CPython, so certainly no METH_FASTCALL support */
#define __Pyx_ArgsSlice_VARARGS(args, start, stop) PyTuple_GetSlice(args, start, stop)
#define __Pyx_ArgsSlice_FASTCALL(args, start, stop) PyTuple_GetSlice(args, start, stop)
#endif


/////////////// fastcall ///////////////
//@requires: ObjectHandling.c::TupleAndListFromArray
//@requires: StringTools.c::UnicodeEquals

#if CYTHON_METH_FASTCALL
// kwnames: tuple with names of keyword arguments
// kwvalues: C array with values of keyword arguments
// s: str with the keyword name to look for
static CYTHON_INLINE PYOBJECT_TYPE __Pyx_GetKwValue_FASTCALL(HPY_CONTEXT_FIRST_ARG_DEF PYOBJECT_TYPE kwnames, PYOBJECT_TYPE const *kwvalues, PYOBJECT_TYPE s)
{
    // Search the kwnames array for s and return the corresponding value.
    // We do two loops: a first one to compare pointers (which will find a
    // match if the name in kwnames is interned, given that s is interned
    // by Cython). A second loop compares the actual strings.
    API_SSIZE_T i, n = TUPLE_GET_SIZE(kwnames);
    for (i = 0; i < n; i++)
    {
        if (API_IS_EQUAL(s, TUPLE_GET_ITEM(kwnames, i))) return kwvalues[i];
    }
    for (i = 0; i < n; i++)
    {
        int eq = __Pyx_PyUnicode_Equals(HPY_CONTEXT_FIRST_ARG_CALL s, TUPLE_GET_ITEM(kwnames, i), Py_EQ);
        if (unlikely(eq != 0)) {
            if (unlikely(eq < 0)) return API_NULL_VALUE;  /* error */
            return kwvalues[i];
        }
    }
    return API_NULL_VALUE;  /* not found (no exception set) */
}

#if CYTHON_COMPILING_IN_CPYTHON && PY_VERSION_HEX >= 0x030d0000
CYTHON_UNUSED static PyObject *__Pyx_KwargsAsDict_FASTCALL(PyObject *kwnames, PyObject *const *kwvalues) {
    Py_ssize_t i, nkwargs = PyTuple_GET_SIZE(kwnames);
    PyObject *dict;

    dict = PyDict_New();
    if (unlikely(!dict))
        return NULL;

    for (i=0; i<nkwargs; i++) {
        PyObject *key = PyTuple_GET_ITEM(kwnames, i);
        if (unlikely(PyDict_SetItem(dict, key, kwvalues[i]) < 0))
            goto bad;
    }
    return dict;

bad:
    Py_DECREF(dict);
    return NULL;
}
#endif

#endif
