#define Py_LIMITED_API
#include <Python.h>

PyObject * Sum(PyObject *, PyObject *);
PyObject * Tick(PyObject *, PyObject *);

// Workaround missing variadic function support
// https://github.com/golang/go/issues/975
int PyArg_ParseTuple_LL(PyObject * args, long long * a, long long * b) {
    return PyArg_ParseTuple(args, "LL", a, b);
}

static PyMethodDef MyMethods[] = {
    {"Sum", Sum, METH_VARARGS, "Add two numbers."},
	{"Tick", Tick, METH_VARARGS, "Tick time"},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef MyModule = {
   PyModuleDef_HEAD_INIT, "foo", NULL, -1, FooMethods
};

PyMODINIT_FUNC
PyInit_foo(void)
{
    return PyModule_Create(&MyModule);
}
