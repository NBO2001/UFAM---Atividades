from avalicao.assessments.assessment_01 import assessment_01
from avalicao.assessments.assessment_02 import assessment_02
from avalicao.assessments.assessment_03 import assessment_03
from avalicao.assessments.assessment_04 import assessment_04
from avalicao.assessments.assessment_05 import assessment_05
from avalicao.assessments.assessment_06 import assessment_06
from avalicao.assessments.assessment_07 import assessment_07
from avalicao.assessments.assessment_08 import assessment_08
from avalicao.assessments.assessment_09 import assessment_09

from avalicao.utils import move, clean, getError

import multiprocessing

def avaliacao(student, allowMove=True, allowClean=True, debugger=False):
    
    if allowMove:
        move(student)
    pont = 0.0

    avaliacoes = [assessment_01,assessment_02, assessment_03, assessment_04, assessment_05, assessment_06, assessment_07]
   
    out = f""

    teste = 0

    for av in avaliacoes:
        try:
            print(f"Teste {teste}")
            teste += 1
            tmp = av(debugger=debugger)
        except:
            tmp = 0
            
        if(tmp):
            out += f"x "
        else:
            out += f"- "

        pont += tmp

    if allowClean:
        clean()

    try:
        getError(student)
    except:
        pass

    return pont, out

