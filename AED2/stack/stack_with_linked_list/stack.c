#include "stdio.h"
#include "stack.h"
#include "stdlib.h"
#include "linked_list.h"


typeStack * newStack(int lenght){

    typeStack * stack = (typeStack *) malloc(sizeof(typeStack));

    stack->height = 0;
    stack->lenght = lenght;
    stack->itens = newList(NULL,NULL);

    return stack;

}

char stackUp(typeStack * stk, void* item){

    if( (stk) && ((stk->lenght == 0) || (stk->height < stk->lenght) ) ){

        typeList * list = stk->itens;
        
        inserirInicioLSE(list, item);

        (stk->height)++;

        return 1;

    }

    return 0;

}

void * unstack(typeStack * stk){

    if( (stk) && (stk->height > 0) ){

        void* item = removerInicioLSE(stk->itens);
        (stk->height)--;

        return item;
    }

    return NULL;
}

void * top_stack(typeStack * stk){

    if( (stk) && (stk->height > 0) ){

        typeList * list = stk->itens;
        return list->inicio->chargeutil;

    }

    return NULL;
}

int tam_stack(typeStack * stk){

    return stk->height;
    
}