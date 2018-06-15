#include "Python.h"
#include <ctype.h>
#include <stddef.h>

static long newhash(unsigned char* p, Py_ssize_t len)
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
