#include "Python.h"
#include <ctype.h>
#include <stddef.h>

static long hash_bytes(unsigned char* p, Py_ssize_t len)
{
    register long x;
    register Py_ssize_t i;

    x = 0;
    i = len;

    x ^= *p << 7;
    while (--i >= 0) {
        x = (1000003*x) ^ *p++;
    }
    x ^= len;

    // avoid -1, denotes error in python hash function
    if (x == -1)
        x = -2;

    return x;
}

static long
hash_tuple(PyObject *v)
{
    PyTupleObject* to = (PyTupleObject*) v;
    register long x, y;
    register Py_ssize_t len = Py_SIZE(v);
    register PyObject **p;
    long mult = 1000003L;
    x = 0x345678L;
    p = to->ob_item;
    while (--len >= 0) {
        y = PyObject_Hash(*p++);
        if (y == -1)
            return -1;
        x = (x ^ y) * mult;
        /* the cast might truncate len; that doesn't change hash stability */
        mult += (long)(82520L + len + len);
    }
    x += 97531L;
    if (x == -1)
        x = -2;
    return x;
}
