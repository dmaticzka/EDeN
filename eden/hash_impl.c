#include "Python.h"
#include <ctype.h>
#include <stddef.h>

static long hash_bytes(PyObject *o)
{
    PyBytesObject *a = (PyBytesObject*) o;

    register Py_ssize_t len;
    register unsigned char *p;
    register long x;

    len = Py_SIZE(a);
    if (len == 0) {
        return 0;
    }
    p = (unsigned char *) a->ob_sval;
    x = 0;
    x ^= *p << 7;
    while (--len >= 0) {
        x = (1000003*x) ^ *p++;
    }
    x ^= Py_SIZE(a);

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
    register Py_ssize_t len = Py_SIZE(to);
    register PyObject **p;
    long mult = 1000003L;
    x = 0x345678L;
    p = to->ob_item;
    while (--len >= 0)
        PyObject* uc = (PyObject*) *p++;
        y = hash_bytes(uc);
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
