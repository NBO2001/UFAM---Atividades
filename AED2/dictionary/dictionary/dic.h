#ifndef DICT_H
#define DICT_H

typedef struct typeDictionary typeDictionary;
typedef struct typeEstatistc typeEstatistc;
typedef struct typePair{

    int key;
    void * element;

}typePair;


typeDictionary * newDict(int tam);
void * seachDic(typeDictionary * dic, int key);
void toCharge(typeDictionary * dic, typePair elem);
int occuption(typeDictionary * dic);
void dashbord(typeDictionary * dic);

#endif