#include "../headers/linked_list.h"

typeList* criarLSE(){
  
  typeList* lista = malloc(sizeof(typeList));

  lista->inicio = NULL;
  lista->tamanho = 0;

  return lista;
}

TtypeNode* criartypeNode(typeData carga){
  TtypeNode* elem = malloc(sizeof(TtypeNode));

  elem->cargautil = carga;
  elem->proximo=NULL;

  return elem;
}

void imprimirtypeNode(TtypeNode* e){

  //printf("%lf %lf %d %d\n", e->lat, e->lgi, e->data, e->hora);
  //printf("%p", e->cargautil);
  imprimirInfo(e->cargautil);

}

void inserirInicioLSE(typeList* lse, typeData carga){
  TtypeNode *novo = criartypeNode(carga);

  lse->tamanho++;
  if (lse->inicio == NULL){
    lse->inicio = novo;
  }else{
    novo->proximo = lse->inicio;
    lse->inicio = novo;
  }
}

void inserirFinalLSE(typeList* lse, typeData carga){
  TtypeNode *novo = criartypeNode(carga);

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
  typeData carga;
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

typeData removerInicioLSE(typeList *l){
  TtypeNode* elem;
  if (l->inicio == NULL){
    elem = NULL;
  }else{
    elem = l->inicio;
    l->inicio = elem->proximo;
    l->tamanho--;
  }
  typeData carga = elem->cargautil;
  free(elem);
  return carga;
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

    typeData carga = removido->cargautil;
    free(removido);
    return carga;
}

typeData removerFinalLSE(typeList *l){
  return removerPosicaoLSE(l, l->tamanho);
}

void imprimirLSE(typeList *l){

  TtypeNode* cam = l->inicio;
  printf("inicio da impressão\n");
  while(cam!=NULL){
    //printf("%p ", cam);
    imprimirInfo(cam->cargautil);
    cam = cam->proximo;
  }
  printf("\n");
}

typeData buscarConteudoLSE(typeList* l, void *chaveBusca){
  TtypeNode *cam = l->inicio;

  while ((cam!=NULL) && ( compararInfo(cam->cargautil, chaveBusca) !=0 ) ){
    cam = cam->proximo;
  }
  if (cam == NULL)
    return emptyData();
  else
    return cam->cargautil;
}

typeData removerConteudoLSE(typeList* l, void *chaveBusca){
  TtypeNode *cam = l->inicio;
  TtypeNode *ant=NULL;
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
    typeData carga = cam->cargautil;
    free(cam);
    return carga;
  }else{
    return emptyData();
  }
}

void inserirConteudoLSE(typeList *l, typeData carga){
  TtypeNode* cam = l->inicio;
  TtypeNode* ant=NULL;
  TtypeNode *novo = criartypeNode(carga);

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

void destruirLSE(typeList* *rl){

  while((*rl)->inicio != NULL){
      typeData carga = removerInicioLSE(*rl);
      //free(carga);
  }
  free(*rl);
  *rl = NULL;
}

int tamanhoLSE(typeList *l){
  return l->tamanho;
}