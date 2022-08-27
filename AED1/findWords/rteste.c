#include <stdio.h>
#include <stdlib.h>

// FACA AQUI SUA FUNCAO MOSTRA PALAVRAS

void mostraPalavras(FILE * fp){
    char palavra[200];
    
    while(fscanf(fp,"%[^\n!,. ]%*[\n!,. ]",palavra) ==1){
        printf("%s\n",palavra);
    }
    fclose(fp);
}



// FIM DA FUNCAO


int main() {
  char nomeArq[30];
  char linha[2000];
  FILE *fp;

  scanf("%[^\n]",nomeArq);
  fp = fopen(nomeArq,"r");
  mostraPalavras(fp);
}
