from avalicao.utils import execute_command
import multiprocessing
import re
import signal

class TimeoutError(Exception):
    pass

def timeout_handler(signum, frame):
    raise TimeoutError("Function timed out")


def assessment_08(debugger=False):
    # Set the desired timeout value in seconds
    timeout = 5

    # Set the signal handler for the alarm signal
    signal.signal(signal.SIGALRM, timeout_handler)

    # Set the alarm for the specified timeout
    signal.alarm(timeout)

    path = "avalicao/dependencias/"

    file_name = "vento"

   
    cm = f"./{path}out.n 2 ./{path}{file_name}/files/boss"
    
    
    code = execute_command(cm, f"{path}{file_name}/input/boss.in", f"{path}out_resul", timeout=6000)

    if(code != 0):
        return 0
    
    try:
        with open(f"{path}out_resul", "r") as file:
            out = file.read()
        
        with open(f"{path}{file_name}/out/boss.out") as file:
            ava = file.read()
    except:
        return 0    
    

    try:
        # Call your function here
        matches = re.findall(ava, out)

        # If the function completes before the timeout, cancel the alarm
        signal.alarm(0)

        if matches:
            return 1
        else:
            return 0
        
    except TimeoutError:
        return 0


  