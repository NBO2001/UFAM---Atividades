#include <stdio.h>
#include <string.h>

char isLetter(unsigned char letter){
    return !( 
        ( 0 <= letter &&  letter <=  57) 
    || ( 58 <= letter &&  letter <= 63) 
    || ( 91 <= letter &&  letter <= 96) 
    || ( 123 <= letter &&  letter <= 128)
    || ( 226 <= letter &&  letter <= 226)
    || ( 152 <= letter &&  letter <= 157)  
    || ( 8200 <= letter &&  letter <= 8230) 
    );
}

const char * lowerCase(unsigned char string[]){

    int size = strlen(string);

    for (int i = 0; i < size; i++){
        if (string[i] >= 65 && string[i] <= 90){
            string[i] += 32;
        }else if(string[i] >= 128 && string[i] <= 159){
            string[i] += 32;
        }
    }
    return string;
}

void cleaningWord(unsigned char * word){

    int tam = strlen(word);

    int ctI = 0;
    int ctJ = tam-1;

    while (!isLetter(word[ctI])){ ctI++; }
    
    while (!isLetter(word[ctJ])){ ctJ--; }

    int i; 

    for(i = ctI; i <= ctJ; i++ ){ word[i-ctI] = word[i]; }

    word[i-ctI] = 0;

}

int main(int argc, char * argv[]){

    unsigned char strTeste[] = "‘a.’ ";

    unsigned char testaaa[150];
    
    // removeAccented(strTeste);
    

}
