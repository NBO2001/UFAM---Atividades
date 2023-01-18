#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>

int power(int a, int n, int p){

    int res = 1;

    a = a % p;

    while( n > 0){
        
        if(n & 1){  res = (res*a) % p;  }

        n = n>>1;
        a = (a*a) % p;
    }

    return res;
}

int gcd(int a, int b){
    if(a < b)
        return gcd(b, a);
    else if(a%b == 0)
        return b;
    else return gcd(b, a%b); 
}

short isPrime(int n, int k){

    if (n <= 1 || n == 4)  return 0;
    if (n <= 3) return 1;

    while(k > 0){

        int a = 2 + rand()%(n-4);

        if(gcd(n,a) != 1) { return 0; }

        if(power(a, n-1, n)!=1){ return 0; }
        
        k--;

    }

}

int nextPrime(int* n){

    int k = 3;
    
    while (isPrime((*n), k) != 1){ (*n)++; }
    

}

int main(int argc, char * argv[]){

    // (2**2) % 4
    
    int n = 0x555582;
    nextPrime(&n);
    printf("%d\n", n );
}
