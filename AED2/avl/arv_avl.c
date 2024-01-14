#include <stdlib.h>
#include "arv_avl.h"
#include <stdio.h>

typedef struct Node{

    void* data;
    int height;
    
    struct Node* childrenLeft;
    struct Node* childrenRigth;
}Node;

typedef struct Stat{
  int i_nro;
  int b_nro;
  int r_nro;  
  int b_cmps;
  int i_cmps;
  int r_cmps;
} Stat;

void* removeRet = NULL;

struct t_avl{

    Node* root;
    functionCmp cmp;
    Stat* stat;

};

int getHeigth(Node* node){

    if(!node) return 0;

    return node->height;

}

int isBalence(Node* node){

    if(!node) return 0;
    
    return getHeigth(node->childrenLeft) - getHeigth(node->childrenRigth);

}

Node* newNode(void* data){

    Node* node = malloc(sizeof(Node));

    if(node){

        node->data = data;
        node->height = 1;
        
        node->childrenLeft  = NULL;
        node->childrenRigth = NULL;
    }

}

t_avl* criarAVL(functionCmp cmp){

    t_avl* tree = malloc(sizeof(t_avl));

    if(tree){
        tree->cmp = cmp;
        tree->root = NULL;
        tree->stat = calloc(1,sizeof(Stat));
        return tree;

    }else return NULL;

}

int max(int a, int b)
{
    return (a > b)? a : b;
}

Node* rightRotate(Node* node){
    
    Node* childLeft = node->childrenLeft;
    
    node->childrenLeft = childLeft->childrenRigth;
    childLeft->childrenRigth = node;

      // Update heights
    node->height = max(getHeigth(node->childrenLeft), getHeigth(node->childrenRigth)) + 1;

    childLeft->height = max(getHeigth(childLeft->childrenLeft), getHeigth(childLeft->childrenRigth)) + 1;

    return childLeft;
    
}

Node* leftRotate(Node* node){

    Node* childRight = node->childrenRigth;

    node->childrenRigth = childRight->childrenLeft;
    childRight->childrenLeft = node;

    node->height = max(getHeigth(node->childrenLeft), getHeigth(node->childrenRigth)) + 1;

    childRight->height = max(getHeigth(childRight->childrenLeft), getHeigth(childRight->childrenRigth)) + 1;

    return childRight;
}

Node* insertRAVL(Node* node, void* data, functionCmp cmp, Stat* stat){

    if(!node) return newNode(data);

    if(cmp(node->data, data) < 0){
        // Inserir compação
        stat->i_cmps++;
        node->childrenRigth = insertRAVL(node->childrenRigth, data, cmp, stat); 
    }else if(cmp(node->data, data) > 0){
        // Inserir compação
        stat->i_cmps+=2;
        node->childrenLeft = insertRAVL(node->childrenLeft, data, cmp, stat); 
    }else{
        stat->i_cmps+=2;
        return node;
    }

    node->height = max(getHeigth(node->childrenLeft), getHeigth(node->childrenRigth)) + 1;

    int isBal = isBalence(node);
    
    if(isBal > 1 && cmp(node->childrenLeft->data, data) > 0){
        // Contar Rotação
        stat->i_cmps++;
        stat->i_nro++;
        return rightRotate(node);
    }

    if(isBal < -1 && cmp(node->childrenRigth->data, data) < 0){
        // Rotação
        stat->i_nro++;
        stat->i_cmps++;
        return leftRotate(node);
    }

    if(isBal > 1 && cmp(node->childrenLeft->data, data) < 0){
        // Contar Rotação
        stat->i_nro+=2;
        stat->i_cmps++;
        node->childrenLeft = rightRotate(node->childrenLeft);
        return leftRotate(node);
    }


    if(isBal < -1 && cmp(node->childrenRigth->data, data) > 0){
        stat->i_nro+=2;
        stat->i_cmps++;
        node->childrenRigth = rightRotate(node->childrenRigth);
        return leftRotate(node);
    }

    return node;

}

void inserirAVL(t_avl* tree, void* data){
    
    tree->root = insertRAVL(tree->root, data, tree->cmp, tree->stat);

}

Node* _minNodeAVL(Node* start){

    Node* tmp = start;

    while(tmp->childrenLeft != NULL) tmp = tmp->childrenLeft;
    return tmp;
}

Node* removeRAVL(Node* node, void* key, functionCmp cmp, Stat* stat){

    if(!node) return node;
    
    if(cmp(node->data, key) > 0){
        
        stat->r_cmps++;
        node->childrenLeft = removeRAVL(node->childrenLeft, key, cmp, stat);

    }else if(cmp(node->data, key) < 0){
        stat->r_cmps += 2;
        node->childrenRigth = removeRAVL(node->childrenRigth, key, cmp, stat);
    }else{
        stat->r_cmps += 2;
        removeRet = node->data;
        
        if(node->childrenLeft == NULL || node->childrenRigth == NULL){

            Node* tmp_node = node->childrenLeft != NULL? node->childrenLeft: node->childrenRigth;

            if(!tmp_node){

                tmp_node = node;
                node = NULL;

            }else{
                *node = *tmp_node;
            }

            free(tmp_node);
        }else{

            Node* tmp_node = _minNodeAVL(node->childrenRigth);

            node->data = tmp_node->data;

            node->childrenRigth = removeRAVL(node->childrenRigth, tmp_node->data, cmp, stat);

        }

    }

    if(node == NULL) return node;

    node->height = max(getHeigth(node->childrenLeft), getHeigth(node->childrenRigth)) + 1;

    int isBal = isBalence(node);


    if(isBal > 1 && isBalence(node->childrenLeft) >= 0){
        stat->r_nro++;
        return rightRotate(node);
    }
    if(isBal > 1 && isBalence(node->childrenLeft) <= 0){
        stat->r_nro+=2;
        node->childrenLeft = leftRotate(node->childrenLeft);
        return rightRotate(node);
    }

    if(isBal < -1 && isBalence(node->childrenRigth) <= 0){
        stat->r_nro++;
        return leftRotate(node);
    }

    if(isBal < -1 && isBalence(node->childrenRigth) > 0){
        stat->r_nro+=2;
        node->childrenRigth = rightRotate(node->childrenRigth);
        return leftRotate(node);

    }

    return node;

}
void* removerAVL(t_avl* tree, void* data){
    
    tree->root = removeRAVL(tree->root, data, tree->cmp, tree->stat);
    Node* tmp = removeRet;
    removeRet = NULL;
    return tmp;

}

void* buscarAVL(t_avl* tree, void* data){

    Node* aux = tree->root;

    while(aux){
        
        if(tree->cmp(aux->data, data) > 0){
            tree->stat->b_cmps++;
            aux = aux->childrenLeft;
        }else if(tree->cmp(aux->data, data) < 0){
            tree->stat->b_cmps+=2;
            aux = aux->childrenRigth;
        }else{
            tree->stat->b_cmps += 2;
            return aux->data;
        }

    }
    return NULL;

}

void printRTree(Node* node){

    if(!node) return;

    printRTree(node->childrenLeft);
    printf(" %p ->", node->data);
    printRTree(node->childrenRigth);

}
void printTree(t_avl* tree){
    printRTree(tree->root);
    printf("\n");
}

void estatisticaAVL(t_avl* tree){

    printf("I: {Cmp=%d, Rot: %d}, B: {Cmp=%d, Rot: %d}, R: {Cmp=%d, Rot: %d}\n",
    tree->stat->i_cmps,tree->stat->i_nro,tree->stat->b_cmps,tree->stat->b_nro, tree->stat->r_cmps,tree->stat->r_nro);
    
}
