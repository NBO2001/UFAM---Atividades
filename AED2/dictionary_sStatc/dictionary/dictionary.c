#include "stdlib.h"
#include "string.h"
#include "dictionary.h"

struct entrada{
  int chave;
  void* info;
};

struct DSD{
  TEntradaDSD* entradas;
  int tamanho;

};

static TEntradaDSD _criar_entrada(int chave, void* info){

  return (TEntradaDSD){.chave=chave, .info=info};

}

static int _vazia_entrada(TEntradaDSD e){
  return (e.info == NULL);
}

static int _ler_chave_entrada(TEntradaDSD e){
  return (e.chave);
}

static void* _ler_info_entrada(TEntradaDSD e){
  return (e.info);
}

static int _hashing_resto_DSD(TDSD* dsd, int chave){
    return (chave%dsd->tamanho);
}

TDSD* criar_DSD(int tam){

  TDSD* dsd = malloc(sizeof(TDSD));
  dsd->tamanho = tam;
  dsd->entradas = malloc(dsd->tamanho*sizeof(TEntradaDSD));

  // garantir que todos os membros recebam valores "zerados"
  memset(dsd->entradas, 0, dsd->tamanho*sizeof(TEntradaDSD));

  return dsd;
}

void inserir_DSD(TDSD* dsd, int chave, void* info){
      int k = _hashing_resto_DSD(dsd,chave);
      int j,i=-1;

      do{
        i++;
        j = (k+i) % dsd->tamanho; // garante checagem circular
      }while( ! _vazia_entrada (dsd->entradas[j]) );

      dsd->entradas[j] = _criar_entrada(chave, info);
}

void* buscar_DSD(TDSD* dsd, int chave){
  void* info = NULL;

  // tem chave na posiçào?
  // a chave que tá na posiçào é buscada?
  // teve colisão? Buscar nas entradas subsequentes;

  int k = _hashing_resto_DSD(dsd, chave);
  int j,i=-1;

  for(int c=0; c < dsd->tamanho; c++){

    i++;
    j = (k+i) % dsd->tamanho; // garante checagem circular

    if((!_vazia_entrada(dsd->entradas[j])) && (_ler_chave_entrada(dsd->entradas[j]) == chave)){
      return _ler_info_entrada(dsd->entradas[j]);
    }

  }

  return info;
}

int tamanho_DSD(TDSD* dsd){

  return dsd->tamanho;
}
