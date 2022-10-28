#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

typedef struct
{
    char name[20];
    unsigned int age;
    unsigned id;

}typePerson;

typedef struct typeCitys
{
    
    int id;
    char isFull;


} typeCitys;


void showPesson(typePerson * person){

    printf("{ id: %d,name: %s, age: %d }\n", person->id, person->name, person->age);

}
void showCyt(typeCitys * cyt){

    printf("{ id: %d, isFull: ", cyt->id);

    if(cyt->isFull == 1){
        printf("True");
    }else{
        printf("False");
    }

    printf(" }\n");

}

int main(int argc, char * argv[]){

    typePerson pen;
    
    typeCitys manaus;

    typeList list, listCitys;

    create(&list);
    create(&listCitys);

    strcpy(pen.name, "Natanael B");
    pen.age = 21;
    pen.id = 1;

    insert(&list, &pen);

    show_list(&list,&showPesson);

    manaus.id = 1;
    manaus.isFull = 1;

    insert(&listCitys, &manaus);

    manaus.id = 2;
    manaus.isFull = 0;

    insert(&listCitys, &manaus);

    show_list(&listCitys,&showCyt);


   
}