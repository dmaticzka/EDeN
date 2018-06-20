from eden import hash

def test_python2_hash_for_string():
    assert hash.py2hash_bytes('totallyfancyteststring') == -164093292463378545
    assert hash.py2hash_bytes('A') == 8320025024
    assert hash.py2hash_tuple(('A','B')) == 3827259697253177498
    assert hash.py2hash_tuple((1,2)) == 3713081631934410656
    assert hash.py2hash_tuple((1.0,2.0)) == 3713081631934410656
    assert hash.py2hash_tuple((1,2,'A','B')) == 4757425340937179621
