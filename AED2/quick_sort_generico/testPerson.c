#include <stdio.h>
#include "stdlib.h"
#include "quick_sort.h"
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
   
    //viewPeople(vet, n);

    printf("Ordenado por nome ---- \n");

    sort(vet,n, sizeof(typePerson), &cmp_name);

    viewPeople(vet, n);

    printf("Ordenado por peso ---- \n");

    sort(vet,n, sizeof(typePerson), &cmp_weight);

    viewPeople(vet, n);

}
