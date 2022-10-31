#include "stdio.h"
#include "stdlib.h"
//#include "lista.h"
//typedef struct lista TListaSE;

typedef struct {
  long int rg;
  double altura;
  int idade;
  double peso;
} TInfo;

void imprimirInfo(TInfo info){

  //printf("%d %lf\n", info.matricula, info.nota);
  printf("%ld %lf %lf %d\n", info.rg, info.altura, info.peso, info.idade);
  //printf("Vou imprimir a informação\n");

}

int compararInfo(TInfo info, void* chaveBusca){
  long int* rg = chaveBusca;

  return info.rg - *rg;
}


typedef struct elementoLSE{
  TInfo cargautil;
  struct elementoLSE* proximo; // sucessor
} TElementoLSE;

typedef struct lista TListaSE;
struct lista{
  TElementoLSE* inicio;
  int tamanho;
  // int qtde_consulta;
  // int qtde_remocao;
  // int qtde_insercao;
};

TListaSE* criarLSE(){
  TListaSE* lista = malloc(sizeof(TListaSE));

  lista->inicio = NULL;
  lista->tamanho = 0;

  return lista;
}

TElementoLSE* criarElementoLSE(TInfo carga){
  TElementoLSE* elem = malloc(sizeof(TElementoLSE));

  elem->cargautil = carga;
  elem->proximo=NULL;

  return elem;
}

void imprimirElementoLSE(TElementoLSE* e){

  //printf("%lf %lf %d %d\n", e->lat, e->lgi, e->data, e->hora);
  //printf("%p", e->cargautil);
  imprimirInfo(e->cargautil);

}

// Operações baseadas em posição

void inserirInicioLSE(TListaSE* lse, TInfo carga){
  TElementoLSE *novo = criarElementoLSE(carga);

  lse->tamanho++;
  if (lse->inicio == NULL){
    lse->inicio = novo;
  }else{
    novo->proximo = lse->inicio;
    lse->inicio = novo;
  }
}

void inserirFinalLSE(TListaSE* lse, TInfo carga){
  TElementoLSE *novo = criarElementoLSE(carga);

  lse->tamanho++;
  if (lse->inicio == NULL){
    lse->inicio = novo;
  }else{
    TElementoLSE *cam = lse->inicio;
    while (cam->proximo!=NULL){
      cam = cam->proximo;
    }
    cam->proximo = novo;
  }
}

TInfo acessarLSE(TListaSE *l, int pos){
  TElementoLSE *cam = NULL;
  TInfo carga;
  if( (pos>=1) && (pos<=l->tamanho) ){
    int i=1;
    cam = l->inicio;
    while(i<pos){
      i++;
      cam = cam->proximo;
    }
    carga =   cam->cargautil;
  }
  return carga;
}

TInfo removerInicioLSE(TListaSE *l){
  TElementoLSE* elem;
  if (l->inicio == NULL){
    elem = NULL;
  }else{
    elem = l->inicio;
    l->inicio = elem->proximo;
    l->tamanho--;
  }
  TInfo carga = elem->cargautil;
  free(elem);
  return carga;
}

TInfo removerPosicaoLSE(TListaSE *l, int pos){
    TElementoLSE* removido=NULL;

    TElementoLSE *ant=NULL;
    if( (pos<1) || (pos>l->tamanho) ){
      printf("ERRO: Fora do escopo\n");
      return (TInfo){};
    }
    TElementoLSE *cam=l->inicio;
    int i=1;
    while(i<pos){
      ant = cam;
      cam = cam->proximo;
      i++;
    }
    if (ant==NULL){
      removido = l->inicio;
      // atualizando a descrição da lista (o novo inicio)
      l->inicio = removido->proximo;
    }else{
      removido = cam;
      ant->proximo = removido->proximo;
    }
    // atualizando a descrição da lista (reduzir o tamanho)
    l->tamanho--;

    TInfo carga = removido->cargautil;
    free(removido);
    return carga;
}

TInfo removerFinalLSE(TListaSE *l){
  return removerPosicaoLSE(l, l->tamanho);
}

// Operações baseadas em conteúdo

void imprimirLSE(TListaSE *l){

  TElementoLSE* cam = l->inicio;
  printf("inicio da impressão\n");
  while(cam!=NULL){
    //printf("%p ", cam);
    imprimirInfo(cam->cargautil);
    cam = cam->proximo;
  }
  printf("\n");
}

TInfo buscarConteudoLSE(TListaSE* l, void *chaveBusca){
  TElementoLSE *cam = l->inicio;

  while ((cam!=NULL) && ( compararInfo(cam->cargautil, chaveBusca) !=0 ) ){
    cam = cam->proximo;
  }
  if (cam == NULL)
    return (TInfo){};
  else
    return cam->cargautil;
}

TInfo removerConteudoLSE(TListaSE* l, void *chaveBusca){
  TElementoLSE *cam = l->inicio;
  TElementoLSE *ant=NULL;
  while ((cam!=NULL) && (compararInfo(cam->cargautil, chaveBusca)!=0) ){
    ant = cam;
    cam = cam->proximo;
  }

  if (cam!=NULL){  // encontrou o elemento
    if(l->inicio == cam){ // removendo o primeiro da lista (no inicio)
      l->inicio = cam->proximo;
      l->tamanho--;
    }else{ // removendo um intermediario
      ant->proximo = cam->proximo;
      l->tamanho--;
    }
    TInfo carga = cam->cargautil;
    free(cam);
    return carga;
  }else{
    return (TInfo){};
  }
}

void inserirConteudoLSE(TListaSE *l, TInfo carga){
  TElementoLSE* cam = l->inicio;
  TElementoLSE* ant=NULL;
  TElementoLSE *novo = criarElementoLSE(carga);

  while( (cam != NULL) && (compararInfo(cam->cargautil, &carga ) >= 0) ){
    ant = cam;
    cam = cam->proximo;
  }

  if (l->inicio == cam){ //
    l->inicio = novo;
    novo->proximo = cam;
    l->tamanho++;
  } else{
    novo->proximo = cam;
    ant->proximo = novo;
    l->tamanho++;
  }

}

void destruirLSE(TListaSE* *rl){

  while((*rl)->inicio != NULL){
      TInfo carga = removerInicioLSE(*rl);
      //free(carga);
  }
  free(*rl);
  *rl = NULL;
}

int tamanhoLSE(TListaSE *l){
  return l->tamanho;
}


int main(int argc, char const *argv[]) {
  long int rg;
  double peso, altura;
  int idade;

  TListaSE* lista_notas = criarLSE();
  scanf("%ld", &rg);
  while(rg > 0){
    scanf("%lf %lf %d", &altura, &peso, &idade);

    TInfo novo = (TInfo){.rg=rg,
                         .peso=peso,
                         .altura = altura,
                         .idade = idade
                       };

    inserirFinalLSE(lista_notas, novo);
    scanf("%ld", &rg);
  }
  imprimirLSE(lista_notas);

  return 0;

}
