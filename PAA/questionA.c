#include <stdio.h>

int main(){

    int toys;
    int heigthCarlos;

    scanf("%d %d", &toys, &heigthCarlos);

    int sum = 0;
    int tmp;
    for(int i =0; i < toys; i++){

        scanf("%d", &tmp);

        if(tmp <= heigthCarlos) sum+=1;
    }

    printf("%d\n", sum);

}