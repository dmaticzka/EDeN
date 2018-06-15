cdef extern from 'myhash_impl.c':
    void say_hello_to(int tons)
    long newhash(char* data)
    # string_hash(PyStringObject *a)

def pyton_wrapper_for_hello(int tons):
    say_hello_to(tons)

def python_wrapper_for_myhash():
    py_string = 'hello'
    cdef char* other_c_string = py_string
    return(newhash(other_c_string))
