#ifndef _TYPE_PERSON_H
#define _TYPE_PERSON_H

typedef struct typePerson typePerson;

void viewPerson(typePerson * person);
void viewPeople(typePerson * people, int n);
char cmp_name(void * a, void * b);
char cmp_weight(void * a, void * b);
int sizeTypePerson();
char cmp_age(void * a, void * b);
char cmp_id(void * a, void * b);
typePerson * readPerson();

#endif