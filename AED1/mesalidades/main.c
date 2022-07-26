#include <stdio.h>

int main(){
    int kids;
    float desconto;
    float mesalidade;
    float valorComDesconto;

    scanf("%f", &mesalidade);
    scanf("%d", &kids);

    mesalidade = mesalidade*kids;

    if(kids == 1){
        desconto = mesalidade*(0.1);
    }else if(kids == 2 ){
        desconto = mesalidade*(0.3);
    }else{
        desconto = mesalidade*(0.4);
    }

    valorComDesconto = mesalidade-desconto;

    printf("%.1f\n", valorComDesconto);

}