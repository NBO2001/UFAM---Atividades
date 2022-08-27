#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[50];
    int idade;
    char sexo;
}Pessoa;

int main(){
	int quantidade, i=0;
	FILE *fp, *fp2;
	Pessoa temp;
	
	fp= fopen("arq.bin","r");
	fp2= fopen("arq.txt","w+");
	
	fread(&quantidade, sizeof(int), 1, fp);
	fprintf(fp2,"%d\n",quantidade);
	
	while(i<quantidade){
		fread(&temp, sizeof(Pessoa), 1, fp);
		
		fprintf(fp2, "%s",temp.nome);
		fprintf(fp2, "%d",temp.idade);
		fprintf(fp2, "%hhd",temp.sexo);
		
		i++;
	}
	i=0;
	fseek(fp2,0,SEEK_SET);
	fscanf(fp2,"%d%*c",&quantidade);
	printf("%d",quantidade);
	
	while(i<quantidade){
		fscanf(fp2,"%[^\n]%*c",temp.nome);
		fscanf(fp2,"%d%*c",temp.idade);
		fscanf(fp2,"%hhd%*c",temp.sexo);
		
		printf("%s", temp.nome);
		printf("%d", temp.idade);
		printf("%hhd", temp.sexo);
		
		i++;
	}
	fclose(fp);
	fclose(fp2);
	
	
}