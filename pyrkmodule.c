#include <Python.h>

#include "pyrk.h"

static PyObject *Pyrk_getpowhash(PyObject *self, PyObject *args)
{
    char *output;
    PyObject *value;
#if PY_MAJOR_VERSION >= 3
    PyBytesObject *input;
#else
    PyStringObject *input;
#endif
    if (!PyArg_ParseTuple(args, "S", &input))
        return NULL;
    Py_INCREF(input);
    output = PyMem_Malloc(32);

#if PY_MAJOR_VERSION >= 3
    pyrk_multialgo((char *)PyBytes_AsString((PyObject*) input), output);
#else
    pyrk_multialgo((char *)PyString_AsString((PyObject*) input), output);
#endif
    Py_DECREF(input);
#if PY_MAJOR_VERSION >= 3
    value = Py_BuildValue("y#", output, 32);
#else
    value = Py_BuildValue("s#", output, 32);
#endif
    PyMem_Free(output);
    return value;
}

static PyMethodDef PyrkMethods[] = {
    { "getPoWHash", Pyrk_getpowhash, METH_VARARGS, "Returns the proof of work hash using Pyrk's multialgorithm hash" },
    { NULL, NULL, 0, NULL }
};

#if PY_MAJOR_VERSION >= 3
static struct PyModuleDef PyrkModule = {
    PyModuleDef_HEAD_INIT,
    "pyrk_hash",
    "...",
    -1,
    PyrkMethods
};

PyMODINIT_FUNC PyInit_pyrk_hash(void) {
    return PyModule_Create(&PyrkModule);
}

#else

PyMODINIT_FUNC initpyrk_multialgo(void) {
    (void) Py_InitModule("pyrk_multialgo", PyrkMethods);
}
#endif
