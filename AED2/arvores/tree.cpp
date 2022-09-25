#include "iostream"
#include "tree.h"
#include "cstring"

using namespace std;

// Create new Tree.
void newTree(typeTree * tree){

    tree->root = NULL;
    tree->cursor = NULL;

}

// Create new leaf
typeLeaf * newLeaf(typeData * data){    

    typeLeaf * leaf;

    leaf = (typeLeaf * ) malloc( sizeof(typeLeaf) );

    leaf->data = *data;

    leaf->father = NULL;
    leaf->left = NULL;
    leaf->right = NULL;

    return leaf;
}

// Function that compares two types of data
char compare(typeData * a, typeData * b){

    if(a->age > b->age){
        return 1;
    }else if(a->age < b->age){
        return -1;
    }
    else{
        return 0;
    }
}

// Function that moves the cursor while there is element smaller than data or bigger than data.
char moveCursor(typeTree * tree, typeData * data){

    if(!tree->cursor){ return 0; }

    if(compare(&tree->cursor->data, data) == -1){
        if(tree->cursor->right){

            tree->cursor = tree->cursor->right;
            return 1;

        }else{
            return 0;
        }

    }else if(compare(&tree->cursor->data, data) == 0){
        return 0;
    }else{
        if(tree->cursor->left){

            tree->cursor = tree->cursor->left;
            return 1;
        }else{
            return 0;
        }
    }

}

void insertTree(typeTree * tree, typeData * data){

    typeLeaf * aux, * tmp;

    aux = tree->root;
    
    tmp = newLeaf(data);

    if(!aux){

        tree->root = tmp;
        tree->cursor = tmp;
        
        return;
    
    }

    tree->cursor = tree->root;

    while (moveCursor(tree, data));

    tmp->father = tree->cursor;

    if(compare(&tree->cursor->data, data) == -1){
        tree->cursor->right = tmp;
    }else{
        tree->cursor->left = tmp;
    }
    

}

void showData(typeData * data){

    printf("%d ", data->age);


}

void showLeaf(typeLeaf * leaf){
    
    if(leaf){
        
        showLeaf(leaf->left);
        showData(&leaf->data);
        showLeaf(leaf->right);
        
        return;
    }


}

void showTree(typeTree * tree){

    tree->cursor = tree->root;

    showLeaf(tree->cursor);

}

typeData * predecessor(typeTree * tree, typeData * data){

    typeLeaf * tmp;
    typeData * dtTemp;

    tmp = tree->cursor;

    dtTemp = NULL;

    tree->cursor = tree->root;

    moveCursor(tree, data);


    if(tree->cursor->left){
        
        tree->cursor = tree->cursor->left;

        while (tree->cursor->right)
        {
            tree->cursor = tree->cursor->right;
        }
        
        dtTemp = &tree->cursor->data;
        

    }

    tree->cursor = tmp;

    return dtTemp;

}

typeData * successor(typeTree * tree, typeData * data){

    typeLeaf * tmp;
    typeData * dtTemp;

    tmp = tree->cursor;

    dtTemp = NULL;

    tree->cursor = tree->root;

    moveCursor(tree, data);


    if(tree->cursor->right){
        
        tree->cursor = tree->cursor->right;

        while (tree->cursor->left)
        {
            tree->cursor = tree->cursor->left;
        }
        
        dtTemp = &tree->cursor->data;
        

    }

    tree->cursor = tmp;

    return dtTemp;

}

