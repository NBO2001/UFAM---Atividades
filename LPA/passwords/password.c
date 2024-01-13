#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <crypt.h>
#include "libs/typeVector/typeVector.h"
#include "libs/typeString/typeString.h"

TypeVector* createCombination(char* caracteres, int tamMax){

    TypeString* carac = newString(.initialString=caracteres);
    
    TypeVector* vector = splitString(carac);
    TypeVector* vectorCopy = splitString(carac);

    TypeString* tmp;
    TypeString* tmpCaracter;

    int start = 0;
    int end_vector = getLenVector(vector);

    for(int i=2; i <= tamMax; i++){
        
        for(int j=start; j < end_vector; j++){
            
            tmp = vectorGet(vector, j);

            startInterationVector(vectorCopy);

            while (tmpCaracter = (TypeString*) nextElementvector(vectorCopy))
            {
                TypeString* newStrVal = concateString(tmp, tmpCaracter);
                vectorPush(vector, newStrVal);
            }
            
        }

        start = end_vector;
        end_vector = getLenVector(vector);
    }

    return vector;

}

int verificaSenha(char* senhaTeste, char* senhaCriptografada) {
    char *senhaTesteCriptografada = crypt(senhaTeste, senhaCriptografada);
    return strcmp(senhaTesteCriptografada, senhaCriptografada);
}

void app(TypeVector* caracteresVector, char *senhaCriptografada, int verbose ){
    TypeString* carac;


    
    startInterationVector(caracteresVector);

    int flag = 1;
    while ((carac = (TypeString*) nextElementvector(caracteresVector)) && flag)
    {   
        if (!verificaSenha(getVectorChar(carac), senhaCriptografada)){
            printf("%s --> sim! Senha encontrada!\n",getVectorChar(carac));
            flag = 0;
        }
        else {
            if(verbose) printf("%s --> não\n",getVectorChar(carac));
        }
        
    }
}

int main(int argc, char* *argv){

    int tamanhoMaximo = 3;
    char caracteres[] = "abc";
    TypeVector* caracteresVector = createCombination(caracteres, tamanhoMaximo);
    char *senhaCriptografada = "$6$7yCakIXevncmT6se$m002Lkf2BK6Qgyhc.c/PxMTvcmBAXYtIo"
    "kUKvWwvB5H5zCt5HhhPOlV8ygebOcSsgNqG74whVwN.8UF9WaGfs/";

    app(caracteresVector, senhaCriptografada, 1);

    tamanhoMaximo = 4;
    char caracteres_02[] = "0123456789";
    caracteresVector = createCombination(caracteres_02, tamanhoMaximo);
    char *senhaQueastao01 = "$6$LrSF5BAseToYYHJ0$SYY1avj8FRoRGpn.1kPXuZ6Xn5WTl2kL3"
    "hxc3yMWdDUyz4c/Ac3Av3WO8Q9LciP8o4c9WaeLcgxIXWaHpJMFb.";
    
    app(caracteresVector, senhaQueastao01, 0);

    tamanhoMaximo = 3;
    char caracteres_03[] = "abcdefghijklmnopqrstuvzyxw";
    caracteresVector = createCombination(caracteres_03, tamanhoMaximo);
    char *senhaQueastao02 = "$6$rMAk28dVkWjpYoA3$SkWbPYqEB8O/10ryvvjm1qN9BOrkeBOXp"
    "JScVSGDL5L88OIs0UCBuP.pnd9TQ6SBx60dLKwR9WAzfnLtvjGvj.";

    app(caracteresVector, senhaQueastao02, 0);

    tamanhoMaximo = 5;
    char caracteres_04[] = "0123456789";
    caracteresVector = createCombination(caracteres_04, tamanhoMaximo);
    char *senhaQueastao03 = "$6$l2xE4w9twgjtnZBz$9YK9krslZFraLffy5VNiahAfT.xZNvB54"
    "j91DMCMIoVFvj335ZKxb11qgVMn.KzU2GqVPPyS2FTBqPSciYq761";
    app(caracteresVector, senhaQueastao03, 0);
    
}