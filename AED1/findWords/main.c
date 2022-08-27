#include <stdio.h>
#include <stdlib.h>

// FACA AQUI SUA FUNCAO MOSTRA PALAVRAS

void mostraPalavras(FILE * fp){

    char value[150];

    while (fscanf(fp,"%[^\n!,. ]%*[\n!,. ]", value) == 1)
    {
        printf("%s\n", value);
    }
    

    fclose(fp);



}
// FIM DA FUNCAO


int main(){
    char nomeArq[30];
    char linha[2000];
    FILE *fp;

    scanf("%[^\n]",nomeArq);
    fp = fopen(nomeArq,"r");
    mostraPalavras(fp);

}