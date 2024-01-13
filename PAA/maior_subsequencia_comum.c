#include <stdio.h>
#include <string.h>

int max(int a, int b){

    if(a > b) return a;
    else return b;

}

int biggerSubString(char* string1, char* string2){

    int tamStr1 = strlen(string1);
    int tamStr2 = strlen(string2);

    int matrizMatrizDinamic[tamStr1+1][tamStr2+1];

    // O(n)
    for(int i=0; i <= tamStr1; i++){
        matrizMatrizDinamic[i][0] = 0;
    }

    // O(m)
    for(int j=0; j <= tamStr2; j++){
        matrizMatrizDinamic[0][j] = 0;
    }

    // O(n*m) -> no pior caso n==m, logo, O(n^2)
    // Isso dá a equação O(n) + O(n) + O(n^2)
    for(int i=1; i <= tamStr1; i++){
        for(int j=1; j <= tamStr2; j++){

            if(string1[i-1] == string2[j-1]){
                
                matrizMatrizDinamic[i][j] = matrizMatrizDinamic[i-1][j-1] + 1;
            }else{

                matrizMatrizDinamic[i][j] = max(matrizMatrizDinamic[i-1][j],matrizMatrizDinamic[i][j-1]);
            }

        }
    }

    for(int i=0; i <= tamStr1; i++){
        for(int j=0; j <= tamStr2; j++){
            printf("%d ", matrizMatrizDinamic[i][j]);
        }
        printf("\n");
    }


    return matrizMatrizDinamic[tamStr1][tamStr2];

}


int main(int argc, char**argv){
    
    int bigger = biggerSubString(argv[1],argv[2]);

    printf("Maior eh: %d\n", bigger);

}