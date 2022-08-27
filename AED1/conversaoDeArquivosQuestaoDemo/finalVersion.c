#include <stdio.h>
#include <stdlib.h>

typedef struct Pessoa{
    char nome[50];
    int idade;
    char sexo;
}Pessoa;

Pessoa * readArqBinary(short * tam,int * tamOf, char * fileName);
void showPerson(Pessoa * person);
void salveInFile(Pessoa * vet,int tam,char * fileName);

int main(){
    Pessoa * vec;
    short tam=0;
    int ofTam=0;

    vec = readArqBinary(&tam,&ofTam, "./output/arq.bin");

    // printf("%hhc\n", tam);
    printf("%d\n", ofTam);
    for(int i=0; i < ofTam; i++){
        
        showPerson(&vec[i]);

    }
    salveInFile(vec,ofTam,"./output/resul");
    
}

Pessoa * readArqBinary(short * tam, int * tamOf, char * fileName){

    FILE * fp;
	Pessoa * aux;
    Pessoa temp;
    short tm;

    fp = fopen(fileName, "r");

    if(fp == NULL){
        printf("Erro ao abrir o arquivo!!!\n");
        exit(0);
    }
		
	fread(tam,sizeof(short),1,fp );
	
    aux = (Pessoa * ) malloc(sizeof(Pessoa)*11);

    while (fread(&temp,sizeof(Pessoa),1,fp) == 1)
    {
        aux[(*tamOf)] = temp;
        (*tamOf)++;
    }

    fclose(fp);

    return aux;
}

void showPerson(Pessoa * person){
    printf("%s", person->nome);
	printf("%d\n", person->idade);
	printf("%c\n", person->sexo);
}

void salveInFile(Pessoa * vet,int tam,char * fileName){

    FILE * fp;
	Pessoa * aux;
    Pessoa temp;
    
    fp = fopen(fileName, "w");

    if(fp == NULL){
        printf("Erro ao abrir o arquivo!!!\n");
        exit(0);
    }
		
    fprintf(fp,"%d\n", tam);
    
    for(int i=0; i < tam; i++){
        
        fprintf(fp,"%s\n", vet[i].nome);
        fprintf(fp,"%d\n", vet[i].idade);
        fprintf(fp,"%c\n", vet[i].sexo);

    }

    fclose(fp);

}