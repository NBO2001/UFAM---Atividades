#ifndef LISTEVENTS_H
#define LISTEVENTS_H

#include "evento_t.h"

typedef struct lista_eventos_t{

    evento_t* evento;
    struct lista_eventos_t* next;  

} lista_eventos_t;

bool lista_eventos_adicionar_inicio(evento_t *evento, lista_eventos_t **lista);
bool lista_eventos_adicionar_fim(evento_t *evento, lista_eventos_t **lista);
bool lista_eventos_adicionar_ordenado(evento_t *evento, lista_eventos_t **lista);

void lista_eventos_print(lista_eventos_t* lista);

#endif