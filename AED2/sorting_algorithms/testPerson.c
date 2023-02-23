#include <stdio.h>
#include "stdlib.h"
#include "./heap_sort_generico/heap_sort.h"
#include <string.h>

typedef struct typePerson{

    int id;
    char name[50];
    double weight;
    int age;
    char email[50];

}typePerson;

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

int cmp_name(void * a, void * b){

    typePerson * aa = a;
    typePerson * bb = b;
    
    return strcmp(aa->name,bb->name);

}

int cmp_weight(void * a, void * b){

    typePerson * aa = a;
    typePerson * bb = b;
    
    return bb->weight - aa->weight;

}

int cmp_age(void * a, void * b){

    typePerson * aa = a;
    typePerson * bb = b;

    return aa->age - bb->age;

}

int main(int argc, char * argv[]){

    typePerson * vet;
    int n;

    scanf("%d%*c", &n);

    vet = malloc(sizeof(typePerson)*n);

    for(int i=0; i < n; i++){
        scanf("%d%*c", &vet[i].id);
        scanf("%[^\n]%*c", vet[i].name);
        scanf("%lf%*c", &vet[i].weight);
        scanf("%d%*c", &vet[i].age);
        scanf("%[^\n]%*c", vet[i].email);
    }
   
    viewPeople(vet, n);

    printf("Ordenado por nome ---- \n");

    heap_sort(vet,n, sizeof(typePerson), &cmp_name);

    viewPeople(vet, n);

}
