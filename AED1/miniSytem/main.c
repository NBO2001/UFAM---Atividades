#include <stdio.h>
#include <stdlib.h>

typedef struct typeData {

    char nome[30];

    float salario;

    unsigned id;

} typeData;

typedef struct typeNode{

    typeData data;
    struct typeNode * next;
    struct typeNode * previus;

} typeNode;

typedef struct typeList{

    typeNode * first; 
    typeNode * end;

}typeList;

// Prototipos das funçoes

// Create List
typeList * list();

// Create node
typeNode * node(typeData * data);

// Insert into list
void insert(typeList * lst, typeData * data);

// Remove the list
typeData * pop(typeList * lst, int k);

/*
Insere os valores de uma lista encadeada em uma arquivo binario.
*/
void inserInBase(typeList * lst);


/*
Ler os valores de um arquivo binario e joga para uma lista encadeada.
*/
void readBase(typeList * lst);

// Mostra um elemento de uma lista encadeada
void onlyData(typeData * data);

// Mostra uma lista encadeada completa.
void showData(typeList * lst);

// Ler um tipoDado para a lista
void read(typeList * lst);

// Funcao que pega a opcao digitada pelo usuario
void getOption(int * tmp);

// O program que interage com o usuario.
void program(typeList * lst, int * options);



int main(){

    typeList * l1;
    int options=0;
    
    l1 = list();

    readBase(l1);
    
    //getOption(&options);

    //program(l1,&options);
    showData(l1);

    //inserInBase(l1);
    
    

}


typeList * list(){

    typeList * tmp;

    tmp =(typeList * ) malloc(sizeof(tmp));

    tmp->first = NULL;
    
    tmp->end = NULL;

    return tmp;

}

typeNode * node(typeData * data){

    typeNode * nd;

    nd = (typeNode * ) malloc(sizeof(typeNode));

    nd->next = NULL;

    nd->previus = NULL;

    nd->data = *data;

    return nd;

}

void insert(typeList * lst, typeData * data){

    typeNode * tmp, * aux;

    tmp = node(data);

    aux = lst->end;

    if(!aux){
        lst->first = tmp;
        lst->end = tmp;
        return;
    }

    aux->next = tmp;
    tmp->previus = aux;
    lst->end = tmp;

}
