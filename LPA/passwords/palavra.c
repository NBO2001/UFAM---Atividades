#include <stdio.h>
#include <stdlib.h>
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

int main(int argc, char* *argv){

    int tamanhoMaximo = 3;
    char caracteres[] = "abc";

    
    TypeVector* caracteresVector = createCombination(caracteres, tamanhoMaximo);

    TypeString* carac;
    
    startInterationVector(caracteresVector);

    while (carac = (TypeString*) nextElementvector(caracteresVector))
    {
        printf("%s\n", getVectorChar(carac));
    }
    

    
}