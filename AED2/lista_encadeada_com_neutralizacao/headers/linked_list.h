#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

#include "manipulationData.h"
#include "stdio.h"
#include <stdlib.h>

typedef struct typeNode{
  typeData chargeutil;
  struct typeNode* proximo; // sucessor
} TtypeNode;

typedef struct lista typeList;

struct lista{
  TtypeNode* inicio;
  int tamanho;
  // int qtde_consulta;
  // int qtde_remocao;
  // int qtde_insercao;
};

typeList* newList();
TtypeNode* newNode(typeData charge);
void imprimirtypeNode(TtypeNode* e);

// Operações baseadas em posição

void inserirInicioLSE(typeList* lse, typeData charge);
void inserirFinalLSE(typeList* lse, typeData charge);
typeData acessarLSE(typeList *l, int pos);
typeData removerInicioLSE(typeList *l);
typeData removerPosicaoLSE(typeList *l, int pos);
typeData removerFinalLSE(typeList *l);

// Operações baseadas em conteúdo
void imprimirLSE(typeList *l);
typeData buscarConteudoLSE(typeList* l, void *chaveBusca);
typeData removerConteudoLSE(typeList* l, void *chaveBusca);
void inserirConteudoLSE(typeList *l, typeData charge);
void destruirLSE(typeList* *rl);
int tamanhoLSE(typeList *l);

#endif