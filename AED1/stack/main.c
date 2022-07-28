#include <stdio.h>
#include <stdlib.h>

typedef int typeData;

typedef struct typeNode{

    typeData data;
    struct typeNode * next;

}typeNode;

typedef struct typeStack{

    typeNode * top;

}typeStack;

typeStack * stack(){
    
    typeStack * stc;

    stc = (typeStack * ) malloc(sizeof(typeStack));

    stc->top = NULL;

    return stc;
}

typeNode * node(typeData * data){

    typeNode * nd;

    nd = (typeNode * ) malloc(sizeof(typeData));

    nd->data = *data;

    nd->next = NULL;

    return nd;

}

void insert(typeStack * stc, typeData * data){

    typeNode * aux;

    aux = node(data);

    aux->next = stc->top;
    stc->top = aux;

}

void sData(typeData * data){

    printf("%d \n", *data);

}

void showDatas(typeStack * stc){

    typeNode * aux;

    aux = stc->top;
    if(aux){
        do{
            sData(&(aux->data));
            aux = aux->next;
        }while(aux);

    }

}
void read(int v[], int tam){

    for(int i=0; i < tam; i++) scanf("%d", v+i);

}


int main(){
    int *v;
    int tam;
    typeData d;
    typeStack * stc;

    stc = stack();

    scanf("%d", &tam);
    
    v  = (int * ) malloc(sizeof(int)*tam);

    read(v, tam);

    for(int i=0; i < tam; i++){
        d = v[i];
        insert(stc,&d);   
    }

    showDatas(stc);


}