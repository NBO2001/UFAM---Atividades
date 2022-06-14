/*
* Autor: Natanael Bezerra De Oliveira
*
*/

#include<stdio.h>
#include <math.h>

/*
*   Para compilar o codigo use o comando: gcc main.c -o conversor -lm
*   Para execultar use: ./conversor
*   
*/


// Funções auxiliares
long anyDecimalBase(char valuesOtherBase[], char origemBase);
char searchValue(char caracterFind);
void appendV(char value, char arrayValues[]);
void decimnalParaQualquerBase(int number, char anyBase, char arrayResul[]);

int main(void){

    long acomulador=0;
    int baseOrgem=10, baseDestino = 10;
    char numberForConvert[100] = {'\000'}, numberConverted[100] = {'\000'};

    printf("Digite o valor: ");
    scanf("%s", &numberForConvert);

    printf("Digite a base de origem: ");
    scanf("%d", &baseOrgem);

    printf("Digite a base de destino: ");
    scanf("%d", &baseDestino);

    acomulador = anyDecimalBase(numberForConvert,baseOrgem);
    decimnalParaQualquerBase(acomulador,baseDestino,numberConverted);
    
    printf("Na base %d o resultado é %s \n",baseDestino, numberConverted);
    

    return 0;
}


// Função para converter decimal para qualquer base
void decimnalParaQualquerBase(int number, char anyBase, char arrayResul[])
{

    // Dicionario de caracters
	char dicionario[16] = {
			'0', '1', '2', '3',
			'4', '5', '6', '7',
			'8', '9', 'A', 'B',
			'C', 'D', 'E', 'F'
	};

    if (number >=0 ){
        while (number > 0)
        {
            // Adiciona valor no inicio do vetor
            appendV(dicionario[number%anyBase],arrayResul);

            number = number/anyBase;
        }
        
    }


}


//  função anyDecimalBase pela um valor em qualquer base e converte para decimal.
long anyDecimalBase(char valuesOtherBase[], char origemBase){


    long acomulador=0, letraVal, resulPow;

    int i,base=10, posicao=0;

    // Conta a quantidade de caracteres do vetor
    for (i=0; i < 255; i++){
        if (valuesOtherBase[i] == '\000'){
            break;
        }

        posicao++;
        
    }
    
    posicao = posicao - 1;

    for (i=0; i < 255; i++){

        // No primero valor vázio, sai do loop
        if (valuesOtherBase[i] == '\000'){
            break;
        }
        
        // Armazena o valor da letra
        letraVal = searchValue(valuesOtherBase[i]);

        // Base elevada a posição
        resulPow = pow(origemBase, posicao);

        // Acumula o resultado
        acomulador = acomulador + (letraVal * resulPow);

        if (posicao != 0){
            posicao--;
        }
        
    }
   
   return acomulador;
}

// Função auxiliar para adicionar valors no inicio de um vetor
void appendV(char value, char arrayValues[]){

    char i=0, tamanhoArray=0;

    // Conta a contidade de valores do vetor recebido
    while (1)
    {
        if(arrayValues[i] == '\000'){
            break;
        }

        i++;
        tamanhoArray++;

    }

    // Move os valores do vetor para uma posição posterior
    for (i; i > 0; i--){
        arrayValues[i] = arrayValues[i-1];
    }

    // Insere o valor no inicio do vetor
    arrayValues[0] = value;

    // Finaliza a string
    arrayValues[tamanhoArray+1] = '\000';
    

}

/*
*   A função searchValue procura uma string em um vetor com os valores
*   da tabela ascii e retorna seu equivalente em inteiro.
*   A função está definida para  '0' >= caracterFind <= 'F', o que equivale aos valores de 0 a 15.
*   
*   Tentei usar binarização para deixar o código mais rápido.
*/
char searchValue(char caracterFind){

    char caractes[17] = {48,49,50,51,52,53,54,55,56,57,65,66,67,68,69,70,71};

    // Verificando se está na metade
    if ( caractes[9] ==  caracterFind){
        return 9;
    }

    // Verificando se é menor que o valor procurado
    else if (caractes[9] > caracterFind){

        // Verifica se é a metade
        if ( caractes[5] ==  caracterFind){
            return 5;
        }

        // Verifica se é menor que a metade
        else if (caractes[5] >  caracterFind){

            // Dividindo na metade
            if (caractes[2] == caracterFind){
                return 2;
            }
            else if (caractes[2] > caracterFind){

                if (caractes[1] == caracterFind){
                    return 1;
                }
                else if (caractes[0] == caracterFind){
                    return 0;
                }

            }

            else if (caractes[2] < caracterFind){
                if (caractes[3] == caracterFind){
                    return 3;
                }
                else if (caractes[4] == caracterFind){
                    return 4;
                }
            }
        }
        // Verifica se é maior que a metade
        else if (caractes[5] <  caracterFind){

            // Vericando se é a metade

            if (caractes[7] == caracterFind){
                return 7;
            }
            else if (caractes[8] == caracterFind){
                return 8;
            }
            else if (caractes[6] == caracterFind){
                return 6;
            }

        }



    }
    // Verificando se é maior que o valor procurado
    else if (caractes[9] <  caracterFind){

        // dividindo na metade
        if (caractes[14] ==  caracterFind){
            return 14;
        }

        //Pode ser menor que 14
        else if (caractes[14] > caracterFind){

            if (caractes[13] == caracterFind){
                return 13;
            }
            else if (caractes[12] == caracterFind){
                return 12;
            }
            else if (caractes[11] == caracterFind){
                return 11;
            }
            else if (caractes[10] == caracterFind){
                return 10;
            }

        }

         //Pode ser maior que 14
        else if (caractes[14] < caracterFind){

            if (caractes[16] == caracterFind){
                return 16;
            }
            else if (caractes[15] == caracterFind){
                return 15;
            }
            else if (caractes[17] == caracterFind){
                return 17;
            }

        }
    
    }


}
