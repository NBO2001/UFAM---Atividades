#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct{
    char nome[50];
    int idade;
    char sexo;
}Pessoa;



void lerArquivoDeTexto(char *nomeArquivo, Pessoa vet[], short *tam){
    int i = 0;
    FILE *fp;
    fp = fopen(nomeArquivo, "r");
    if (fp == NULL){
        printf("ERRO AO ABRIR ARUQIVO.\n");
        exit(1);
    }
    fscanf(fp, "%hi%*c", tam);
    while(fscanf(fp, "%[^\n]%*c", vet[i].nome) == 1){
        fscanf(fp, "%d%*c", &vet[i].idade);
        fscanf(fp, "%c%*c", &vet[i].sexo);
        i++;
    }
    fclose(fp);
}

void showPerson(Pessoa * people){
    printf("{name: %s, age: %d, sex: %c}\n", people->nome, people->idade, people->sexo);
}

void showPeople(Pessoa * p, int tamp){

    for(int i=0; i < tamp; i++){

        showPerson(&p[i]);

    }

}

void saveInBinary(char * fileName, Pessoa *vet, short tam){

    FILE * fp;

    fp = fopen(fileName, "w");

    fwrite(&tam,sizeof(short), 1, fp);

    for(short i=0; i < tam; i++){

        fwrite(&vet[i], sizeof(Pessoa), 1, fp);
    }

    fclose(fp);

}

int main(){
    Pessoa vet[10];
    short tam = 0;
    lerArquivoDeTexto("./test/t1.in", vet, &tam);
    showPeople(vet, tam);

    saveInBinary("./output/arq.bin", vet, tam);

}