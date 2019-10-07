#include "sword_csv_read.h"

PyObject* sword_csv_read_row(PyObject* self, PyObject* args)
{
    const char* str_arg;
    if(!PyArg_ParseTuple(args, "s", &str_arg)) {
        return NULL;
    }
    // to do
    return PyBytes_FromStringAndSize(str_arg, 2);
}