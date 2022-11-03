#include <stdio.h>
#include "./headers/linked_list.h"
#include <string.h>

int main(int argc, char * argv[]){

    long int id;
    char name[60];
    double peso;
    int idade;
    char email[50];
    
    typeList* lista_pessoas = newList();
    scanf("%ld%*c", &id);
    while(id > 0){
        scanf("%[^\n]%*c", name);
        scanf("%lf%*c", &peso);
        scanf("%d%*c", &idade);
        scanf("%[^\n]%*c", email);
        
        typeData novo = (typeData){.idade=idade,
                            .peso=peso,
                            .id = id
                        };

        strcpy(novo.name,name);
        strcpy(novo.email,email);        

        inserirFinalLSE(lista_pessoas, novo);
        scanf("%ld%*c", &id);
    }

    printf("Tam: %d\n", tamanhoLSE(lista_pessoas));

    int flag=1;
    long int seach_id;
    while (flag)
    {
        scanf("%ld%*c", &seach_id);

        typeData retElement = buscarConteudoLSE(lista_pessoas, &seach_id);

        imprimirInfo(retElement);

        scanf("%d%*c", &flag);
    }
    
    

  
    //imprimirLSE(lista_pessoas);

    return 0;

}
