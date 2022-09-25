#include <stdio.h>
#include <stdlib.h>

typedef struct {

    char nome22[2];
    int id;
    char nome2[2];


} tipoDados;

void analise(char * nameFile){

    FILE * fp;
    char tm;
    char nome22[2];
    int id;
    char nome2[2];

    fp = fopen(nameFile, "r");

    if(fp == NULL){
        printf("Erro ao abrir o arquivo\n");
        exit(0);
    }
    fwrite(nome22,1,1,fp);

    printf("%s\n", nome22);
    // do{
    //     tm = fgetc(fp);
    //     if(tm == 'n'){
    //         printf("tell %ld \n", ftell(fp));
    //     }

    //     if(tm == 'a'){
    //         printf("tell %ld \n", ftell(fp));
    //     }

    //     printf("%c", tm);

    // }while(tm != EOF);
    

    fclose(fp);

}

int main(){
    analise("./output/data");
}