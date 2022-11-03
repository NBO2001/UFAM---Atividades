#ifndef _MANI_DATA_H
#define _MANI_DATA_H

#include <stdio.h>

typedef struct {
    long int id;
    char name[60];
    double peso;
    int idade;
    char email[50];
} typeData;

void imprimirInfo(typeData info);
int compararInfo(typeData info, void* chaveBusca);
typeData emptyData();

#endif