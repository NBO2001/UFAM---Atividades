#include <stdio.h>
#include <stdlib.h>

typedef struct Pessoa{
    char nome[50];
    int idade;
    char sexo;
}Pessoa;

// Ler os dados de para a uma struct pessoa.
void readData(Pessoa * peo);

// Mostra um valor do tipo pessoa.
void showPeople(Pessoa * people);

// Mostra varias pessoas.
void showPeoples(Pessoa * p, int tamp);

// Carrega os dados para um vetor returna o vetor e altera o tamanho.
Pessoa * loadingData(char * fileName,int * tam);


// Salve os dados da estruct em um arquivo de texto.
void salveInArqTxt(Pessoa * peoples, int tam, char * fileName);


// Salve os dados da estruct em um arquivo binario.
void salveInArq(Pessoa * peoples, int tam, char * fileName);

int main(){

    Pessoa * peoples, tmp;
    //Pessoa tmp;
    int tam;

    // scanf("%d%*c", &tam);

    // peoples = (Pessoa * ) malloc(sizeof(Pessoa)*tam);

    // for(int i=0; i < tam;i++){

    //     readData(&tmp);
    //     peoples[i] = tmp;
    // }

    peoples = loadingData("./output/base",&tam);

    salveInArqTxt(peoples,tam,"./output/baseTxt");
    
    showPeoples(peoples,tam);

    //salveInArq(peoples,tam,"./output/base");

}

void readData(Pessoa * peo){

    scanf("%[^\n]%*c", peo->nome);
    scanf("%d%*c", &peo->idade);
    scanf("%c%*c", &peo->sexo);

}

void showPeople(Pessoa * people){
    printf("{name: %s, age: %d, sexo: %c}\n", people->nome, people->idade, people->sexo);
}

void showPeoples(Pessoa * p, int tamp){

    for(int i=0; i < tamp; i++){

        showPeople(&p[i]);

    }

}

void salveInArqTxt(Pessoa * peoples, int tam, char * fileName){

    FILE * fp;

    fp = fopen(fileName, "w");

    fprintf(fp,"%d\n", tam);
 
    for(int i=0; i < tam; i++){
        fprintf(fp,"%s\n", peoples[i].nome);
        fprintf(fp,"%d\n", peoples[i].idade);
        fprintf(fp,"%c\n", peoples[i].sexo);

    }


    fclose(fp);

}

void salveInArq(Pessoa * peoples, int tam, char * fileName){

    FILE * fp;

    fp = fopen(fileName, "w");

    fwrite(&tam,sizeof(int), 1, fp);

    for(int i=0; i < tam; i++){

        fwrite(&peoples[i],sizeof(Pessoa), 1, fp);

    }


    fclose(fp);

}

Pessoa * loadingData(char * fileName,int * tam){


    FILE * fp;
    Pessoa * pessoas, tmp;
    int i=0;

    fp = fopen(fileName, "r");

    fread(tam,sizeof(int), 1, fp);

    pessoas = (Pessoa * ) malloc(sizeof(Pessoa)*(*tam));

    while (fread(&tmp, sizeof(Pessoa), 1, fp) == 1){
        pessoas[i] = tmp;
        i++;
    }


    fclose(fp);

    return pessoas;
}