from avalicao.utils import execute_command, check_file_exists
import re

import signal

class TimeoutError(Exception):
    pass

def timeout_handler(signum, frame):
    raise TimeoutError("Function timed out")


def assessment_05(debugger=False):
    # Set the desired timeout value in seconds
    timeout = 5

    # Set the signal handler for the alarm signal
    signal.signal(signal.SIGALRM, timeout_handler)

    # Set the alarm for the specified timeout
    signal.alarm(timeout)

    path = "avalicao/dependencias/"

    file_name = "vento"

    if(not check_file_exists(path)):
        return 0

    cm = f"./{path}out.n 2 ./{path}{file_name}/files/baby"
 
    execute_command(cm, f"{path}{file_name}/input/baby.in", f"{path}out_resul")
    
    try:
        with open(f"{path}out_resul", "r") as file:
            out = file.read()
        
        with open(f"{path}{file_name}/out/baby.out") as file:
            ava = file.read()
    except:
        if debugger:
                print("Falha de execução", cm, f"{path}{file_name}/input/baby.in", f"{path}out_resul")
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
                print("Error output", cm, f"{path}{file_name}/input/baby.in", f"{path}out_resul")
            return 0
        
    except TimeoutError:
        return 0