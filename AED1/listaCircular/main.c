#include <stdio.h>
#include <stdlib.h>

typedef int typeData;

typedef struct typeNode{

    typeData data;
    struct typeNode * next;

}typeNode;

typedef struct typeList{

    typeNode * now;

}typeList;

typeList * list(){

    typeList * l1;

    l1 = (typeList * ) malloc(sizeof(typeList));

    l1->now = NULL;

    return l1;

}

typeNode * node(typeData *d){

    typeNode * n1;

    n1 = (typeNode * ) malloc(sizeof(typeNode));

    n1->data = *d;
    n1->next = NULL;

    return n1;

}

void insert(typeList * l1, typeData *d){
    
    typeNode * aux, * tmp;

    aux = node(d);

    if(l1->now){
        
        tmp = l1->now;
        
        while(tmp->next != l1->now){
            tmp = tmp->next;
        }

        aux->next = tmp->next;
        tmp->next = aux;

    }else{
        l1->now = aux;
        aux->next = aux;
    }


}

void showData(typeData *d){
    printf("%d\n", *d);
}

void showDatas(typeList * l){

    typeNode * aux;

    aux = l->now;
    if(aux){

        do{

            showData(&(aux->data));
            aux = aux->next;

        }while(aux != l->now);

    }

}

// Function read data
void read(typeList * lst,int tam){

    typeData dt;

    for(int i=0; i< tam;i++){

        scanf("%d", &dt);
        insert(lst,&dt);

    }


}

int main(){

    typeList * l1;
    int n;

    l1 = list();

    scanf("%d", &n);

    read(l1,n);

    showDatas(l1);
  
}