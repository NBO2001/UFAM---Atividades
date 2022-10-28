#include <stdio.h>
#include "tree.h"

// Create list
void create(typeList * list){

    list->first = NULL;

}

// Insert in list
void insert(typeList * list, void * data){

    typeNode * newNode;

    newNode = (typeNode * ) malloc(sizeof(newNode));

    newNode->data = data;

    newNode->next = list->first;

    list->first = newNode;

}

// show list
void show_list(typeList * list, void (*showData)(void*)){

    typeNode * aux;

    aux = list->first;

    while (aux)
    {
        showData(aux->data);
        aux = aux->next;
    }

}