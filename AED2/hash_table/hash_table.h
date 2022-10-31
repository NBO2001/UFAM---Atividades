#ifndef _HASH_TABLE_H
#define _HASH_TABLE_H

#include "linked_list.h"

typedef struct typeHash{

    typeList * tabHash;
    unsigned int tot_elements;
    unsigned int max_tam;

}typeHash;

void create_hash(typeHash * h, unsigned int tam);

void insert_hash(typeHash * h, typeData * dat);

unsigned int function_hash(void* value, unsigned int max_tam);

typeData seach_hash(typeHash * h, void* key);

typeData remove_hash(typeHash * h, void* key);

void show_hash(typeHash * h);

#endif