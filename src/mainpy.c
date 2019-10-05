#include <Python.h>
#include "sword_csv_count.h"

#define SWORD_METHODS_END_STATIC { NULL, NULL, 0, NULL }

static PyObject* csv_count_rows(PyObject* self, PyObject* args)
{
    const char* str_arg;
    long counted_rows;
    if(!PyArg_ParseTuple(args, "s", &str_arg)) {
        puts("Could not parse the python arg!");
        return NULL;
    }
    counted_rows = sword_csv_count_rows(str_arg);
    return PyLong_FromLong(counted_rows);
}

static PyMethodDef swordMethods[] = {
    { "csv_count_rows", csv_count_rows, METH_VARARGS, "Counts the rows in a CSV string." },
    SWORD_METHODS_END_STATIC
};

// Our Module Definition struct
static struct PyModuleDef swordModule = {
    PyModuleDef_HEAD_INIT,
    "sword",
    "A fast and effecient data mining C extension.",
    -1,
    swordMethods
};

// Initializes our module using our above struct
PyMODINIT_FUNC PyInit_sword(void)
{
    return PyModule_Create(&swordModule);
}