#include "dictionary.h"
#include "stdlib.h"
#include "string.h"
#include "stdio.h"

//typedef int(*TFuncaoHash)(int);

// typedef struct entrada{
//     int chave;
//     void* info;
// }TEntradaDSH;

//typedef struct DSD TDSD;

struct DSD{
    TEntradaDSH* entradas;
    int tamanho;
    TFuncaoHash hashing;
};

static TEntradaDSH criar_entrada(int chave, void* info){
    return (TEntradaDSH){.chave=chave, .info=info};
}


TDSD* criar_DSD(int tam, TFuncaoHash hashing){
  TDSD* dsd;
  dsd = malloc(sizeof(TDSD));
  dsd->entradas = malloc(sizeof(TEntradaDSH)*tam);
  dsd->tamanho = tam;
  dsd->hashing = hashing;
  
  int i=0;
  while(i < tam){
    dsd->entradas[i].info = NULL; // setar todos os ponteiros como NULL.
    i++;
  }
  return dsd;
}

void inserir_DSD(TDSD* hash, int chave, void* info){
    int k = hash->hashing(chave);
    int tam = hash->tamanho;
    int count = 0; // um dos critérios de parada.

    while((hash->entradas[(k%tam)].info != NULL)&&(count<tam/2)){
      k++;
      count++;
    }
    hash->entradas[k%tam] = criar_entrada(chave,info);
}   

void* buscar_DSD(TDSD* hash, int chave){
  int k = hash->hashing(chave);
  int count =0; // um dos critérios de parada.
  int tam = hash->tamanho;
  TEntradaDSH e = hash->entradas[k];
  void* info_retorno = NULL;

    while((e.chave != chave)&&(e.info != NULL)&&(count<tam/2)){
      k++;
      e = hash->entradas[(k%tam)];
      count++;
    }
    info_retorno = e.info;

    return info_retorno;
  }

int tamanho_DSD(TDSD* hash){
    return hash->tamanho;
}






