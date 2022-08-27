#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct{
    char nome[50];
    int idade;
    char sexo;
}Pessoa;

// Mostra em asCii cada elemento
void analise(char * nameFile);
void testaAMerda(char * nameFile);
void showPerson(Pessoa * person);

int main(){

    short tam;

    scanf("%hi", &tam);

    printf("%hi\n", tam);

    //testaAMerda("ro_arq.bin");

}

void analise(char * nameFile){

    FILE * fp;
    char tm;

    fp = fopen(nameFile, "r");

    if(fp == NULL){
        printf("Erro ao abrir o arquivo\n");
        exit(0);
    }

    do{
        tm = fgetc(fp);
        if(tm == 'a'){
            printf("tell %d \n", ftell(fp));
        }

        if(tm == 'm'){
            printf("tell %d ", ftell(fp));
        }

        printf("%c", tm);

    }while(tm != EOF);
    

    fclose(fp);

}

void showPerson(Pessoa * person){
    printf("%s", person->nome);
	printf("%d\n", person->idade);
	printf("%c\n", person->sexo);
}


void testaAMerda(char * nameFile){

    FILE * fp;
    short tm, tam;
    Pessoa temp;

    fp = fopen(nameFile, "r");
	
	fread(&tam,sizeof(short),1,fp);
	
   fread(&temp,sizeof(Pessoa),1,fp);

    showPerson(&temp);
		fread(&temp,sizeof(Pessoa),1,fp);
	showPerson(&temp);

    fclose(fp);

}

