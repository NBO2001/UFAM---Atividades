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
void insert(typeList * lst, typeData *dat){

    typeNode * nd;

    nd = node(dat);
    
    nd->next = lst->first;
    lst->first = nd;

}

// Detroy list
void destroy(typeList * lst){

    typeNode * nde, * aux;

    nde = lst->first;

    while (nde){
        aux = nde;
        nde = nde->next;
        free(aux);
    }

    lst->first = NULL;

}

//Remove the first element. Return 1 successfully otherwise return 0.
char popf(typeList * lst){

    typeNode * aux;
    if(lst->first){

        aux = lst->first;
        lst->first = aux->next;
        free(aux);
        return 1;
    }
    return 0;

}

//Remove the end element. Return 1 successfully otherwise return 0.
char pope(typeList * lst){

    typeNode * aux, * aux2;
    
    if(!lst->first) return 0;

    aux = lst->first;
    if(!aux->next){
        lst->first = NULL;
        free(aux);
        return 1;
    }
    while (aux->next->next){
        aux = aux->next;
    }

    aux2 = aux->next;
    
    aux->next = NULL;

    free(aux2);

    return 1;
    
}

//Remove element by index. Return 1 successfully otherwise return 0.
char popi(typeList * lst, int k){
    int i=1;
    typeNode * aux, * anterior;
    
    if(!lst->first) return 0;

    aux = lst->first;
    
    if((k!=1) && (!aux->next)){
        return 0;
    }

    if(k==1){
        if(aux->next){
            anterior = aux->next;
            lst->first = anterior;
        }else{
            lst->first = NULL;
        }
        
        free(aux);
        return 1;
    }

    while ((i < k) && aux->next){ 
        
        anterior = aux;
        aux = aux->next;
        i++;
    }

    if (i == k){

        anterior->next = aux->next;

        free(aux);

        return 1;
    }

    return 0;
    
}

typeData popiV2(typeList * lst, int k){
    int i=1;
    typeData auxData;
    typeNode * aux, * anterior;
    
    auxData.d = -9999;
    if(!lst->first) return auxData;

    aux = lst->first;
    
    if((k!=1) && (!aux->next)){
        return auxData;
    }

    if(k==1){
        if(aux->next){
            anterior = aux->next;
            lst->first = anterior;
        }else{
            lst->first = NULL;
        }
        auxData = aux->data;
        free(aux);
        return auxData;
    }

    while ((i < k) && aux->next){ 
        
        anterior = aux;
        aux = aux->next;
        i++;
    }

    if (i == k){

        anterior->next = aux->next;
        auxData = aux->data;
        free(aux);

        return auxData;
    }

    return auxData;
    
}

// Check it it's growing
char isCrescent(typeList * lst){

    typeNode * aux;

    aux = lst->first;

    if((!aux) || (!aux->next)){
        return 1;
    }
    
    while(aux->next){

        if(aux->data.d > aux->next->data.d){
            return 0;
        }

        aux = aux->next;

    }

    return 1;

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

// Function read data
void read(typeList * lst,int tam){

    typeData dt;

    for(int i=0; i< tam;i++){

        scanf("%d", &dt.d);
        insert(lst,&dt);

    }


}
// Funcao de teste de ordenacao
int retornIndexMenor(typeList * lst){

    typeNode * aux;
    int k, cnt;
    typeData menor;
    aux = lst->first;

    if(!aux) return 0;

    menor = aux->data;
    k = 1;
    cnt = 1;
    while(aux){

        if(aux->data.d < menor.d){
            menor = aux->data;
            k=cnt;
        }

        aux = aux->next;
        cnt++;
    }
    return k;

}

char isEmpty(typeList * lst){

    if(!lst->first) return 0;
    return 1;

}

void ordenaLista(typeList * lst){

    typeList * lstAux;
    typeData tmp;
    int indexMenor;
    lstAux = list();

    while(isEmpty(lst)){

        indexMenor = retornIndexMenor(lst);
        tmp = popiV2(lst,indexMenor);
        insert(lstAux,&tmp);

    }

    *lst = *lstAux;

}

int main(){

    typeList * l1;
    int n;

    l1 = list();

    scanf("%d", &n);

    read(l1,n);

    //popi(l1,2); // Remove Element

    ordenaLista(l1);
    showList(l1);
    
    // if(isCrescent(l1)){ // Verfica se e' crescente
    //     printf("e' crescente\n");
    // }else{
    //     printf("Not cress\n");
    // }

    // destroy(l1);

    
}