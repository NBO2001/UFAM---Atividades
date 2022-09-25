#ifndef _TREE_H
#define _TREE_H

typedef struct typeData{

    int age;

}typeData;

typedef struct typeLeaf{

    typeData data;
    struct typeLeaf *left;
    struct typeLeaf *right;
    struct typeLeaf *father;

}typeLeaf;

typedef struct typeTree{

    typeLeaf * root;
    typeLeaf * cursor;

}typeTree;

void newTree(typeTree * tree);
typeLeaf * newLeaf(typeData * data);


// Create new Tree.
void newTree(typeTree * tree);

// Create new leaf
typeLeaf * newLeaf(typeData * data);

// Function that compares two types of data
char compare(typeData * a, typeData * b);

// Function that moves the cursor while there is element smaller than data or bigger than data.
char moveCursor(typeTree * tree, typeData * data);

void insertTree(typeTree * tree, typeData * data);

void showData(typeData * data);

void showLeaf(typeLeaf * leaf);

void showTree(typeTree * tree);

typeData * predecessor(typeTree * tree, typeData * data);

typeData * successor(typeTree * tree, typeData * data);

#endif