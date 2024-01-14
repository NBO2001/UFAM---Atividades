from avalicao.utils import execute_command, check_file_exists
import re

import signal

class TimeoutError(Exception):
    pass

def timeout_handler(signum, frame):
    raise TimeoutError("Function timed out")


def assessment_04(debugger=False):
    # Set the desired timeout value in seconds
    timeout = 5

    # Set the signal handler for the alarm signal
    signal.signal(signal.SIGALRM, timeout_handler)

    # Set the alarm for the specified timeout
    signal.alarm(timeout)

    path = "avalicao/dependencias/"

    file_name = "temperatura"

    cm = f"./{path}out.n 1 ./{path}{file_name}/files/baby"
    
    if(not check_file_exists(path)):
        if debugger:
                print("Erro file")
                print(cm, f"{path}{file_name}/input/baby.in", f"{path}out_resul")
        return 0
    
    code = execute_command(cm, f"{path}{file_name}/input/baby.in", f"{path}out_resul")
    
    if(code != 0):
        if debugger:
            print("Erro code")
            print(cm, f"{path}{file_name}/input/baby.in", f"{path}out_resul")

        return 0
        
    try:
        with open(f"{path}out_resul", "r") as file:
            out = file.read()
        
        with open(f"{path}{file_name}/out/baby.out") as file:
            ava = file.read()
    except:
        if debugger:
                print("Erro segmentation")
                print(cm, f"{path}{file_name}/input/baby.in", f"{path}out_resul")
        return 0    
    

    try:
        # Call your function here
        matches = re.findall(ava, out)

        # If the function completes before the timeout, cancel the alarm
        signal.alarm(0)

        if matches:
            return 1
        else:
            if debugger:
                print("Erro output")
                print(cm, f"{path}{file_name}/input/baby.in", f"{path}out_resul")
            return 0
        
    except TimeoutError:
        if debugger:
                print("Erro time")
                print(cm, f"{path}{file_name}/input/baby.in", f"{path}out_resul")
        return 0