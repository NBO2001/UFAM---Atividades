    #include <stdio.h>

    int recorrenciaCaracter(char * string, char caracter){

        int contadorDeRecorrencias = 0;
        
        while (*string){
            if(*string == caracter) contadorDeRecorrencias++;
            *string++;
        } 
        return contadorDeRecorrencias;

    }

    int main(int argc, char * argv[]){

        char string[50];
        char caracter;

        scanf("%[^\n]%*c", string);
        scanf("%c", &caracter);

        printf("%s %c %d\n", string, caracter, recorrenciaCaracter(string, caracter));

    }
