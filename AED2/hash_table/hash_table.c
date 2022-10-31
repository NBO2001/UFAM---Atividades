#include "hash_table.h"

unsigned int function_hash(void* value, unsigned int max_tam){

    unsigned int * id = value;
    
    return ( (*id) % max_tam); 

}

void create_hash(typeHash * h, unsigned int tam){

    h->tabHash = (typeList *) malloc(sizeof(typeList)*tam);    

    h->max_tam = tam;

    h->tot_elements = 0;

    for(int i=0; i < tam; i++) create(&h->tabHash[i]);

}

void insert_hash(typeHash * h, typeData * dat){

    unsigned int pos = function_hash(&dat->id,h->max_tam);

    if(! ( seach_in_list(&h->tabHash[pos], &dat->id) ) ){

        insert_end(&h->tabHash[pos], dat);
        h->tot_elements++;
    }


}

typeData seach_hash(typeHash * h, void* key){

    unsigned int pos = function_hash(key,h->max_tam);

    return (*seach_in_list(&h->tabHash[pos], key));

}

typeData remove_hash(typeHash * h, void* key){

    unsigned int pos = function_hash(key,h->max_tam);

    return remove_with_key(&h->tabHash[pos], key);
}

void show_hash(typeHash * h){

    for(int i = 0; i < h->max_tam; i++) showDatas(&(h->tabHash[i]));

}