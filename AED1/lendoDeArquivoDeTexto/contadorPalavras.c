#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct words{
    char wd[50];
    int qnt;
}words;

char cmp(words a, words b);
void intercalary(words als[], int inicio, int meio, int fim, words aux[]);
void mergeR(words v[], int inicio, int fim, words aux[]);
void merge(words als[], int tam);
void insereNoVetor(words * vector, char *wd, int *tam);

int main(){
    
    FILE * fp;
    int tam=0;
    words data[50];
    char tmp[50];

    fp = fopen("./output/t4", "r");

    while(fscanf(fp,"%[^\n]%*c", tmp) == 1){

        insereNoVetor(data,tmp,&tam);
        
    }

    merge(data,tam);
    
    for(int i=0; i < 5 ; i++){

        printf("%s %d \n", data[i].wd, data[i].qnt);
        
    }

    fclose(fp);
}

char cmp(words a, words b){

    if(a.qnt >= b.qnt ){
        return 1;
    }

    return 0;
}

// Funcao que intercala os valores
void intercalary(words als[], int inicio, int meio, int fim, words aux[]){

    int i, j,k=inicio;

    i = inicio;
    j = meio + 1;

    while( (i <= meio) && (j <= fim)){

        if(cmp(als[i],als[j])){
            aux[k] = als[i];
            i++;
        }else{
            aux[k] = als[j];
            j++;
        }

        k++;
    }

    while( i <= meio){
        aux[k] = als[i];
        i++;
        k++;
    }
    while( j <= fim){
        aux[k] = als[j];
        j++;
        k++;
    }

    for(i=inicio; i < k; i++){ als[i] = aux[i];  }

}

void mergeR(words v[], int inicio, int fim, words aux[]){

    int meio; 
    
    if (inicio < fim){
        meio = (inicio+fim)/2;

        mergeR(v, inicio, meio, aux);
        mergeR(v, meio+1, fim, aux);
        intercalary(v,inicio,meio,fim,aux);

    }

}

void merge(words als[], int tam){

    words *aux;

    aux = (words *) malloc(sizeof(words)*(tam+2));

    mergeR(als,0,tam-1,aux);

    free(aux);

}

void insereNoVetor(words * vector, char *wd, int (*tam)){

    for(int i=0; i < (*tam); i++){

        if(strcmp(vector[i].wd, wd) == 0){
            vector[i].qnt = vector[i].qnt + 1; 
            return;
        }

    }

    strcpy(vector[(*tam)].wd, wd);

    vector[(*tam)].qnt = 1;

    *tam = *tam+1;

}