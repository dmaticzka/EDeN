cdef extern from 'myhash_impl.c':
    long newhash(unsigned char* c_string, Py_ssize_t c_len)

def python_wrapper_for_myhash(bytes py_string):
    # py_string = 'hellomydear'
    cdef unsigned char* c_string = py_string
    cdef Py_ssize_t c_len = len(py_string)
    return(newhash(c_string, c_len))
