cdef extern from 'myhash.c':
    void say_hello_to(int tons)

def pyton_wrapper_for_hello(int tons):
    say_hello_to(tons)
