#include <Python.h>

#define SWORD_METHODS_END_STATIC { NULL, NULL, 0, NULL }

static PyObject* print_message(PyObject* self, PyObject* args)
{
    const char* str_arg;
    if(!PyArg_ParseTuple(args, "s", &str_arg)) {
        puts("Could not parse the python arg!");
        return NULL;
    }
    Py_INCREF(Py_None);
    return Py_None;
}

static PyMethodDef swordsMethods[] = {
    { "print_message", print_message, METH_VARARGS, "Prints a called string" },
    SWORD_METHODS_END_STATIC
};

// Our Module Definition struct
static struct PyModuleDef swordModule = {
    PyModuleDef_HEAD_INIT,
    "DemoPackage",
    "A demo module for python c extensions",
    -1,
    swordMethods
};

// Initializes our module using our above struct
PyMODINIT_FUNC PyInit_sword(void)
{
    return PyModule_Create(&swordModule);
}