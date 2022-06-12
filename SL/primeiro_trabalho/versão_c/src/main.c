/*
*
*/

#include<stdio.h>

int anyDecimalBase(char valuesOtherBase[], char origemBase);
char searchValue(char caracterFind);

int main(void){

    char numberForConvert[] = "Heloo hoe";

    printf("Digite o valor: ");
    scanf("%s", &numberForConvert);

    printf("%u \n\n", searchValue('F'));

    return 0;
}

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
            else if (caractes[2] < caracterFind){

                if (caractes[1] == caracterFind){
                    return 1;
                }
                else if (caractes[0] == caracterFind){
                    return 0;
                }

            }

            else if (caractes[2] > caracterFind){
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

int anyDecimalBase(char valuesOtherBase[], char origemBase){



}