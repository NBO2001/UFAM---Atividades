#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
int main(int argc, char * argv[]){

    int tam = 1;
    int * numbs = malloc(sizeof(int)*tam);
    int idx = 0;

    for(int i=0; i < 55000; i++){

        numbs[idx] = i;
        idx++;

        if(idx >= tam){
            
            tam = tam * 2;

            numbs = realloc(numbs, (sizeof(int)*tam) );
            assert(numbs != NULL);
        }
        
       

    }
    for(int i=0; i < 100; i++){
        printf("%d ", numbs[i]);
    }
    printf("\n");


}
