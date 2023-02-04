
def convertStrBin(string):

    valueBin = 0
    for i in string:
        valueBin = valueBin << 1
        if i == "0":
            valueBin += 0
        else:
            valueBin += 1
    
    return valueBin
        


    

breakpoint()
convertStrBin("1010")