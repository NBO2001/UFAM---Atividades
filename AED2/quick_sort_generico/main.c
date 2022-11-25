#include <stdio.h>
#include "stdlib.h"
#include "quick_sort.h"

char cmp(void * a, void * b){

    int * aa = a;
    int * bb = b;
    
    return (*bb) - (*aa);

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

    sort(vet,n, sizeof(int), &cmp);

    for(int i=0; i < n; i++){
        printf("%d ", vet[i]);
    }

    printf("\n");

}
