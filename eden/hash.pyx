from cpython.ref cimport PyObject

cdef extern from 'hash_impl.c':
    long hash_bytes(PyObject *po)
    long hash_tuple(PyObject *po)

def py2hash_bytes(b):
    cdef PyObject* po = <PyObject*> b
    return(hash_bytes(po))

def py2hash_tuple(tuple t):
    cdef PyObject* po = <PyObject*> t
    return(hash_tuple(po))
