#include <Python.h>
#include "sword_csv_count.h"
#include "sword_csv_read.h"

#define SWORD_METHODS_END_STATIC { NULL, NULL, 0, NULL }

static PyObject* csv_count_rows(PyObject* self, PyObject* args)
{
    const char* str_arg;
    long counted_rows;
    if(!PyArg_ParseTuple(args, "s", &str_arg)) {
        return NULL;
    }
    counted_rows = sword_csv_count_rows(str_arg);
    return PyLong_FromLong(counted_rows);
}

static PyObject* csv_count_cols(PyObject* self, PyObject* args)
{
    const char* str_arg;
    long counted_cols;
    if(!PyArg_ParseTuple(args, "s", &str_arg)) {
        return NULL;
    }
    counted_cols = sword_csv_count_cols(str_arg);
    return PyLong_FromLong(counted_cols);
}

static PyMethodDef swordMethods[] = {
    { "csv_count_rows", csv_count_rows, METH_VARARGS, "Counts the rows in a CSV string." },
    { "csv_count_cols", csv_count_cols, METH_VARARGS, "Counts the columns in the first row of a CSV string."},
    { "csv_read_row", sword_csv_read_row, METH_VARARGS, "Reads one row from a CSV-string. Returns a tuple containg the parsed row and the remaining CSV-string."},
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