#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

typedef struct typeHora{

    int hora;
    int minutos;
    int segundos;
    long int milisegundos; 

} typeHora;

typedef struct typeDate{

    int day;
    int month;
    int year;

}typeDate;

typedef struct typeActivity{

    typeHora hora;
    typeDate date;
    char typeAct[40];
    char describe[60];

}typeActivity;

void printActivity(typeActivity * info){
    
  printf("{ \n");
  printf("\t %d/%d/%d  %d:%d,\n", 
    info->date.day,
    info->date.month, 
    info->date.year, 
    info->hora.hora, 
    info->hora.minutos);
  printf("\tAtividade: %s\n", info->typeAct);
  printf("\tDescricao: %s\n", info->describe);
  printf("} \n");

}

int main(int argc, char * argv[]){

    typeQueue* queue = createQueue(0);
    typeActivity* desStack;

    typeDate date;
    typeHora hora;
    char typeAct[40];
    char describe[60];


    scanf("%d/%d/%d%*c", &date.day,&date.month,&date.year);

    while(date.day != 0){
        
        
        scanf("%d:%d%*c", &hora.hora, &hora.minutos);

        scanf("%[^\n]%*c", typeAct);
        scanf("%[^\n]%*c", describe);
        
        
        typeActivity* newAct = (typeActivity* ) malloc(sizeof(typeActivity));

        
        newAct->hora = hora;
        newAct->date = date;

        strcpy(newAct->typeAct,typeAct);
        strcpy(newAct->describe,describe);        

        if( toQueue(queue, newAct) == 0){
            printf("Fila Cheia!\n");
        }

        scanf("%d/%d/%d%*c", &date.day,&date.month,&date.year);
    }

    typeActivity * top = fistElement(queue);

    printf("Tamanho: %d\n", lenQueue(queue));

    if(top)
        printActivity(top);

    int flag = 1;

    while (flag){

        desStack = unqueue(queue);

        if(desStack){
            printActivity(desStack);
        }else{
            printf("Fila Vazia\n");
        }

        scanf("%d%*c", &flag);
    }
    
}