#include "../headers/linked_list.h"

typeList* newList(){
  
  typeList* list = malloc(sizeof(typeList));

  list->inicio = NULL;
  list->tamanho = 0;

  return list;
}

TtypeNode* newNode(typeData charge){

  TtypeNode* elem = malloc(sizeof(TtypeNode));

  elem->chargeutil = charge;
  elem->proximo=NULL;

  return elem;
}

void imprimirtypeNode(TtypeNode* e){

  //printf("%lf %lf %d %d\n", e->lat, e->lgi, e->data, e->hora);
  //printf("%p", e->chargeutil);
  imprimirInfo(e->chargeutil);

}

void inserirInicioLSE(typeList* lse, typeData charge){
  TtypeNode *novo = newNode(charge);

  lse->tamanho++;
  if (lse->inicio == NULL){
    lse->inicio = novo;
  }else{
    novo->proximo = lse->inicio;
    lse->inicio = novo;
  }
}

void inserirFinalLSE(typeList* lse, typeData charge){
  TtypeNode *novo = newNode(charge);

  lse->tamanho++;
  if (lse->inicio == NULL){
    lse->inicio = novo;
  }else{
    TtypeNode *cam = lse->inicio;
    while (cam->proximo!=NULL){
      cam = cam->proximo;
    }
    cam->proximo = novo;
  }
}

typeData acessarLSE(typeList *l, int pos){
  TtypeNode *cam = NULL;
  typeData charge;
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

typeData removerInicioLSE(typeList *l){
  TtypeNode* elem;
  if (l->inicio == NULL){
    elem = NULL;
  }else{
    elem = l->inicio;
    l->inicio = elem->proximo;
    l->tamanho--;
  }
  typeData charge = elem->chargeutil;
  free(elem);
  return charge;
}

typeData removerPosicaoLSE(typeList *l, int pos){
    TtypeNode* removido=NULL;

    TtypeNode *ant=NULL;
    if( (pos<1) || (pos>l->tamanho) ){
      printf("ERRO: Fora do escopo\n");
      return emptyData();
    }
    TtypeNode *cam=l->inicio;
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

    typeData charge = removido->chargeutil;
    free(removido);
    return charge;
}

typeData removerFinalLSE(typeList *l){
  return removerPosicaoLSE(l, l->tamanho);
}

void imprimirLSE(typeList *l){

  TtypeNode* cam = l->inicio;
  printf("inicio da impressão\n");
  while(cam!=NULL){
    //printf("%p ", cam);
    imprimirInfo(cam->chargeutil);
    cam = cam->proximo;
  }
  printf("\n");
}

typeData buscarConteudoLSE(typeList* l, void *chaveBusca){
  TtypeNode *cam = l->inicio;

  while ((cam!=NULL) && ( compararInfo(cam->chargeutil, chaveBusca) !=0 ) ){
    cam = cam->proximo;
  }
  if (cam == NULL)
    return emptyData();
  else
    return cam->chargeutil;
}

typeData removerConteudoLSE(typeList* l, void *chaveBusca){
  TtypeNode *cam = l->inicio;
  TtypeNode *ant=NULL;
  while ((cam!=NULL) && (compararInfo(cam->chargeutil, chaveBusca)!=0) ){
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
    typeData charge = cam->chargeutil;
    free(cam);
    return charge;
  }else{
    return emptyData();
  }
}

void inserirConteudoLSE(typeList *l, typeData charge){
  TtypeNode* cam = l->inicio;
  TtypeNode* ant=NULL;
  TtypeNode *novo = newNode(charge);

  while( (cam != NULL) && (compararInfo(cam->chargeutil, &charge ) >= 0) ){
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
      typeData charge = removerInicioLSE(*rl);
      //free(charge);
  }
  free(*rl);
  *rl = NULL;
}

int tamanhoLSE(typeList *l){
  return l->tamanho;
}