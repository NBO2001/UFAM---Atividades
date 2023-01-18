#include "stdlib.h"
#include "typeTree.h"
#include <stdio.h>
#define RED 1
#define BLACK 0


typedef struct typeNode{

    int data;
    short color;
    struct typeNode * father;
    struct typeNode * left, * right;

}typeNode;

struct typeTreeRedAndBlack{

    typeNode *root;

};


typeTreeRedAndBlack * newTreeRB(){

    typeTreeRedAndBlack * tree = malloc(sizeof(typeTreeRedAndBlack));

    tree->root = NULL;

    return tree;

}

short _isBlack(typeNode * node){ return !node->color; }
short _isRed(typeNode * node){ return node->color; }
short _itsFull(typeNode * node){ return ( (node->left && _isRed(node->left)) && (node->right && _isRed(node->right)) ); }
short _isNecessaryRotateLeft(typeNode * node){ return ( (!node->left || !_isRed(node->left) ) && ( node->right && _isRed(node->right) )) ; }
short _isNecessaryRotateRight(typeNode * node){ return ( node->left && _isRed(node->left) && node->left->left && _isRed(node->left->left) );}

typeNode *  _roteteLeft(typeNode * node){

    typeNode * tmp = node->right;
    node->right = tmp->left;
    tmp->left = node;
    tmp->color = node->color;
    node->color = RED;

    return tmp;
}

typeNode *  _rotateRight(typeNode * node){

    typeNode * tmp = node->left;
    node->left = tmp->right;
    tmp->right = node;

    tmp->color = node->color;
    node->color = RED;

    return tmp;
}

void  _flipColors(typeNode * node){

    node->color = !node->color;
    node->left->color = !node->left->color;
    node->right->color = !node->right->color;

}

typeNode * _newNode(int info){

    typeNode * newNode = malloc(sizeof(typeNode));
    newNode->data = info;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->color = RED;
    newNode->father = NULL;
    return newNode;

}

typeNode * _insertRecusive(typeNode * node, int info){

    if(!node) return _newNode(info);

    if(_itsFull(node)) _flipColors(node);

    if(node->data > info) node->left = _insertRecusive(node->left,info);
    else if(node->data > info) node->right = _insertRecusive(node->right,info);

    if(_isNecessaryRotateLeft(node)) node = _roteteLeft(node);
    if(_isNecessaryRotateRight(node)) node = _rotateRight(node);

    return node;
 
}

void insertTreeRB(typeTreeRedAndBlack * tree, int info){

    tree->root = _insertRecusive(tree->root, info);
    tree->root->color = BLACK;
}

int searchTreeRB(typeTreeRedAndBlack * tree, int info){

    typeNode * aux = tree->root;

    short findend = 0;

    int valueRt = -1;

    while (aux && !findend){

        if(aux->data > info){
            aux= aux->left;
        }else if(aux->data < info){
            aux= aux->right;
        }else{
            findend = 1;
            valueRt = aux->data;
        }
    
    }


    return valueRt;

}
