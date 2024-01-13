#include "lista_eventos_t.h"
#include "evento_t.h"
#include <stdlib.h>
#include <stdio.h>

bool lista_eventos_adicionar_inicio(evento_t *evento, lista_eventos_t **lista){

    lista_eventos_t* new_element = (lista_eventos_t*) malloc(sizeof(lista_eventos_t)); 
    if(!new_element) return false;

    new_element->evento = evento;
    new_element->next = *lista;

    *lista = new_element;

    return true;

}

bool lista_eventos_adicionar_fim(evento_t *evento, lista_eventos_t **lista){

    lista_eventos_t* lis = *lista;

    if(lis && !lis->evento){
        lis->evento= evento;

        return true;
    }

    while(lis && lis->next && lis->next->evento){
        lis = lis->next;
    }

    lista_eventos_t* new_element = (lista_eventos_t*) malloc(sizeof(lista_eventos_t)); 
    if(!new_element) return false;

    new_element->evento = evento;
    new_element->next = NULL;

    lis->next = new_element;

    
    return true;
}

bool lista_eventos_adicionar_ordenado(evento_t *evento, lista_eventos_t **lista){

    lista_eventos_t* lis = *lista;
    lista_eventos_t* ant = NULL;

    if(lis && !lis->evento){
        lis->evento= evento;

        return true;
    }
    
    while(lis &&  lis->evento->tempo < evento->tempo){
        ant = lis;
        lis = lis->next;
    }
    

    lista_eventos_t* new_element = (lista_eventos_t*) malloc(sizeof(lista_eventos_t)); 
    if(!new_element) return false;

    new_element->evento = evento;
    new_element->next = lis;

    if(ant) ant->next = new_element;

    if(!ant) *lista = new_element;
    return true;
}

void lista_eventos_print(lista_eventos_t* lista){

    lista_eventos_t* aux = lista;

    while(aux && aux->evento){
        printf("%lf %d %d\n",aux->evento->tempo,aux->evento->tipo,aux->evento->alvo);
        aux = aux->next;
    }
    
}