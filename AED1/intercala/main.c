#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct tipoDado{
    int dado;
} tipoDado;

typedef struct tipoNo{
    tipoDado dado;
    struct tipoNo *prox;
} tipoNo;

typedef struct tipoLista{
    tipoNo *prim;
} tipoLista;

void criaLista(tipoLista *l){
    l->prim = NULL;
} 

void insereNaLista(tipoLista *l, tipoDado dado){
    tipoNo *aux;
    aux = (tipoNo *) malloc(sizeof(tipoNo));
    aux->dado = dado;
    aux->prox = l->prim;
    l->prim = aux;
}

void intercala(tipoLista *l1, tipoLista *l2){
    tipoNo *aux, *tmp, *tmp2, *tmp3, * anterior;
    aux = l1->prim;
    tmp = l2->prim;
    if (!aux){
        l1->prim = tmp;
        l2->prim = NULL;
        return;
    }
    if (!tmp){
        return;
    }
    
    while (aux && tmp)
    {
        tmp2 = tmp->prox;
        
        anterior = aux;

        tmp3 = aux->prox;

        tmp->prox = aux->prox;
        
        aux->prox = tmp;
        aux=tmp3;

        tmp = tmp2;
    }
    if(tmp){
        anterior->prox->prox = tmp;
    }

    l2->prim = NULL;

}

void lerParaLista(tipoLista *l, int n){
    tipoDado dado;
    int x;
    for (x = 0; x < n; x++){
        scanf("%d", &dado.dado);
        insereNaLista(l, dado);
    }
}

void mostraLista(tipoLista *l){
    tipoNo *aux;
    aux = l->prim;
    while(aux){
        printf("%d ", aux->dado.dado);
        aux = aux->prox;
    }
    printf("\n");
}


int main(){

    tipoLista l1, l2;

    criaLista(&l1);
    criaLista(&l2);

    lerParaLista(&l1, 5);
    lerParaLista(&l2, 6);

    mostraLista(&l1);
    mostraLista(&l2);

    printf("More errors\n");

    intercala(&l1, &l2);
    mostraLista(&l1);
    mostraLista(&l2);

}