#include <stdio.h>
#include "stdlib.h"
#include "typePerson.h"
#include <string.h>

struct typePerson{

    int id;
    char name[50];
    double weight;
    int age;
    char email[50];

};

void viewPerson(typePerson * person){

    printf("{ id: %d, name: %s, email: %s, age: %d, weight: %lf}\n",
    person->id,
    person->name, 
    person->email, 
    person->age,
    person->weight);

}
void viewPeople(typePerson * people, int n){

    for(int i = 0; i < n; i++){
        viewPerson(people+i);
    }

}

char cmp_name(void * a, void * b){

    typePerson * aa = a;
    typePerson * bb = b;
    
    return strcmp(bb->name,aa->name);

}

char cmp_weight(void * a, void * b){

    typePerson * aa = a;
    typePerson * bb = b;
    
    return bb->weight - aa->weight;

}

char cmp_age(void * a, void * b){

    typePerson * aa = a;
    typePerson * bb = b;
    

    return aa->age - bb->age;

}

char cmp_id(void * a, void * b){

    typePerson * aa = a;
    typePerson * bb = b;
    

    return aa->id - bb->id;

}

typePerson * readPerson(){

    typePerson * person = malloc(sizeof(typePerson));

    scanf("%d%*c", &person->id);
    scanf("%[^\n]%*c", person->name);
    scanf("%lf%*c", &person->weight);
    scanf("%d%*c", &person->age);
    scanf("%[^\n]%*c", person->email);

    return person;
}

int sizeTypePerson(){
    return sizeof(typePerson);
}
