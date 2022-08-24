#include <stdio.h>

void showFile(char  * fileName){

    FILE * fp;

    char value[2000];

    fp = fopen(fileName, "r");

    while (fscanf(fp,"%[^\n!,. ]%*[\n!,. ]", value) == 1)
    {
        printf("%s\n", value);
    }
    

    fclose(fp);

}

int main(){

    showFile("./output/t2");

}