from cpython.ref cimport PyObject

cdef extern from 'hash_impl.c':
    long hash_bytes(unsigned char* c_string, Py_ssize_t c_len)
    long hash_tuple(PyObject *v)

def py2hash_bytes(bytes b):
    cdef unsigned char* c_string = b
    cdef Py_ssize_t c_len = len(b)
    return(hash_bytes(c_string, c_len))

def py2hash_tuple(tuple t):
    cdef PyObject* po = <PyObject*> t
    return(hash_tuple(po))
    return(0)
