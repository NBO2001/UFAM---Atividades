#include <stdio.h>

// Retorna verdadeiro e alterar a variavel x1 caso o sistema tenha uma solucao. Retorna 0 caso contratio.
char calc_x1(int aplha, int beta, int b_barra, int a_barra, int b, int a, float * x1);

char calc_x2(int aplha, int beta, int b_barra, int a_barra, int b, int a, float * x2);


int main(){

    float x1, x2;
    int a=1, b=1, aplha=25; 
    int a_barra=4, b_barra=2, beta=74;

    if( calc_x1(aplha, beta, b_barra, a_barra, b, a, &x1) && calc_x2(aplha, beta, b_barra, a_barra, b, a, &x2)){

        printf("X1 = %.2f, X2 = %.2f\n", x1,x2);

    }else{
        printf("Sistema sem solucao\n");
    }



}

char calc_x1(int aplha, int beta, int b_barra, int a_barra, int b, int a, float * x1){

    float divisor, dividendo;

    divisor = a * ( (a*b_barra) - (a_barra*b) );

    if(!divisor) return 0;

    dividendo = (aplha * (b_barra - (a_barra*b)) ) - (b * ((a*beta)-(a*aplha)));

    *x1 =  dividendo/divisor;

    return 1;

}

char calc_x2(int aplha, int beta, int b_barra, int a_barra, int b, int a, float * x2){

    float divisor, dividendo;

    divisor = ( (a*b_barra) - (a_barra*b) );

    if(!divisor) return 0;

    dividendo = (a*beta) - (a_barra*aplha);

    *x2 =  dividendo/divisor;

    return 1;
}