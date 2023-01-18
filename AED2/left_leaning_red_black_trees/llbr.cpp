#include <iostream>
#include "llbr.h"

#define RED 1
#define BLACK 0

typeTree * newTree(){

    typeTree * tr;

    tr = (typeTree * ) malloc(sizeof(typeTree));

    tr->root = NULL;
    tr->cursor = NULL;

}

char its_full(typeNode * node){

    if(node->left and node->right){
        if(node->left->color == RED and node->right->color == RED){
            return true;
        }
        return false;

    }else{
        return false;
    }
}
void rotate_rigth(typeNode * node){

    typeNode * aux;

    aux = node->left;
    node->left = node->right;
    node->right = aux;

    aux->color = node->color;
    node->color = RED;

}


void insert(typeTree * tr, typeData * data){

    typeNode * aux, * tmp;

    aux = (typeNode * ) malloc(sizeof(typeNode));

    if( !tr->root ){
        
        aux->color = BLACK;
        aux->dt = *data;
        aux->left = NULL;
        aux->right = NULL;

        tr->root = aux;
        tr->cursor = aux;

        return;
    }else{

        tmp = tr->cursor;

        while (tmp)
        {
            if(!its_full(tmp)){

                aux->color = RED;
                aux->dt = *data;
                aux->left = NULL;
                aux->right = NULL;

                if(*data < tmp->dt){       
                    
                    if(!tmp->left) { tmp->left = aux; }
                    else{
                        
                    }
                    
                    return;

                }else{

                    tmp->right = aux;

                    return;

                }

            }
        }
        


    }
    

}