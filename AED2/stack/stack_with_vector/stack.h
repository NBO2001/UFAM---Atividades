#ifndef _STACK_H
#define _STACK_H


typedef struct typeStack{

    void* itens;
    int height;
    int lenght;
    char isInfinity;

}typeStack;

/**
With lenght iquals 0, stack is infinite.  
 */
typeStack * newStack(int lenght);

char stackUp(typeStack * stk, void* item);

void * unstack(typeStack * stk);

void * top_stack(typeStack * stk);

int tam_stack(typeStack * stk);


#endif