from avalicao.utils import compile_c_code, clean, check_header_file

def assessment_01(debugger=False):
    
    origem_path = "./avalicao/dependencias/"

    pontuation = 0
    try:
        if(check_header_file(f"{origem_path}sensor.c", "listase.h")):

            if debugger:
                print(f"gcc {origem_path}listase.c {origem_path}sensor.c -o {origem_path}/out.n")
                print(f"gcc {origem_path}sensor.c -o {origem_path}/out.n")
            
            pontuation =  1 if compile_c_code(f"gcc {origem_path}listase.c {origem_path}sensor.c -o {origem_path}/out.n") else 0
        else:
            pontuation =  1 if compile_c_code(f"gcc {origem_path}sensor.c -o {origem_path}/out.n") else 0

    except:
        return pontuation 


    return pontuation