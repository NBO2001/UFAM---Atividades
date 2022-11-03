#include "../headers/manipulationData.h"


void imprimirInfo(typeData info){

  //printf("%d %lf\n", info.matricula, info.nota);

  printf("{ \n");
  printf("\tId: %ld,\n", info.id);
  printf("\tName: %s,\n", info.name);
  printf("\tEmail: %s,\n", info.email);
  printf("\tIdade: %d,\n", info.idade);
  printf("\tPeso: %lf,\n", info.peso);
  printf("} \n");

  //printf("{ Placa: %ld,  Ano: %d,  Peso: %lf, Km: %lf, Valor: %lf }\n", info.placa, info.ano, info.peso, info.kilometragem, info.valor);
  //printf("Vou imprimir a informação\n");

}

int compararInfo(typeData info, void* chaveBusca){
  long int* id = chaveBusca;

  return info.id - *id;
}

typeData emptyData(){

    typeData empty = (typeData){.id=-1};

}