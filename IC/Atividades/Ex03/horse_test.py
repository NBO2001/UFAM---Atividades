from pickle import TRUE
from horse import possivel

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

        

