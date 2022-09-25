#include <stdio.h>
#include <stdlib.h>

typedef struct {

    char nome[30];

    float salario;

    unsigned id;

} tipoDados;

typedef struct typeNode{

    tipoDados data;
    struct typeNode * next;
    struct typeNode * previus;

} typeNode;

typedef struct typeList{

    typeNode * first; 
    typeNode * end;

}typeList;

// Create List
typeList * list();

// Create node
typeNode * node(tipoDados * data);

// Insert into list
void insert(typeList * lst, tipoDados * data);
void readData(char * fileName, typeList * l);
void onlyData(tipoDados * data);
void showData(typeList * lst);
void showDataV2(typeList * lst);



int main(){

    typeList * l;

    l = list();

    readData("ro_dados",l);
    showData(l);


}

typeList * list(){

    typeList * tmp;

    tmp =(typeList * ) malloc(sizeof(typeList));

    tmp->first = NULL;
    
    tmp->end = NULL;

    return tmp;

}

typeNode * node(tipoDados * data){

    typeNode * nd;

    nd = (typeNode * ) malloc(sizeof(typeNode));

    nd->next = NULL;

    nd->previus = NULL;

    nd->data = *data;

    return nd;

}

void insert(typeList * lst, tipoDados * data){

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

void readData(char * fileName, typeList * l){

    FILE * fp;
    tipoDados tmp;
    fp = fopen(fileName, "r");

    if(fp == NULL){
        printf("Erro ao ler o arquivo.\n");
        exit(1);
    }
    while (fread(&tmp,sizeof(tipoDados), 1, fp)==1)
    {
        insert(l,&tmp);
        
    }
    

    fclose(fp);

}

void onlyData(tipoDados * data){

    //printf("{ id: %d, name: %s, salario: %.2f }\n", data->id, data->nome, data->salario);

    printf("%s\n",  data->nome);
    printf("%.2f\n", data->salario);
    printf("%d\n", data->id);

}

void showData(typeList * lst){

    typeNode * aux;

    aux = lst->first;

    while(aux){

        onlyData(&aux->data);

        aux = aux->next;

    }

}

void showDataV2(typeList * lst){

    typeNode * aux;

    aux = lst->end;

    while(aux){

        onlyData(&aux->data);

        aux = aux->previus;

    }

}


