#include "stdio.h"
#include "listase.h"
#include "string.h"
#include <stdlib.h>

typedef struct Data
{
    int dia;
    int mes;
    int ano;
} Data;

typedef struct Hora
{
    int hora;
    int minuto;
} Hora ;


typedef struct typeTemperatura {

    int seq;
    Data data;
    Hora hora;
    int radiacao_solar;
    double temperatura;
    double umidade_relativa;

}typeTemperatura;

typeTemperatura* new_typeTemperatura();

typeTemperatura* readFile_typeTemperatura(void* fileArq);

int comparatorTemperatura(void* aa, void* bb);

void print_temperatura(void* t);

typedef struct typeMassa {

    int seq;
    Data data;
    Hora hora;
    double velocidade_media;
    double velocidade_instantanea;
    int direcao;

}typeMassa;

typeMassa* new_typeMassa();

typeMassa* readFile_typeMassa(void* fileArq);

void print_massa(void* m);

int comparatorMassa(void* aa, void* bb);

typeTemperatura* new_typeTemperatura(){

    typeTemperatura* temperatura = malloc(sizeof(typeTemperatura));

    return temperatura;

}

void print_temperatura(void* t){

    typeTemperatura* temperatura = t;

    printf("%d %02d/%02d/%02d %02d:%02d %d %.2lf %.2lf\n", 
    temperatura->seq, temperatura->data.dia, 
    temperatura->data.mes, temperatura->data.ano, 
    temperatura->hora.hora, temperatura->hora.minuto,
    temperatura->radiacao_solar, temperatura->temperatura, temperatura->umidade_relativa);

}

typeTemperatura* readFile_typeTemperatura(void* fileArq){

    FILE* file = fileArq;

    if(!file) return NULL;

    typeTemperatura* temperatura = new_typeTemperatura();

    if(fscanf(file,"%d	%d/%d/%d %d:%d	%d	%lf	%lf", 
    &temperatura->seq, &temperatura->data.dia, &temperatura->data.mes, &temperatura->data.ano, 
    &temperatura->hora.hora, &temperatura->hora.minuto, &temperatura->radiacao_solar, 
    &temperatura->temperatura, &temperatura->umidade_relativa ) == 9)
    {
        return temperatura;
    }else{
        free(temperatura);
        return NULL;
    }

}

int comparatorTemperatura(void* aa, void* bb){

    typeTemperatura* a = aa;
    typeTemperatura* b = bb;

    if(a->data.ano != b->data.ano){
        return a->data.ano - b->data.ano;
    }else if(a->data.mes != b->data.mes){
        return a->data.mes - b->data.mes;
    }else if(a->data.dia != b->data.dia){
        return a->data.dia - b->data.dia;
    }else if(a->hora.hora != b->hora.hora){
        return a->hora.hora - b->hora.hora;
    }else if(a->hora.minuto != b->hora.minuto){
        return a->hora.minuto - b->hora.minuto;
    }else{
        return 0;
    }

    return 0;
    
}

typeMassa* new_typeMassa(){

    typeMassa* massa = malloc(sizeof(typeMassa));

    return massa;

}

void print_massa(void* m){

    typeMassa* massa = m;

    printf("%d %02d/%02d/%02d %02d:%02d %.2lf %.2lf %d\n", 
    massa->seq, massa->data.dia, 
    massa->data.mes, massa->data.ano, 
    massa->hora.hora, massa->hora.minuto,
    massa->velocidade_media, massa->velocidade_instantanea, massa->direcao);

}

typeMassa* readFile_typeMassa(void* fileArq){

    FILE* file = fileArq;

    if(!file) return NULL;

    typeMassa* massa = new_typeMassa();

    if(fscanf(file,"%d	%d/%d/%d %d:%d	%lf	%lf %d", 
    &massa->seq, &massa->data.dia, &massa->data.mes, &massa->data.ano, 
    &massa->hora.hora, &massa->hora.minuto, &massa->velocidade_media, 
    &massa->velocidade_instantanea, &massa->direcao ) == 9)
    {
        return massa;
    }else{
        
        free(massa);
        return NULL;
    }

}

int comparatorMassa(void* aa, void* bb){

    typeMassa* a = aa;
    typeMassa* b = bb;

    if(a->data.ano != b->data.ano){
        return a->data.ano - b->data.ano;
    }else if(a->data.mes != b->data.mes){
        return a->data.mes - b->data.mes;
    }else if(a->data.dia != b->data.dia){
        return a->data.dia - b->data.dia;
    }else if(a->hora.hora != b->hora.hora){
        return a->hora.hora - b->hora.hora;
    }else if(a->hora.minuto != b->hora.minuto){
        return a->hora.minuto - b->hora.minuto;
    }else{
        return 0;
    }
    
}

int main(int argc, char const *argv[])
{   
 
    const int tipo = (int) argv[1][0]-48;

    const char* nome_arquivo = argv[2];

    FILE *arq = fopen(nome_arquivo, "r");

    t_lse* lista;

    if(tipo == 1){

        lista = criar_lse(&print_temperatura, &comparatorTemperatura);

        typeTemperatura* temperatura = NULL;

        while ( ( temperatura = readFile_typeTemperatura(arq) ) != NULL ) inserir_final_lse(lista, temperatura);

    }else{
        
        lista = criar_lse(&print_massa, &comparatorMassa);

        typeMassa* massa = NULL;

        while ( ( massa = readFile_typeMassa(arq) ) != NULL ) inserir_final_lse(lista, massa);

    }
    
    fclose(arq);

    char option;

    do
    {
       scanf("%c", &option);
        int x,y;
        typeMassa tmp;
        void* ret;

        switch (option)
        {
            case 'R':
                
                scanf("%d/%d/%d %d:%d", &tmp.data.dia,&tmp.data.mes,&tmp.data.ano,&tmp.hora.hora,&tmp.hora.minuto);
                remover_lse(lista, &tmp);
                break;

            case 'I':
         
                scanf("%d %d", &x, &y);

                for(int i = x; i <= y; i++){
                    
                    ret = acessar_lse(lista,i);
                    
                    if(tipo==1) print_temperatura(ret);
                    else print_massa(ret);

                }
                
                break;

            case 'A':
          
                scanf("%d", &x);

                ret = acessar_lse(lista,x);
                if( ret){
                    if(tipo==1) print_temperatura(ret);
                    else print_massa(ret);
                }

                break;
            case 'B':

                scanf("%d/%d/%d %d:%d", &tmp.data.dia,&tmp.data.mes,&tmp.data.ano,&tmp.hora.hora,&tmp.hora.minuto);
                ret = buscar_lse(lista, &tmp);

                if(tipo==1) print_temperatura(ret);
                else print_massa(ret);

                break;
            case 'P':
                
                scanf("%d %d", &x, &y);

                for(int i = x; i <= y; i++){
                    
                    ret = acessar_lse(lista,x);
                    remover_lse(lista, ret);
                    free(ret);
                }
                
                break;
            default:
                break;
        }


    } while (option != 'F');
    
    

    return 0;
}
