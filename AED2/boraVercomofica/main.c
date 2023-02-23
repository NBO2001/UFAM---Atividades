#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char isLetter(unsigned char letter){
    return !( 
        ( 0 <= letter &&  letter <=  57) 
    || ( 58 <= letter &&  letter <= 63) 
    || ( 91 <= letter &&  letter <= 96) 
    || ( 123 <= letter &&  letter <= 128)
    || ( 226 <= letter &&  letter <= 226)
    || ( 147 <= letter &&  letter <= 157)  
    || ( 8200 <= letter &&  letter <= 8230) 
    );
}

void cleaningWord(unsigned char * word){
    
    int tam = strlen(word);
    printf("t %d\n", word);
    int ctI = 0;
    int ctJ = tam-1;

    while (!isLetter(word[ctI])){ ctI++; }
    
    while (!isLetter(word[ctJ])){ ctJ--; }

    int i; 

    for(i = ctI; i <= ctJ; i++ ){ word[i-ctI] = word[i]; }

    word[i-ctI] = 0;

}

void lowerCase(unsigned char string[]){
    int size = strlen(string);
    for (int i = 0; i < size; i++){
        if (string[i] >= 65 && string[i] <= 90){
            string[i] += 32;
        }else if(string[i] >= 128 && string[i] <= 159){
            string[i] += 32;
        }else if((string[i] == 226) || (string[i] == 198)){
            i = i + 3;
        }
    }
    
}


void removeSpecialCharacters(unsigned char * string){

    int tamStr = strlen(string);
    int indexCopia = 0 ;

    int i = 0 ;
    
    while(i < tamStr){
        
        if(string[i] == 195){

            if((string[i+1] >= 160 && string[i+1] <= 165) || (string[i+1] >= 128 && string[i+1] <= 133) ) string[indexCopia] = 97;
            else if((string[i+1] >= 168 && string[i+1] <= 171) || (string[i+1] >= 136 && string[i+1] <= 139) ) string[indexCopia] = 101;
            else if( (string[i+1] >= 172 && string[i+1] <= 174) || (string[i+1] >= 140 && string[i+1] <= 143)   ) string[indexCopia] = 105;
            else if( (string[i+1] >= 178 && string[i+1] <= 181) || (string[i+1] >= 146 && string[i+1] <= 150)   ) string[indexCopia] = 111;
            else if( (string[i+1] >= 185 && string[i+1] <= 188) || (string[i+1] >= 153 && string[i+1] <= 156)   ) string[indexCopia] = 117;
            else if( (string[i+1] == 167 || string[i+1] == 135)    ) string[indexCopia] = 99;
            else if( (string[i+1] == 177)    ) string[indexCopia] = 110;

            indexCopia++;
            i = i + 2;

        }else if(string[i] == 194) i = i + 2;
        else if(string[i] == 226){
            string[indexCopia] = 39;
            indexCopia++;
            i = i + 3;
        }
        else if( string[i] == 198 ){
            string[indexCopia] = 102;
            indexCopia++;
            i = i + 3;
        }
        else{
            string[indexCopia] = string[i];
            indexCopia++;
            i++;
        }
    }

    string[indexCopia] = '\0';


}

int main(int argc, char * argv[]){

    unsigned char * key = malloc(50);

    strcpy(key, "coração");

    cleaningWord(key);
    lowerCase(key);
    removeSpecialCharacters(key);
    printf("%s\n", key);
    

    // FILE * fp = fopen("./test/stopwords_br.txt","r");

    
    // while (fscanf(fp,"%s", teste) == 1){
        
    //     removeSpecialCharacters(teste);

    //     printf("%s\n", teste);
    
    // }
    
  
    // fclose(fp);
}
