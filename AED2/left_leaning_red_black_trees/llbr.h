#ifndef LLBR_H
#define LLBR_H

typedef int typeData;

typedef struct typeNode{

    typeData dt;
    bool color; 
    struct typeNode * left;
    struct typeNode * right;

}typeNode;

typedef struct typeTree{

    typeNode * root;
    typeNode * cursor;

}typeTree;

// Create type tree
typeTree * newTree();

// insert element in tree
void insert(typeTree * tr, typeData * data);

//Verify if node is full
char its_full(typeNode * node);

// Rotate right
void rotate_rigth(typeNode * node);

#endif