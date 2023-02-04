#include<stdarg.h>
#include<stdio.h>


int sum(int args, ...);

int main(int argc, char **argv){

    
    printf("%d\n", sum(8,5,2,6,8,2,1,2,6));
    printf("%d\n", sum(6,2,6,15,368,8,1));
    printf("%d\n", sum(1,2));

}

int sum(int args, ...){

    int acumulation = 0;

    va_list ap;

    va_start(ap,args);
    for(int i=0; i < args; i++){
        acumulation += va_arg(ap,int);
    }
    va_end(ap);

    return acumulation;

}