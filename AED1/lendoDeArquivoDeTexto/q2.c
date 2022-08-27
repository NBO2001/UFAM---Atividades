#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tipoPalavra{
    char word[50];
    int ocorrencia;
}tipoPalavra;


char cmp(tipoPalavra a, tipoPalavra b){

    if(a.ocorrencia >= b.ocorrencia ){
        return 1;
    }

    return 0;
}

// Funcao que intercala os valores
void intercalary(tipoPalavra als[], int inicio, int meio, int fim, tipoPalavra aux[]){

    int i, j,k=inicio;

    i = inicio;
    j = meio + 1;

    while( (i <= meio) && (j <= fim)){

        if(cmp(als[i],als[j])){
            aux[k] = als[i];
            i++;
        }else{
            aux[k] = als[j];
            j++;
        }

        k++;
    }

    while( i <= meio){
        aux[k] = als[i];
        i++;
        k++;
    }
    while( j <= fim){
        aux[k] = als[j];
        j++;
        k++;
    }

    for(i=inicio; i < k; i++){ als[i] = aux[i];  }

}

void mergeR(tipoPalavra v[], int inicio, int fim, tipoPalavra aux[]){

    int meio; 
    
    if (inicio < fim){
        meio = (inicio+fim)/2;

        mergeR(v, inicio, meio, aux);
        mergeR(v, meio+1, fim, aux);
        intercalary(v,inicio,meio,fim,aux);

    }

}

void merge(tipoPalavra als[], int tam){

    tipoPalavra *aux;

    aux = (tipoPalavra *) malloc(sizeof(tipoPalavra)*(tam+2));

    mergeR(als,0,tam-1,aux);

    free(aux);

}

int contaOcorrencia(tipoPalavra chave){
	int i;
	int ocorrencia=0; //erro2: sem valor inicial;
	tipoPalavra palavraAtual;
	FILE *fp;
	
	fp = fopen("./output/t4", "r");
	
	while(fscanf(fp,"%[^\n]%*c",palavraAtual.word) == 1){
	    if(strcmp(palavraAtual.word, chave.word ) == 0){
	        ocorrencia++;
	    }
	}
	fclose(fp);          
	return ocorrencia;
}

int naoEstaNoVetor(tipoPalavra v[], int tamVet, tipoPalavra palavra){
    int i;
    for(i=0; i<tamVet; i++){
        if(strcmp(palavra.word, v[i].word) == 0){
            return 0;
        }
    }
    return 1;
} 


void mostraMaioresOcorrencias(tipoPalavra listaDePalavras[]){
    FILE *fp;
    tipoPalavra palavraAtual;
    int i=0; //erro1: o i não tinha valor;
    
    fp = fopen("./output/t4", "r");
    
    while((fscanf(fp,"%[^\n]%*c",palavraAtual.word)==1)){   
        if(naoEstaNoVetor(listaDePalavras, i, palavraAtual)){  
        palavraAtual.ocorrencia = contaOcorrencia(palavraAtual);
        listaDePalavras[i] = palavraAtual;
        
        i++;
        }
    } 
    
    merge(listaDePalavras,i);
    
    for(i=0; i<5; i++){
        printf("%s %d\n",listaDePalavras[i].word, listaDePalavras[i].ocorrencia);
    }
    
    fclose(fp);
}



int main(){
    tipoPalavra lista[20000];
    mostraMaioresOcorrencias(lista);

    return 0;
}







