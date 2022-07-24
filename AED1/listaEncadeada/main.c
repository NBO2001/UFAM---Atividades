#include <stdio.h>
#include <stdlib.h>

typedef struct typeData{
    
    int d;

}typeData;

typedef struct typeNode{
    
    typeData data;
    struct typeNode * next;

}typeNode;

typedef struct typeList{

    typeNode * first;

}typeList;

// Create list
typeList * list(){

    typeList * lst;

    lst = (typeList * ) malloc(sizeof(typeList));

    lst->first = NULL;

    return lst;

}

// Create node
typeNode * node(typeData *dt){

    typeNode * nod;

    nod = (typeNode * ) malloc(sizeof(typeNode));

    nod->data = *dt;

    nod->next = NULL;

    return nod;

}

// Insert in list
void insert(typeList * lst, typeData dat){

    typeNode * nd;
    typeNode * aux;

    nd = node(&dat);

    aux = lst->first;
    nd->next = aux;
    lst->first = nd;

}

// Show only data
void showData(typeData *dat){

    printf("%d\n", dat->d);

}


// Show list
void showList(typeList * lst){
    
    typeNode * aux;

    aux = lst->first;

    while(aux){

        showData(&aux->data);

        aux = aux->next;
    }

}

int main(){

    typeList * l1;
    typeData n1;

    l1 = list();

    for(int i=0; i < 5; i++){
        n1.d = i;
        insert(l1,n1);
    }

    showList(l1);

}