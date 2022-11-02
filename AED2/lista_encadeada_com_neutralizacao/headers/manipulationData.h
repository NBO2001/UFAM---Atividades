#ifndef _MANI_DATA_H
#define _MANI_DATA_H

#include <stdio.h>

typedef struct {
  long int placa;
  unsigned int ano;
  double kilometragem;
  double peso;
  double valor;
} typeData;

void imprimirInfo(typeData info);
int compararInfo(typeData info, void* chaveBusca);
typeData emptyData();

#endif