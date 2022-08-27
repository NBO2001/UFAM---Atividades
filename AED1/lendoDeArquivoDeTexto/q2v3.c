#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tipoPalavra{
    char palavra[50];
    unsigned ocorrencias;
} tipoPalavra;

/*long int tamanhoArquivo2(FILE *fp){
    long int posicao = ftell(fp);
    fseek(fp, 0, SEEK_END);
    long int fim = ftell(fp);
    fseek(fp, posicao, SEEK_SET);
    return fim;
}*/




int tamanhoDoArquivoDeTexto(FILE *fp, char *nomeArquivo){
    int tam = 0;
    char palavra[50];
    fp = fopen(nomeArquivo, "r");
    while(fscanf(fp, "%[^\n]%*c", palavra) == 1){
        tam++;
    }
    fclose(fp);
    return tam;
}



void insereNoVetor(tipoPalavra vet[], char palavra[], unsigned *tam){
    int i;
    for ( i = 0; i < (*tam); i++){
        if (!strcmp(vet[i].palavra, palavra)){
            vet[i].ocorrencias ++;
            return;
        }
    }
    strcpy(vet[i].palavra, palavra);
    vet[i].ocorrencias = 1;
    (*tam)++ ;

}

void insereArquivoEmVetor(FILE *fp, tipoPalavra vet[], unsigned *tam){
    char palavra[50];
    int i = 0;
    while(fscanf(fp, "%[^\n]%*c", palavra) == 1){
        
        insereNoVetor(vet, palavra, tam);
        i++;
    }
    fclose(fp);
}





void mostraVetor(tipoPalavra vet[], int tam){
    for (int i = 0; i < tam; i++){
        printf("%s %d\n", vet[i].palavra, vet[i].ocorrencias);
    }
}








int main(){
    int tamanho;
    unsigned tamVet = 0;
    char *nome;
    nome = "./output/t4";
    FILE *fp;
    
    tamanho = tamanhoDoArquivoDeTexto(fp, nome);
    tipoPalavra vet[tamanho];
    fp = fopen(nome, "r");
    printf("%d\n", tamanho);
    
    insereArquivoEmVetor(fp, vet, &tamVet);

    mostraVetor(vet, tamVet);
}