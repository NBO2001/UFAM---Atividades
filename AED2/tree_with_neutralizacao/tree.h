#ifndef TREE_H
#define TREE_H

#include <stdlib.h>

typedef struct typeNode{

    void * data;
    struct typeNode * next;

} typeNode;

typedef struct typeList{

    typeNode * first;

}typeList;


// Create list
void create(typeList * list);

// Insert in list
void insert(typeList * list, void * data);

// show list
void show_list(typeList * list, void (*showData)(void*));



#endif


