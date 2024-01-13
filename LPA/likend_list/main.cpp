#include <stdio.h>
#include "lista_eventos_t.h"
#include <stdlib.h>


int main(int argc, char** argv){

    FILE* file = fopen(argv[1], "r");
    lista_eventos_t* lista = (lista_eventos_t*) malloc(sizeof(lista_eventos_t));
    evento_t* event = (evento_t*) malloc(sizeof(evento_t));

    while (fscanf(file,"%lf\t%d\t%d\n", &(event->tempo), &(event->alvo), &(event->tipo)) == 3){

        
        lista_eventos_adicionar_ordenado(event, &lista);

        event = (evento_t*) malloc(sizeof(evento_t));
    }

    lista_eventos_print(lista);
    
    
}