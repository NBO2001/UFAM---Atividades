/*Considere uma lista encadeada dinâmica com dados do tipo inteiro (int). Diz-se que
uma lista encadeada é simétrica (conceito inventado para a questão) se cada elemento que
ocorre antes da posição do meio (na primeira metade, desconsiderando o elemento do
centro se houver número ímpar de elementos), tem um correspondente de valor igual na
segunda metade da lista (há um outro com o mesmo valor na segunda metade da lista).
Considere que nenhum valor ocorre mais de duas vezes na lista. Como exemplo, as listas
<3,6,9, 3,9,6> e <6, 3,9,3,9,6> são simétricas. Já as listas <3,6,9,3,6,5> e <3,6,5,5,2,3>
não são simétricas. (P 2008)*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tipoNo{
    int dado;
    struct tipoNo *prox;
} tipoNo;

typedef struct tipoLista{
    tipoNo *prim;
} tipoLista;

void criaLista(tipoLista *l){
    l->prim = NULL;
}

void insereNaLista(tipoLista *l, int dado){
    tipoNo *aux;
    aux = (tipoNo*) malloc(sizeof(tipoNo));
    aux->dado = dado;
    aux->prox = l->prim;
    l->prim = aux;
}

// Conta lista encadeada
int len(tipoLista *l){

    tipoNo * aux;
    int tam=0;

    aux = l->prim;
    
    while(aux){
       
        tam++;
        aux = aux->prox;
    
    }
    return tam;

}

char exist(tipoNo * fist, int data){


    do{

        if(fist->dado == data){
            return 1;
        }

        fist = fist->prox;
    }while(fist);
    
    return 0;

}


tipoNo * getAddress(tipoLista * l, int k){

    tipoNo * aux;
    
    aux = l->prim;
    
    int tam=1;

    while (aux)
    {
        
        if(k == tam){ return aux; }

        tam++;
    
        aux = aux->prox;
    }
    
    return NULL;

}



char listaSimetrica(tipoLista *l){

    tipoNo *aux, * harfAddress;

    int meio;
  
    meio = len(l)/2;
    
    harfAddress = getAddress(l,meio);

    aux = l->prim;
    
    while(aux != harfAddress){
        
        if(!exist(harfAddress,aux->dado)) return 0;

       aux = aux->prox;
    }

    return 1;
}

void mostraLista(tipoLista *l){
    tipoNo *aux;
    aux = l->prim;
    while(aux){
        printf("%d ", aux->dado);
        aux = aux->prox;
    }
    printf("\n");

}
int main(){
    tipoLista l;
    int tmp;
    int n;

    criaLista(&l);

    scanf("%d", &n);

    for(int i=0; i < n; i++){ scanf("%d", &tmp ); insereNaLista(&l, tmp); }

    mostraLista(&l);
    if(listaSimetrica(&l)){
        printf("Its true!!!\n");
    }else{
        printf("Its false!!!\n");
    }
}