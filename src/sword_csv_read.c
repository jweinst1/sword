#include "sword_csv_read.h"

#define SWORD_SET_ERR_MES(mes) PyErr_SetString(PyExc_Exception, mes)

PyObject* sword_csv_read_row(PyObject* self, PyObject* args)
{
    PyObject* tup_return;
    PyObject* row_lst;
    PyObject* parsed_field;
    PyObject* remain_string;
    const char* str_arg;
    const char* arg_read;
    Py_ssize_t cur_field_sz;
    const char* cur_field_pt;
    
    if(!PyArg_ParseTuple(args, "s", &str_arg)) {
        return NULL;
    }
    arg_read = str_arg;
    tup_return = PyTuple_New(2);
    row_lst = PyList_New(0);
    cur_field_sz = 0;
    cur_field_pt = NULL;
    remain_string = NULL;
    if(tup_return == NULL || row_lst == NULL) {
        SWORD_SET_ERR_MES("Pylist or pytuple created failed!");
        goto ERR_STATE_WORK;
    }
    
    while(*arg_read && *arg_read != '\n') {
        if(cur_field_sz == 0) {
            // we are not currently tracking a field.
            if(*arg_read == ',') {
                // empty field detected.
                arg_read++;
                if(PyList_Append(row_lst, Py_None) == -1) {
                    SWORD_SET_ERR_MES("Pylist append none failed!");
                    goto ERR_STATE_WORK;
                }
            }
            else {
                cur_field_pt = arg_read++;
                ++cur_field_sz;
                // We are now in the field checking state.
            }
        }
        else {
            if(*arg_read == ',') {
                // append the string
                parsed_field = PyBytes_FromStringAndSize(cur_field_pt, cur_field_sz);
                if(parsed_field == NULL) {
                    SWORD_SET_ERR_MES("PyBytes from string and size failed!");
                    goto ERR_STATE_WORK;
                }
                if(PyList_Append(row_lst, parsed_field) == -1) {
                    SWORD_SET_ERR_MES("pylist append field failed!");
                    goto ERR_STATE_WORK;
                }
                cur_field_pt = NULL;
                cur_field_sz = 0;
                arg_read++;
            }
            else {
                arg_read++;
                cur_field_sz++;
            }
        }
    }
    // get the last field, if needed,
    if(cur_field_sz > 0) {
        parsed_field = PyBytes_FromStringAndSize(cur_field_pt, cur_field_sz);
        if(parsed_field == NULL) {
            SWORD_SET_ERR_MES("PyBytes_FromStringAndSize failed!");
            goto ERR_STATE_WORK;
        }
        if(PyList_Append(row_lst, parsed_field) == -1) {
            SWORD_SET_ERR_MES("PyList append fails for parsed field!");
            goto ERR_STATE_WORK;
        }
    }
    PyTuple_SET_ITEM(tup_return, 0, row_lst);
    remain_string = PyBytes_FromString(arg_read);
    if(remain_string == NULL) {
        SWORD_SET_ERR_MES("PyBytes_FromString fails on remain string!");
        goto ERR_STATE_WORK;
    }
    PyTuple_SET_ITEM(tup_return, 1, remain_string);
    return tup_return;
ERR_STATE_WORK:
    Py_XDECREF(row_lst);
    Py_XDECREF(tup_return);
    Py_XDECREF(parsed_field);
    return NULL;
}