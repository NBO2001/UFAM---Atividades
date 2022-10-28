

def bim_for_decimal(bin_val:str) -> int:

    init = len(bin_val) - 1

    acum = 0

    for i in range(len(bin_val)):
        acum += int(bin_val[i]) * (2**init)
        init -= 1

    return acum

def bim_fracao_for_decimal(bin_val:str) -> float:
    acum = 0

    for i in range(len(bin_val)):
        acum += int(bin_val[i]) * (2**(-(i+1)))

    return acum

def execute_shift(expor:int, number_binary:str) -> tuple:

    if expor >= 0:
        return (f"1{number_binary[:expor]}", number_binary[expor:])
    else:
        init = abs(expor) - 1
        newString = "1"
        for _ in range(init,0, -1):
            newString = f"0{newString}" 
        
        return (f"0", newString + number_binary)
        

bin_input = input()

signal_b = bin_input[0]

expor = bim_for_decimal(bin_input[1:12]) - 1023

int_part, frac_part = execute_shift(expor,bin_input[12:])

resul = (1 if signal_b == '0' else -1) * (bim_for_decimal(int_part) + bim_fracao_for_decimal(frac_part))


print(resul)

# 0 10000001010 1001001100000000000000000000000000000000000000000000
# 1 10000001010 1001001100000000000000000000000000000000000000000000

# 0 01111111111 0101001100000000000000000000000000000000000000000000
# 0 01111111111 0101001100000000000000000000000000000000000000000001

# 0100000001011001000000000000000000000000000000000000000000000000
# 0011111111010000000000000000000000000000000000000000000000000000