#include "linked_list.h"
#include "stdio.h"
#include <stdlib.h>


typeList* newList(void* compare, void* print){
  
  typeList* list = malloc(sizeof(typeList));

  typeCompare comp = compare;
  typePrint prin = print;
  list->inicio = NULL;
  list->compare = comp;
  list->print = prin;
  list->tamanho = 0;

  return list;
}

typeNode* newNode(void* charge){

  typeNode* elem = malloc(sizeof(typeNode));

  elem->chargeutil = charge;
  elem->proximo=NULL;

  return elem;
}

void imprimirtypeNode(typeNode* e){

  //printf("%lf %lf %d %d\n", e->lat, e->lgi, e->data, e->hora);
  printf("%p", e->chargeutil);
  //imprimirInfo(e->chargeutil);

}

void inserirInicioLSE(typeList* lse, void* charge){
  
  typeNode *novo = newNode(charge);
  
  (lse->tamanho)++;
    
  if ( (lse->inicio == NULL ) ){
    
    lse->inicio = novo;

  }else{

    novo->proximo = lse->inicio;
    lse->inicio = novo;
    
  }
}

void inserirFinalLSE(typeList* lse, void* charge){
  typeNode *novo = newNode(charge);

  lse->tamanho++;
  if (lse->inicio == NULL){
    lse->inicio = novo;
  }else{
    typeNode *cam = lse->inicio;
    while (cam->proximo!=NULL){
      cam = cam->proximo;
    }
    cam->proximo = novo;
  }
}

void* acessarLSE(typeList *l, int pos){
  typeNode *cam = NULL;
  void* charge;
  if( (pos>=1) && (pos<=l->tamanho) ){
    int i=1;
    cam = l->inicio;
    while(i<pos){
      i++;
      cam = cam->proximo;
    }
    charge =   cam->chargeutil;
  }
  return charge;
}

void* removerInicioLSE(typeList *l){
  typeNode* elem;
  if (l->inicio == NULL){
    elem = NULL;
  }else{
    elem = l->inicio;
    l->inicio = elem->proximo;
    l->tamanho--;
  }
  void* charge = elem->chargeutil;
  free(elem);
  return charge;
}

void* removerPosicaoLSE(typeList *l, int pos){
    typeNode* removido=NULL;

    typeNode *ant=NULL;
    if( (pos<1) || (pos>l->tamanho) ){
      printf("ERRO: Fora do escopo\n");
      return NULL;
    }
    typeNode *cam=l->inicio;
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

    void* charge = removido->chargeutil;
    free(removido);
    return charge;
}

void* removerFinalLSE(typeList *l){
  return removerPosicaoLSE(l, l->tamanho);
}

void imprimirLSE(typeList *l){

  typeNode* cam = l->inicio;
  printf("inicio da impressão\n");
  while(cam!=NULL){
    
    l->print(cam->chargeutil);
    cam = cam->proximo;
  }
  printf("\n");
}

void* buscarConteudoLSE(typeList* l, void *chaveBusca){
  typeNode *cam = l->inicio;

  while ((cam!=NULL) && ( l->compare(cam->chargeutil, chaveBusca) !=0 ) ){
    cam = cam->proximo;
  }
  if (cam == NULL)
    return NULL;
  else
    return cam->chargeutil;
}

void* removerConteudoLSE(typeList* l, void *chaveBusca){
  typeNode *cam = l->inicio;
  typeNode *ant=NULL;
  while ((cam!=NULL) && (l->compare(cam->chargeutil, chaveBusca)!=0) ){
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
    void* charge = cam->chargeutil;
    free(cam);
    return charge;
  }else{
    return NULL;
  }
}

void inserirConteudoLSE(typeList *l, void* charge){
  typeNode* cam = l->inicio;
  typeNode* ant=NULL;
  typeNode *novo = newNode(charge);

  while( (cam != NULL) && (l->compare(cam->chargeutil, &charge ) >= 0) ){
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

void destruirLSE(typeList* *rl){

  while((*rl)->inicio != NULL){
      void* charge = removerInicioLSE(*rl);
      //free(charge);
  }
  free(*rl);
  *rl = NULL;
}

int tamanhoLSE(typeList *l){
  return l->tamanho;
}