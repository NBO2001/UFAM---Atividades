#include <stdio.h>
#include "heap.h"
#include "typePerson.h"


int main(int argc, char * argv[]){

    typeHeap * heap = createHeap(sizeTypePerson(), &cmp_age);

    typePerson * person;

    int n;

    scanf("%d%*c", &n);

    for(int i=0; i < n; i++){
       
       person = readPerson();
       insertElement(heap,person);
       

    }

    do{
        
        person = removeElement(heap);

        if(person){
            viewPerson(person);
        }

    }while(person);

}
