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


typedef struct tipoPilha {
 tipoNo *topo;
} tipoPilha;

// Funcoes a serem feitas. 
// Coloque os includes necessários para seu para o seu 
// programa aqui
// SUAS FUNCOES DEVEM COMPLEMENTAR O PROGRAMA PRINCIPAL
// ELE JA TEM CHAMADAS PARA SUAS FUNCOES
tipoNo * node(tipoDados * dt){
    
    tipoNo * no;
    
    no = (tipoNo *) malloc(sizeof(tipoNo));

    no->d = *dt;

    no->prox = NULL;

    return no;
}

void criaPilha(tipoPilha *p){
    p->topo = NULL;
}

void insereNaPilha(tipoPilha *p, tipoDados data){
    tipoNo * aux;

    aux = node(&data);

    aux->prox = p->topo;

    p->topo = aux;

}
tipoDados removeDaPilha(tipoPilha * p){
    
    tipoDados tmp;    
    tipoNo * aux;

    aux = p->topo;
    tmp = aux->d;
    p->topo = aux->prox;

    free(aux);

    return tmp;

} 
// FIM DO SEI CODIGO


void mostraPilha(tipoPilha *p) {
 tipoNo *aux= p->topo;
	
	while(aux) {
	printf("%s\n",aux->d.nome);
	printf("%d\n",aux->d.id);
		aux = aux->prox;
	}
	
}

int  main() {
	tipoDados pessoa;
	tipoPilha p1;
	tipoPilha p2;
	
	
	criaPilha(&p1);
	criaPilha(&p2);
	
	scanf("%[^\n]%*c",pessoa.nome);
	scanf("%d%*c",&pessoa.id);
	insereNaPilha(&p1,pessoa);
	
	scanf("%[^\n]%*c",pessoa.nome);
	scanf("%d%*c",&pessoa.id);
	insereNaPilha(&p1,pessoa);
	
	pessoa = removeDaPilha(&p1);
	insereNaPilha(&p2,pessoa);
	
	scanf("%[^\n]%*c",pessoa.nome);
	scanf("%d%*c",&pessoa.id);
	insereNaPilha(&p1,pessoa);
	
	scanf("%[^\n]%*c",pessoa.nome);
	scanf("%d%*c",&pessoa.id);
	insereNaPilha(&p1,pessoa);
	
	pessoa = removeDaPilha(&p1);
	insereNaPilha(&p2,pessoa);
	
	mostraPilha(&p1);
	mostraPilha(&p2);
	
}
