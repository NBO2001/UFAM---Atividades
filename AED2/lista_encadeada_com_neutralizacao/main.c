#include <stdio.h>
#include "./headers/linked_list.h"

int main(int aplacac, char * aplacav[]){

    long int placa;
    unsigned int ano;
    double kilometragem;
    double peso;
    double valor;
    
    typeList* lista_carros = criarLSE();
    scanf("%ld", &placa);
    while(placa > 0){
        scanf("%d %lf %lf %lf", &ano, &kilometragem, &peso, &valor);

        typeData novo = (typeData){.placa=placa,
                            .peso=peso,
                            .kilometragem = kilometragem,
                            .valor = valor,
                            .ano = ano
                        };

        inserirFinalLSE(lista_carros, novo);
        scanf("%ld", &placa);
    }

    imprimirLSE(lista_carros);

    return 0;

}
