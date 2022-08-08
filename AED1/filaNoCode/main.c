#include <stdio.h>
#include <stdlib.h>


typedef struct { 
    char nome[20];
    int id;
} tipoDados;

typedef struct tipoNo {
 tipoDados d;
 struct tipoNo *prox;
} tipoNo;


typedef struct tipoFila {
 tipoNo *prim;
 tipoNo *ult;
} tipoFila;

// Funcoes a serem feitas. 
// Coloque os includes necessários para seu para o seu 
// programa aqui
// SUAS FUNCOES DEVEM COMPLEMENTAR O PROGRAMA PRINCIPAL
// ELE JA TEM CHAMADAS PARA SUAS FUNCOES
void criaFila(tipoFila * f){
    f->prim = NULL;
    f->ult = NULL;

}
tipoNo * node(tipoDados * data){
    
    tipoNo * nd;

    nd = (tipoNo * ) malloc(sizeof(tipoNo));

    nd->d = *data;
    nd->prox = NULL;

    return nd;

}

void insereNaFila(tipoFila * f, tipoDados data){

    tipoNo * aux;
    
    aux = node(&data);

    if(f->ult){
        
        f->ult->prox = aux;

        f->ult = aux;
    
    }else{
        f->prim = aux;
        f->ult = aux;
    }


}
tipoDados removeDaFila(tipoFila * f){
    
    tipoDados aux;

    tipoNo * tmp;
    tmp = f->prim;
    if(tmp){
        
        aux = tmp->d;

        f->prim = tmp->prox;

        if(!tmp->prox){ f->ult = NULL; }

        free(tmp);
    }
    return aux;


}
// FIM DO SEI CODIGO


void mostraFila(tipoFila *p) {
 tipoNo *aux= p->prim;
	
	while(aux) {
	printf("%s\n",aux->d.nome);
	printf("%d\n",aux->d.id);
		aux = aux->prox;
	}
	
}

int  main() {
	tipoDados pessoa;
	tipoFila p1;
	tipoFila p2;
	
	
	criaFila(&p1);
	criaFila(&p2);
	
	scanf("%[^\n]%*c",pessoa.nome);
	scanf("%d%*c",&pessoa.id);
	insereNaFila(&p1,pessoa);
	
	scanf("%[^\n]%*c",pessoa.nome);
	scanf("%d%*c",&pessoa.id);
	insereNaFila(&p1,pessoa);
	
	pessoa = removeDaFila(&p1);
	insereNaFila(&p2,pessoa);
	
	scanf("%[^\n]%*c",pessoa.nome);
	scanf("%d%*c",&pessoa.id);
	insereNaFila(&p1,pessoa);
	
	scanf("%[^\n]%*c",pessoa.nome);
	scanf("%d%*c",&pessoa.id);
	insereNaFila(&p1,pessoa);
	
	pessoa = removeDaFila(&p1);
	insereNaFila(&p2,pessoa);
	
	mostraFila(&p1);
	mostraFila(&p2);
	
}
