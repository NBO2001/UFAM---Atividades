#include "merge_sort.h"
#include "stdio.h"
#include <string.h>
#include <stdlib.h>

// Funcao que intercala os valores
void intercalary(void* als, int inicio, int meio, int fim, int sizeEl,void* aux, mergeCMP cmpFunction ){

    int i, j,k=inicio;

    i = inicio;
    j = meio + 1;

    while( (i <= meio) && (j <= fim)){

        if(cmpFunction( als + (i*sizeEl),als + (j*sizeEl)) > 0){

            memcpy(aux+(k*sizeEl), als+(i*sizeEl), sizeEl);

            i++;
        }else{
            memcpy(aux+(k*sizeEl), als+(j*sizeEl), sizeEl);
            j++;
        }

        k++;
    }

    while( i <= meio){
        memcpy(aux+(k*sizeEl), als+(i*sizeEl), sizeEl);
        i++;
        k++;
    }
    while( j <= fim){
        memcpy(aux+(k*sizeEl), als+(j*sizeEl), sizeEl);
        j++;
        k++;
    }

    for(i=inicio; i < k; i++){ memcpy(als+(i*sizeEl), aux+(i*sizeEl), sizeEl);  }

}

void mergeR(void * v, int inicio, int fim, int sizeEl, void* aux,  mergeCMP cmpFunction){

    int meio; 
    
    if (inicio < fim){

        meio = (inicio+fim)/2;

        mergeR(v, inicio, meio,sizeEl, aux, cmpFunction);
        mergeR(v, meio+1, fim,sizeEl, aux, cmpFunction);
        intercalary(v,inicio,meio,fim,sizeEl,aux, cmpFunction);

    }

}


void merge_sort(void* vet, int n, int sizeEl, mergeCMP cmpFunction){

    void* aux = malloc(sizeEl*(n+2));
    
    mergeR(vet,0,n-1, sizeEl, aux,cmpFunction);

    free(aux);

}