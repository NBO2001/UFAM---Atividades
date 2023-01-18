#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "./dicRom/dictionary.h"

int hashFunction(int k){ return k%10; }

int main(int argc, char * argv[]){
    
    srand(time(NULL)); 
    int teste02 = 1;

    TDSD * nomesDic = criar_DSD(10, &hashFunction);

    char name[25];
    int id;
    char * resp = malloc(sizeof(char)*25);

    while(scanf("%d;%[^\n]%*c", &id, name) > 0){
        
        char * nameIn = malloc(sizeof(char)*25);

        strcpy(nameIn, name);
        
        inserir_DSD(nomesDic, id, nameIn);
        
    }

    int key = 20;

    do{
        resp = buscar_DSD(nomesDic, key);

        if(resp) printf("%s %d\n", resp, key);
        else printf("N tem a chave: %d\n", key);

        key--;
    }while (key >= 0);


    if(!teste02) return 0;
    printf("Teste 02 *-*-*-*-*- \n");
    int contador = 100;
    key = 0;

    do{
        key = rand()%20;
        resp = buscar_DSD(nomesDic, key);

        if(resp) printf("%s %d\n", resp, key);
        else printf("N tem a chave: %d\n", key);

        contador--;
    }while (contador >= 0);
    

    printf("Tam: %d\n", tamanho_DSD(nomesDic));

}
