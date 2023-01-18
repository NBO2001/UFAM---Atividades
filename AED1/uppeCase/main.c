#include <stdio.h>

// 65 90
// 97 122
char upperOrlower(char c){

    if( c >= 65 && c <= 90){
        return c+32;
    }else{
        return c-32;
    }

}

int tam(char * string){

    int t = 0;
    while( string[t] != 0){ t++; }
    return t;

}

void invert(char * string){

    int t = 0;
    while( string[t] != 0){ 
        string[t] = upperOrlower(string[t]);
        t++; 
    }

}

int main(int argc, char * argv[]){

    char name[25];

    scanf("%s", name);

    invert(name);

    printf("%s\n", name);

}
