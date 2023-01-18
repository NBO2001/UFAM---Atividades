#include <stdio.h>
#include <string.h>

typedef struct mykey{

    int teste;
    void * ts;

}mykey;
int main(int argc, char * argv[]){

    mykey data = {.teste = 2,.ts=NULL};
    mykey data2 = {.teste = 2,.ts=NULL};
    double g = 2.0;
    double d = 2.1;

    int ret = memcmp(&g, &d, sizeof(double));

    if( ret == 0){
        printf("Sao iguais\n");
    }else{
        printf("N Sao iguais %d\n", ret);
    }

}
