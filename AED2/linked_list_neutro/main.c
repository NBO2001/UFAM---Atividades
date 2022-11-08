#include <stdio.h>
#include "linked_list.h"
#include <string.h>
#include <stdlib.h>

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

typedef struct {
    long int id;
    typeHora hora;
    typeDate date;
    char eventeType[40];
    char adrress[60];
    char describe[60];

} typeData;

void printPerson(typeData * info){
    
  printf("{ \n");
  printf("\tId: %ld,\n", info->id);
  printf("\tTipo de evento: %s\n", info->eventeType);
  printf("\tDescricao: %s\n", info->describe);
  printf("\tEndereco: %s,\n", info->adrress);
  printf("\tData: %d/%d/%d,\n", info->date.day, info->date.month, info->date.year);
  printf("\tHora: %d:%d,\n", info->hora.hora, info->hora.minutos);
  printf("} \n");

}

int compararPerson(typeData * info, void* chaveBusca){
  typeData* dt = chaveBusca;

  return info->id - dt->id;
}

int main(int argc, char * argv[]){

    long int id;
    typeHora hora;
    typeDate date;
    char eventeType[40];
    char adrress[60];
    char describe[60];

    
    typeList* lista_eventos = newList(&compararPerson,&printPerson);

    scanf("%ld%*c", &id);
    while(id > 0){
        
        scanf("%d/%d/%d%*c", &date.day,&date.month,&date.year);
        scanf("%d:%d%*c", &hora.hora, &hora.minutos);

        scanf("%[^\n]%*c", eventeType);
        scanf("%[^\n]%*c", adrress);
        scanf("%[^\n]%*c", describe);
        
        
        typeData* novo = (typeData* ) malloc(sizeof(typeData));

        novo->id = id;
        novo->hora = hora;
        novo->date = date;

        strcpy(novo->eventeType,eventeType);
        strcpy(novo->adrress,adrress);
        strcpy(novo->describe,describe);        

        inserirFinalLSE(lista_eventos, novo);
        scanf("%ld%*c", &id);
    }

    printf("Tam: %d\n", tamanhoLSE(lista_eventos));


    // long int seach_id;
    // scanf("%ld%*c", &seach_id);
    // while (seach_id)
    // {
        
    //     typeData* retElement = (typeData* ) buscarConteudoLSE(lista_eventos, &seach_id);

    //     if(retElement){
    //         printPerson(retElement);
    //     }

    //     scanf("%ld%*c", &seach_id);
    // }
    
    imprimirLSE(lista_eventos);

    return 0;

}
