#include <stdio.h>
#include "hash_table.h"
#include "string.h"


int main(int argc, char * argv[]){
    
    typeHash people;
    int id;
	char name[50];
	int age;


    create_hash(&people,5);

    for(int i = 0; i < 5; i++){
        typeData person;
        scanf("%d%*c", &person.id);
        scanf("%[^\n]%*c", person.name);
        scanf("%d%*c", &person.age);
        
        insert_hash(&people,&person);

    }

    show_hash(&people);

}
