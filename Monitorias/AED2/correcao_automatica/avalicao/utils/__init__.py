import subprocess
import time
import multiprocessing
import os

def check_header_file(filename, header_file):
    with open(filename, 'r') as file:
        content = file.read()
        if header_file in content:
            return True
        else:
            return False

def compile_c_code(compilation_str):

    args = [ x for x in compilation_str.strip().split(" ") if len(x) > 0]

    try:
        with open("erro", "w") as output_erro:
        # Run the gcc compiler command
            process = subprocess.run(args, stderr=output_erro)
       
        return True
    except subprocess.CalledProcessError as e:
        
        return False

def clean():
    try:
        subprocess.check_output(["rm", "avalicao/dependencias/sensor.c", "avalicao/dependencias/out.n", "avalicao/dependencias/out_resul"])
        return True
    except subprocess.CalledProcessError as e:
        return False
    
def move(student):

    try:
        subprocess.run(["cp", f"atividades/{student}/sensor.c", "avalicao/dependencias/"])
        return True
    except:
        return False
    

def sub_process(args, file_input, output_file, result_queue):
    result = subprocess.run(args, stdin=open(file_input), stdout=output_file)
    result_queue.put(result)

def execute_command(command, file_input, file_output, timeout=None):

    args = [ x for x in command.strip().split(" ") if len(x) > 0]

    try:
        # Run the gcc compiler command
        with open(file_output, "w") as output_file:
            try:
                result_queue = multiprocessing.Queue()
                p = multiprocessing.Process(target=sub_process, args=(args, file_input,output_file, result_queue, ))
                # process = subprocess.run(args, stdin=open(file_input), stdout=output_file, timeout=timeout)
                # process = subprocess.run(arg,-1,None,None,None, None,)
                p.start()
                p.join()

                # Retrieve the result from the queue
                result = result_queue.get()
                
                return result.returncode
               

            except Exception as e:
                while p.is_alive():
                    time.sleep(1)

                # Retrieve the result from the queue
                result = result_queue.get()

                return result.returncode
            
            
        return True
    except subprocess.CalledProcessError as e:
        return False

def check_file_exists(directory):
    file_path = os.path.join(directory, "out.n")
    if os.path.isfile(file_path):
        return True
    else:
        return False
    

def getError(student):
    with open("erro", 'r') as file:
        content = file.read()

    if len(content) > 0:
        subprocess.run(["mv", "erro" , f"erros/{student}.erro"])
