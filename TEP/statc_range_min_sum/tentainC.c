#include <stdio.h>

unsigned long long int sums[1000008];

unsigned long long int rangeSum(unsigned long long int *vet, int a, int b){

    if(a == 1) return vet[b];
    return vet[b] - vet[a-1];
}

int main(){
    int n, qnts;
    int a,b;
    int i = 1;
    
    scanf("%d %d", &n, &qnts);

    scanf("%llu", &sums[i]);
    i++;

    while(i <= n){
        scanf("%llu", &sums[i]);
        sums[i] = sums[i] + sums[i-1];
        i++;
    }

    for(int j=0; j < qnts; j++){
     
        scanf("%d %d",&a,&b);
        printf("%llu\n", rangeSum(sums, a,b));

    }
    

}