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

// Aumenta em 10% o salario dos funcionarios.
void salaryincrease(char * fileName);

// Mostra um elemento de uma lista encadeada
void onlyData(typeData * data);

// Retorna o tamanho de um arquivo.
long int lenFile(FILE * fp);

// Mostra os dados de um arquivo, sem carregar todos dados para a memoria.
void showFileData(char * fileName);

int main(){
    
    salaryincrease("ro_dados");
    showFileData("ro_dados");

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


void onlyData(typeData * data){

    //printf("{ id: %d, name: %s, salario: %.2f }\n", data->id, data->nome, data->salario);

    printf("%s\n",  data->nome);
    printf("%.2f\n", data->salario);
    printf("%d\n", data->id);

}

long int lenFile(FILE * fp){

    long int tmp, tam;

    tmp = ftell(fp);

    fseek(fp, 0, SEEK_END);

    tam = ftell(fp);

    fseek(fp, tmp, SEEK_SET);

    return tam;


}

void salaryincrease(char * fileName){

    FILE * fp;
    
    typeData data;

    long int tam, qntRegistros;

    fp = fopen(fileName, "r+");

    if(fp == NULL){
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    tam = lenFile(fp);

    qntRegistros = tam/sizeof(typeData);

    fseek(fp,0,SEEK_SET);


    for(int i=0; i < qntRegistros; i++){

        fseek(fp,sizeof(typeData)*i,SEEK_SET);

        fread(&data,sizeof(typeData),1, fp);

        fseek(fp,sizeof(typeData)*i,SEEK_SET);
        
        data.salario = (data.salario*1.1);

        fwrite(&data,1, sizeof(typeData), fp);

    }



    fclose(fp);


}


void showFileData(char * fileName){

    FILE * fp;
    
    typeData data;

    fp = fopen(fileName, "r");

    if(fp == NULL){
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    while(fread(&data,sizeof(typeData),1, fp) == 1){
        onlyData(&data);
    }

    fclose(fp);


}