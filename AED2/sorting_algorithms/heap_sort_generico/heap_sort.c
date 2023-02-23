#include "heap_sort.h"
#include "stdlib.h"
#include "string.h"

void swap(void * vet, int a, int b, int sizeEl){

    void * tmp = malloc(sizeof(sizeEl));
    memcpy(tmp, vet + (a*sizeEl), sizeEl);
    memcpy(vet + (a*sizeEl),vet + (b*sizeEl), sizeEl);
    memcpy(vet + (b*sizeEl), tmp, sizeEl);
    
    free(tmp);

}

void heapOrganazer(void* vet, int n, int father, int sizeEl, heapCMP comparatorFunction ){

    int childrenLeft = (father*2) + 1; 
    int childrenRight = (father*2) + 2;
    int biggerValue = father;

    if( (childrenLeft < n) && comparatorFunction(vet + (childrenLeft*sizeEl),vet + (biggerValue*sizeEl)) > 0 ) biggerValue = childrenLeft;

    if( (childrenRight < n) && comparatorFunction(vet + (childrenRight*sizeEl),vet + (biggerValue*sizeEl)) > 0 ) biggerValue = childrenRight;

    if(biggerValue != father){

        swap(vet,biggerValue,father, sizeEl);

        heapOrganazer(vet,n,biggerValue,sizeEl, comparatorFunction);
    }

}

void removeHeap(void* vet, int n, int sizeEl, heapCMP comparatorFunction ){

    swap(vet,0,n-1, sizeEl);
    heapOrganazer(vet,n-1,0,sizeEl,comparatorFunction);

}

void createHeap(void* vet, int n, int sizeEl, heapCMP comparatorFunction ){
    // Create heap
    int tam = (n-1)/2;

    while (tam >= 0){
        
        heapOrganazer(vet,n,tam,sizeEl,comparatorFunction);

        tam--;
    }
    
}

void sorting(void* vet, int n, int sizeEl, heapCMP comparatorFunction){

    while (n > 1){
        removeHeap(vet,n,sizeEl,comparatorFunction);
        n--;   
    }

}

void heap_sort(void* vet, int n, int sizeEl, heapCMP comparatorFunction ){

    createHeap(vet,n,sizeEl,comparatorFunction);
    sorting(vet,n,sizeEl,comparatorFunction);

}