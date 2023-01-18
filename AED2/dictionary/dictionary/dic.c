#include "dic.h"
#include "stdlib.h"
#include "stdio.h"

struct typeEstatistc{
    int nCmp;
    int nBuscas;
};

struct typeDictionary{
    typePair * elements;
    int occupation;
    int tam;
    struct typeEstatistc;
};


typeDictionary * newDict(int tam){

    typeDictionary * dic = malloc(sizeof(typeDictionary));
    dic->elements = malloc(sizeof(typePair)*tam);
    dic->tam = tam;
    dic->occupation = 0;
    dic->nCmp = 0;
    dic->nBuscas = 0;
    return dic;

}

void * seachDic(typeDictionary * dic, int key){

    dic->nBuscas++;

    int start = 0, end=dic->occupation - 1;
    int harf;

    while (start <= end){

        harf = (start + end )/2;
        
        if(dic->elements[harf].key > key){
            dic->nCmp++;
            end = harf - 1;
        }else if(dic->elements[harf].key < key){
            dic->nCmp = dic->nCmp + 2;
            start = harf + 1;
        }else if(dic->elements[harf].key == key){
            dic->nCmp = dic->nCmp + 3;
            return dic->elements[harf].element;
        }

    }
    return  NULL;

}

void toCharge(typeDictionary * dic, typePair elem){

    dic->elements[dic->occupation] = elem;
    dic->occupation++;

}

int occuption(typeDictionary * dic){
    return dic->occupation;
}

void dashbord(typeDictionary * dic){
    printf("Numero de buscas: %d\n", dic->nBuscas);
    printf("Numero de comparacoes: %d\n", dic->nCmp);
    printf("Comparacoes por Buscas: %lf\n", (double) dic->nCmp/dic->nBuscas);

}