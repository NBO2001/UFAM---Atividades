#include <stdlib.h>
#include <stdio.h>
#include "arv_red.h"

#define RED 1
#define BLACK 0
#define NULL_LEAF -1
typedef struct Node{

    void* data;
    short color;
    struct Node * left, * right;

}Node;

typedef struct Stat{
  int i_nro;
  int b_nro;
  int r_nro;  
  int b_cmps;
  int i_cmps;
  int r_cmps;
} Stat;

struct t_red{

    Node *root;
    functionCmp cmp;
    Stat* stat;

};

t_red* criarRED(functionCmp cmp){

    t_red* tree = malloc(sizeof(t_red));

    if(tree){

        tree->cmp = cmp;
        tree->root = NULL;
        tree->stat = calloc(1,sizeof(Stat));
        return tree;
    }

    return NULL;

}

static short _isNullLeaf(Node * node){ if(!node) return NULL_LEAF; else return 0; }
static short _isBlack(Node * node){ if(!node) return RED; return !node->color; }
static short _isRed(Node * node){   if(!node) return BLACK; return node->color;}
static short _itsFull(Node * node){ return ( (node->left && _isRed(node->left)) && (node->right && _isRed(node->right)) ); }
static short _isNecessaryRotateLeft(Node * node){ return ( (!node->left || !_isRed(node->left) ) && ( node->right && _isRed(node->right) )) ; }
static short _isNecessaryRotateRight(Node * node){ return ( node->left && _isRed(node->left) && node->left->left && _isRed(node->left->left) );}


Node*  _rotateLeft(Node * node){

    Node * tmp = node->right;
    node->right = tmp->left;
    tmp->left = node;
    tmp->color = node->color;
    node->color = RED;

    return tmp;
}

Node *  _rotateRight(Node * node){

    Node * tmp = node->left;
    node->left = tmp->right;
    tmp->right = node;

    tmp->color = node->color;
    node->color = RED;

    return tmp;
}


void  _flipColors(Node * h){

    h->color = !h->color;
    h->left->color = !h->left->color;
    h->right->color = !h->right->color;

}

Node * _newNode(void* info){

    Node * newNode = malloc(sizeof(Node));
    newNode->data = info;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->color = RED;
    
    return newNode;
}

Node * _insertRecusive(Node * node, void* info, functionCmp cmp, Stat* stat){

    if(!node) return _newNode(info);

    if(_itsFull(node)) _flipColors(node);

    if(cmp(node->data, info) > 0){
        stat->i_cmps+=1;
        node->left = _insertRecusive(node->left,info, cmp, stat);
    }
    else if(cmp(node->data, info) < 0){
        stat->i_cmps+=2;
        node->right = _insertRecusive(node->right,info, cmp, stat);
    }

    if(_isNecessaryRotateLeft(node)){
        stat->i_nro += 1;
        node = _rotateLeft(node);
    }
    if(_isNecessaryRotateRight(node)){
        stat->i_nro += 1;
        node = _rotateRight(node);
    }

    if(_itsFull(node)) _flipColors(node);

    return node;
 
}

void inserirRED(t_red* tree, void* data){
    tree->root = _insertRecusive(tree->root, data, tree->cmp, tree->stat);
    tree->root->color = BLACK;
}

void* buscarRED(t_red* tree, void* data){

    Node* aux = tree->root;

    short findend = 0;

    void* valueRt = NULL;

    while (aux && !findend){

        if(tree->cmp(aux->data, data) > 0){
            tree->stat->b_cmps += 1;
            aux= aux->left;
        }else if(tree->cmp(aux->data, data) < 0){
            tree->stat->b_cmps += 2;
            aux= aux->right;
        }else{
            tree->stat->b_cmps += 2;
            findend = 1;
            valueRt = aux->data;
        }
    
    }


    return valueRt;

}

Node* fixUp(Node* h, Stat* stat) {

	if (_isRed(h->right)) {
		h = _rotateLeft(h);
        stat->r_nro += 1;
	}

	if (h->left && _isRed(h->left) && _isRed(h->left->left) ) {
		h = _rotateRight(h);
        stat->r_nro += 1;
	}

	if ( _isRed(h->left) && _isRed(h->right) ){
		_flipColors(h);
	}

	return h;
}

Node* moveRedLeft(Node* h, Stat* stat){

    if(!h) return h;

    _flipColors(h);

    Node* left = h->right->left;

    if(!left) return h;

    if(_isRed(h->right->left)){
      
        h->right = _rotateRight(h->right);
        h = _rotateLeft(h);
        stat->r_nro += 2;
        _flipColors(h);
    }
    
    return h;
}

Node* moveRedRight(Node* h, Stat* stat){

    if(!h) return h;

    _flipColors(h);

    if(!h->left->left) return h;

    if(_isRed(h->left->left)){
        stat->r_nro += 1;
        h = _rotateRight(h);
        _flipColors(h);
    }

    return h;

}

Node* minNode(Node* start){

    Node* tmp = start;

    while(tmp->left != NULL) tmp = tmp->left;
    return tmp;
}

Node* _deleteMin(Node* h, Stat* stat){

    if(h->left == NULL) return NULL;

    if(!_isRed(h->left) && !_isRed(h->left->left)){
        h = moveRedLeft(h, stat);
    }

    h->left = _deleteMin(h->left, stat);

    return fixUp(h, stat);

}


Node* _removeRecursive(Node* h, void* data, functionCmp cmp, Stat* stat) {
    if (!h)
        return h;

    if (cmp(h->data, data) > 0) {
        stat->r_cmps += 1;
        if ( h->left && !_isRed(h->left) && !_isRed(h->left->left))
            h = moveRedLeft(h, stat);
        h->left = _removeRecursive(h->left, data, cmp, stat);
    } else {
        
        if (_isRed(h->left)){
            stat->r_nro += 1;
            h = _rotateRight(h);
        }
            
        if (cmp(h->data, data) == 0 && (h->right == NULL)){
            stat->r_cmps += 2;
            return NULL;
        }
            
        if (h->right && !_isRed(h->right) && !_isRed(h->right->left))
            h = moveRedRight(h, stat);

        if (cmp(h->data, data) == 0) {
            stat->r_cmps += 3;
            Node* min = minNode(h->right);
            h->data = min->data;
            h->right = _deleteMin(h->right, stat);
        } else {
            h->right = _removeRecursive(h->right, data, cmp, stat);
        }
    }

    return fixUp(h, stat);
}

void removerRED(t_red* tree, void* data) {
    if (tree->root) {
        tree->root = _removeRecursive(tree->root, data, tree->cmp, tree->stat);
        if (tree->root)
            tree->root->color = BLACK;
    }
}


void estatisticaRED(t_red* tree){
    
    printf("I: {Cmp=%d, Rot: %d}, B: {Cmp=%d, Rot: %d}, R: {Cmp=%d, Rot: %d}\n",
    tree->stat->i_cmps,tree->stat->i_nro,tree->stat->b_cmps,tree->stat->b_nro, tree->stat->r_cmps,tree->stat->r_nro);
}

void* getRoot(t_red* tree){
    if(!tree->root) return NULL;
    return tree->root->data;
}

