from pickle import TRUE
from horse import possivel,is_integer

class TestClassDemoInstance:
    value = 0

    def test_one(self):
        
        assert possivel(5,5,4,7) == True
        assert possivel(5,5,8,1) == False
        assert possivel(5,5,6,7) == True
        assert possivel(1,8,2,11) == False
        assert possivel(5,5,7,6) == True
        assert possivel(1,8,2,4) == False
        assert possivel(1,1,2,3) == True
        assert possivel(8,8,9,10) == False
        assert possivel(8.1,8,9,10) == False
        assert possivel(8,8.5,9,10) == False
        assert possivel(8,8,9.5,9.5) == False
    
    def test_int(self):
        assert is_integer(1) == True
        assert is_integer(1.5584) == False
        assert is_integer(1.5) == False
        assert is_integer(5.5) == False
        assert is_integer(5) == True
        assert is_integer(6) == True
        assert is_integer(6.8) == False
        assert is_integer(7.5) == False

        

