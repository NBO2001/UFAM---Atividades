#include "stdio.h"
#include "stdlib.h"
#include "libs/typePerson/typePerson.h"
#include "libs/typeTableHash/typeTableHash.h"

int main(int argc, char* *argv){

    const int tam = atoi(argv[1]);
    const char* nome_arquivo = argv[2];
    char name[51];
    long long int cpf;
    int age;
    
    FILE *arq = fopen(nome_arquivo, "r");

    typeTableHash * thash = createTableHash(.tam=tam);

    typePerson* person;
    while (fscanf(arq,"%50[^\t]\t%lld\t%d\n", name, &cpf, &age)==3){
        person = newPerson(name, cpf, age);
        insertTable(thash, getCPF(person), sizeof(long long int), person, size_person());
    }

    fclose(arq);

    typePerson* out;

    for(int i=0; i < tam; i++){
        printf("POSIÇÃO %d DA TABELA HASH:\n", i);
        do{
            out = removeForPosition(thash, i);
            if(out){
                print_person(out);
                free(out);
            }
            
        }while (out);
        
    }


}