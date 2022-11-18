#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

typedef void (*typePrint)(void*);
typedef int (*typeCompare)(void*, void *);

typedef struct typeNode{
  void* chargeutil;
  struct typeNode* proximo; // sucessor
} typeNode;


typedef struct typeList{
  typeNode* inicio;
  typeCompare compare;
  typePrint print;
  int tamanho;
  // int qtde_consulta;
  // int qtde_remocao;
  // int qtde_insercao;
}typeList;

typeList* newList(void* compare, void* print);
typeNode* newNode(void* charge);
void imprimirtypeNode(typeNode* e);

// Operações baseadas em posição

void inserirInicioLSE(typeList* lse, void* charge);
void inserirFinalLSE(typeList* lse, void* charge);
void* acessarLSE(typeList *l, int pos);
void* removerInicioLSE(typeList *l);
void* removerPosicaoLSE(typeList *l, int pos);
void* removerFinalLSE(typeList *l);

// Operações baseadas em conteúdo
void imprimirLSE(typeList *l);
void* buscarConteudoLSE(typeList* l, void *chaveBusca);
void* removerConteudoLSE(typeList* l, void *chaveBusca);
void inserirConteudoLSE(typeList *l, void* charge);
void destruirLSE(typeList* *rl);
int tamanhoLSE(typeList *l);

#endif