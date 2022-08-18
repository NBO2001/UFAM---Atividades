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

void read(typeList * lst){

    typeData dt;

    printf("Nome: ");
    scanf("%[^\n]%*c", dt.nome);
    printf("Salario: ");
    scanf("%f%*c", &dt.salario);
    printf("Id: ");
    scanf("%d%*c", &dt.id);
    insert(lst,&dt);



}

void showData(typeList * lst){

    typeNode * aux;

    aux = lst->first;

    while(aux){

        onlyData(&aux->data);

        aux = aux->next;

    }

}

void inserInBase(typeList * lst){

    typeNode * aux;
    
    FILE * fp;

    fp = fopen("./output/ro_dados", "w");

    if(fp == NULL){
        printf("Erro ao tentar criar o arquivo.\n");
        return;
    }

    aux = lst->first;

    while(aux){

        fwrite(&aux->data,1, sizeof(typeData),fp);

        aux = aux->next;

    }

    fclose(fp);

}

void readBase(typeList * lst){

    FILE * fp;
    typeData tmp;
    fp = fopen("./output/ro_dados", "r");

    if(fp == NULL){
        fp = fopen("./output/ro_dados", "w");
        if(fp == NULL){
            printf("Erro ao tentar criar o arquivo.\n");
            return;
        }
    }

    while(fread(&tmp,sizeof(typeData), 1, fp) == 1){
        insert(lst,&tmp);
    }

    fclose(fp);

}

void getOption(int * tmp){
    printf("============== Opcoes =======\n");
    printf("1 : Inserir Registros\n");
    printf("2 : Mostrar Registros\n");
    printf("0 : Sair\n");
    printf("=============================\n");

    scanf("%d%*c", tmp);

}

void program(typeList * lst, int * options){
    int tmp;

    while(1){

        switch (*options)
        {
        case 1:
            printf("Quantos registros quer inserir?\n");
            scanf("%d%*c", &tmp);

            for(int i=0; i < tmp; i++){
                read(lst);
            }
            
            getOption(options);
            break;
        case 2:
            showData(lst);
            getOption(options);
            break;
        case 0:
            return;
        default:
            return;
        }

        
    }
}

void onlyData(typeData * data){

    //printf("{ id: %d, name: %s, salario: %.2f }\n", data->id, data->nome, data->salario);

    printf("%s\n",  data->nome);
    printf("%.2f\n", data->salario);
    printf("%d\n", data->id);

}