#include "stack.h"
#include "stdlib.h"
#include "stdio.h"


typeStack * newStack(int lenght){

    int n = 2;
    if(lenght != 0)
        n = lenght;
        
    typeStack* stk = malloc(sizeof(typeStack));

    stk->itens = malloc(sizeof(void*)*n);

    stk->height = 0;
    stk->lenght = n;

    if(lenght == 0){
        stk->isInfinity = 1;
    }else{
        stk->isInfinity = 0;
    }

    return stk;

}

char stackUp(typeStack * stk, void* item){

    if( (stk) && ( (stk->isInfinity) || (stk->height < stk->lenght) )){
        
        if(stk->height < stk->lenght){

            void* *vector = stk->itens;

            vector[stk->height] = item;

            (stk->height)++;
            
            return 1;

        }else if(stk->isInfinity){

            int new_tam = stk->lenght * 2;

            stk->itens = realloc(stk->itens,new_tam);

            void* *vector = stk->itens;
            
            stk->lenght = new_tam;

            vector[stk->height] = item;

            (stk->height)++;

            return 1;
            
            

        }

    }

    return 0;

}

void * unstack(typeStack * stk){

    if( (stk) && ( stk->height > 0) ){
        
        void * * vector = stk->itens;
        
        void * el = vector[stk->height-1];
        
        (stk->height)--;

        return el;


    }

    return NULL;
}

void * top_stack(typeStack * stk){

    if( (stk) && ( stk->height > 0) ){
        
        void * * vector = stk->itens;
        
        return vector[ (stk->height)-1 ];


    }

    return NULL;
}

int tam_stack(typeStack * stk){

    return stk->height;

}