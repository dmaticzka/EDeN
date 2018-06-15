cdef extern from 'myhash_impl.c':
    long newhash(unsigned char* c_string, Py_ssize_t c_len)

def python_wrapper_for_myhash(py_string):
    # required to convert to c_string from python 2 and 3
    utf = py_string.encode("UTF-8")
    cdef unsigned char* c_string = utf
    cdef Py_ssize_t c_len = len(py_string)
    return(newhash(c_string, c_len))
