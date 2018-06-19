from eden import hash

def test_python2_hash_for_string():
    assert hash.py2hash('totallyfancyteststring') == -164093292463378545
    assert hash.py2hash('A') == 8320025024
