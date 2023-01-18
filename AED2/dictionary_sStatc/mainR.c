#include "./dicRom/dictionary.h"
#include "stdlib.h"
#include "string.h"
#include "stdio.h"

typedef struct TCarro{
    int ano;
    char modelo[20];
    char fabricante[30];
}TCarro;


TCarro* cria_carro(int ano, char nome[], char fabricante[]){
    TCarro* carro = malloc(sizeof(TCarro));
    
    carro->ano = ano;
    strcpy(carro->modelo, nome);
    strcpy(carro->fabricante, fabricante);
    
    return carro;
}

void imprime_carro(TCarro* carro){
    printf("Fabricante:%s\nModelo:%s\nAno: %d\n", carro->fabricante, carro->modelo, carro->ano);
}

int hashFunction(int k){ return k%10; }

int main(){
    TCarro* carro;
    TCarro* retorno;

    int ano;
    char modelo[20];
    char fabricante[30];
    
    printf("Insira o tamanho do dicionario: ");
    scanf("%d",&ano);
    TDSD* dict_carros = criar_DSD(ano, &hashFunction);
    
    while(ano>0){
        printf("\nAno:");
        scanf("%d%*c",&ano);
        
        printf("\nModelo:");
        scanf("%[^\n]%*c", modelo);

        printf("\nFabricante:");
        scanf("%[^\n]%*c",fabricante);
        
        carro = cria_carro(ano, modelo, fabricante);
        if(ano>0){
            inserir_DSD(dict_carros, carro->ano, carro);
        }
    }
    printf("\nDigite qual valor voce quer buscar:");
    scanf("%d%*c",&ano);
    retorno = buscar_DSD(dict_carros, ano);

    if(retorno){
        printf("O resultado para a busca '%d' foi:\n", ano);
        imprime_carro(retorno);
    }
    else{
        printf("Sem retorno...");
    }
    printf("\n---- FIM ---- \n");
   
}