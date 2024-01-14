#ifndef LLRB_TREE_H
#define LLRB_TREE_H

typedef int (*functionCmp)(void*, void*);

typedef struct t_red t_red;

t_red* criarRED(functionCmp cmp);

void inserirRED(t_red* tree, void* data);
void removerRED(t_red* tree, void* data);
void* buscarRED(t_red* tree, void* data);

void estatisticaRED(t_red* tree);

#endif