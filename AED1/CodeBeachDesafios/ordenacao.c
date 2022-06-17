#include<stdio.h>

int main(){

    int arrayOredenado[3], i, valor0, valor1, valor2;

    scanf("%d", &valor0);
    scanf("%d", &valor1);
    scanf("%d", &valor2);

    if (valor1 > valor0 && valor1 > valor2 ){

        arrayOredenado[2] = valor1;

        if (valor0 > valor2){

            arrayOredenado[0] = valor2;
            arrayOredenado[1] = valor0;
            
        }else{

            arrayOredenado[0] = valor0;
            arrayOredenado[1] = valor2;
            
        }
    }else{
        if ((valor1 > valor0)^(valor1 > valor2) ){
            
            arrayOredenado[1] = valor1;

            if(valor0 > valor2){
                arrayOredenado[0] = valor2;
                arrayOredenado[2] = valor0;
            }else{
                arrayOredenado[0] = valor0;
                arrayOredenado[2] = valor2;
            }
        }else{

            arrayOredenado[0] = valor1;

            if(valor0 > valor2){
                arrayOredenado[1] = valor2;
                arrayOredenado[2] = valor0;
            }else{
                arrayOredenado[1] = valor0;
                arrayOredenado[2] = valor2;
            }
        }
    }

    for(i=0; i < 3; i++){
        printf("%d\n", arrayOredenado[i]);
    }

    return 0;
}
/*
-40
10
-90
*/