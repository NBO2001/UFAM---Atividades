#include <stdio.h>
#include <stdlib.h>

typedef struct Pessoa{
    char nome[50];
    int idade;
    char sexo;
}Pessoa;

Pessoa * readArqBinary(short * tam, char * fileName);
void showPerson(Pessoa * person);

int main(){

    short tam;
    readArqBinary(&tam, "ro_");
    printf("%hi\n", tam);
}

Pessoa * readArqBinary(short * tam, char * fileName){

    FILE * fp;

    fp = fopen(fileName, "r");

    fread(tam, sizeof(short),1,fp);

    fclose(fp);

    return NULL;
}



