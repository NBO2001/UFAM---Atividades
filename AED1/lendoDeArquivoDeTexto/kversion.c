#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
 
/**
 * 50* sizeof(char)
 * Nao ha a necessidade de multiplicar pelo tamanho do char, o idea e̍ colocar o tamanho que voce deseja
 */
typedef struct repetidasPalavras{ 
 char palavra[200]; 
 int repete; 
} repetidasPalavras; 
 
void insereNaStruct(repetidasPalavras vet[], char palavraP[], unsigned cont, unsigned pos){ 
 for(unsigned k = pos; k < pos+1; k++){ 
  if (strcmp(vet[k].palavra,palavraP) == 0) return; 
 } 
 strcpy(vet[pos].palavra,palavraP); 
 vet[pos].repete = cont; 
} 
 
void ordenaStruct(repetidasPalavras vet[], unsigned pos){ 
 unsigned i,j; 
 repetidasPalavras aux; 
 for (i = 0; i < pos+1; i++){ 
  for (j = i+1; j < pos+1; j++){ 
   if(vet[i].repete > vet[j].repete){ 
    aux = vet[i]; 
    vet[i] = vet[j]; 
    vet[j] = aux; 
   } 
  } 
 } 
} 
 
void printaRepetidas(repetidasPalavras vet[], unsigned pos){ 
 for(unsigned i = 0; i< pos+1; i++){ 
  printf("%s %d", vet[i].palavra, vet[i].repete); 
 } 
} 

/**
 *  
 * Nao ha necessidade de usar essa mascara no scanf, como voce vai ler palavras
 * e no arquivos elas estao uma por linha, entao a leitura e̍ ate voce encontrar um \n
 * 
 */
void contaPalavras(FILE *fp){ 
 
 //char palavraT[50* sizeof(char)], palavraP[50* sizeof(char)]; 
 char palavraT[200], palavraP[200];

 unsigned cont = 0, pos = 0; 
 
 //repetidasPalavras vet[20000* sizeof(char)]; 
 repetidasPalavras vet[20000]; 

//  while(fscanf(fp,"%[-abcdefghijklmnopqkrstuvwxyzABCDEFGHIJKLMNOPQRSTUVXYZáéíóúÁÉÍÓÚÂÃÊÔÕâêôõãàüç]%*[^-abcdefghijklmnopqkrstuvwxyzABCDEFGHIJKLMNOPQRSTUVXYZáéíóúÁÉÍÓÚÂÃÊÔÕâêôõãàüç]",palavraP) == 1){ 
//   while(fscanf(fp,"%[-abcdefghijklmnopqkrstuvwxyzABCDEFGHIJKLMNOPQRSTUVXYZáéíóúÁÉÍÓÚÂÃÊÔÕâêôõãàüç]%*[^-abcdefghijklmnopqkrstuvwxyzABCDEFGHIJKLMNOPQRSTUVXYZáéíóúÁÉÍÓÚÂÃÊÔÕâêôõãàüç]",palavraT) == 1){ 
//    if(strcmp(palavraP,palavraT) == 0){ 
//     cont ++; 
//    } 
//   } 

   while(fscanf(fp, "%[^\n]%*c", palavraP) == 1){
        // Esse e um exemplo de como eu fiz, usei vetores ao inves de lista encadeada, pois para mim foi mais simples.
        insereNoVetor(vet, palavraP, tam);
        i++;
    } 

  insereNaStruct(vet,palavraP,cont,pos); 
  pos ++; 
 } 
 ordenaStruct(vet,pos); 
 printaRepetidas(vet,pos); 
 fclose(fp); 
} 
 
int main(){ 
 char nomeArq[15]; 
 char linha[20000]; 
 FILE *fp; 
 scanf("%[^\n]",nomeArq); 
 fp = fopen(nomeArq,"r"); 
 contaPalavras(fp); 
}