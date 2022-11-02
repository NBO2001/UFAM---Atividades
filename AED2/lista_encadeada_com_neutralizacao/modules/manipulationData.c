#include "../headers/manipulationData.h"


void imprimirInfo(typeData info){

  //printf("%d %lf\n", info.matricula, info.nota);
  printf("{ Placa: %ld,  Ano: %d,  Peso: %lf, Km: %lf, Valor: %lf }\n", info.placa, info.ano, info.peso, info.kilometragem, info.valor);
  //printf("Vou imprimir a informação\n");

}

int compararInfo(typeData info, void* chaveBusca){
  long int* placa = chaveBusca;

  return info.placa - *placa;
}

typeData emptyData(){

    typeData empty = (typeData){.peso=-1,.placa=-1,.kilometragem=-1,.valor=-1};

}