#include <stdio.h>
#include <stdlib.h>

// FACA AQUI SUA FUNCAO MOSTRA PALAVRAS
char exists(char word){
    
    char words[24] = {'-','á','é','í','ó','ú','Á','É','Í','Ó','Ú','Â','Ã','Ê','Ô','Õ','â','ê','ô','õ','ã','à','ü','ç'};

    if((word >= 97 && word <= 122) || word >= 65 && word <= 90){
        return 1;

    }

    for(int i=0; i < 24; i++){
        if(words[i] == word){
            return 1;
        }
    }
    return 0;

}

void mostraPalavras(FILE * fp){
    char ctc, barraN=0;


    do{
        ctc = fgetc(fp);

        if(feof(fp) == EOF) return;
        if(exists(ctc)){
            barraN = 0;
            printf("%c", ctc);
        }else{
            if(!barraN){
                printf("\n");
                barraN = 1;
            }
        }
        
    }while(ctc != EOF);



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