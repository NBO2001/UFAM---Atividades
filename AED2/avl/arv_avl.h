#ifndef AVL_TREE_H
#define AVL_TREE_H

typedef int (*functionCmp)(void*, void*);

typedef struct t_avl t_avl;


t_avl* criarAVL(functionCmp cmp);

void inserirAVL(t_avl* tree, void* data);
void* removerAVL(t_avl* tree, void* data);
void* buscarAVL(t_avl* tree, void* data);

void estatisticaAVL(t_avl* tree);

#endif