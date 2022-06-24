#include<stdio.h>


int retonaMaximoDointeio(){

     char tamanho_inteiro_em_bits = sizeof(int)*8;
     
     int tamanho_inteito_complento_de_dois = tamanho_inteiro_em_bits - 1;
     
     int valor_maximo=1,i;

     // Eleva o 2 a quantidade de bits.
     for(i=0; i < tamanho_inteito_complento_de_dois; i++){
          valor_maximo = valor_maximo*2;
     }

     valor_maximo = valor_maximo-1;

     // Retorna o modulo do valor máximo.
     if( valor_maximo>= 0 ){
          
          return valor_maximo;

     }else{
          return valor_maximo*(-1);
     }

}

int main(){

     int energia;

     printf("Começamos\n");

     energia = retonaMaximoDointeio();

     printf("O valor maximos is: %d\n", energia);

     return 0;
}