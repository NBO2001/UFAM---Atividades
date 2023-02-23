#include <stdio.h>
#include "stdlib.h"
#include "./heap_sort_generico/heap_sort.h"

int cmp(void * a, void * b){

    int * aa = a;
    int * bb = b;
    
    return (*aa) - (*bb);

}

int main(int argc, char * argv[]){

    int * vet;
    int n;

    scanf("%d", &n);

    vet = malloc(sizeof(int)*n);

    for(int i=0; i < n; i++){
        scanf("%d", &vet[i]);
    }
    for(int i=0; i < n; i++){
        printf("%d ", vet[i]);
    }

    printf("\n");

    heap_sort( vet,n, sizeof(int), &cmp);

    for(int i=0; i < n; i++){
        printf("%d ", vet[i]);
    }

    printf("\n");

}
