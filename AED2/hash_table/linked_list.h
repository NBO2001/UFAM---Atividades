#ifndef _LINKED_LIST_H
#define _LIKEND_LIST_H

#include <stdlib.h>

typedef struct typeData{

	int id;
	char name[50];
	int age;

}typeData;

typedef struct typeNode{

	typeData data;
	struct typeNode * next;
	struct typeNode * previus;

}typeNode;

typedef struct typeList{

	typeNode * first;

}typeList;

// Create new linked list
void create(typeList * list);

// Create new node
typeNode * new_node(typeData * data);

// Insert at the beginning of the list
void insert_start(typeList * list, typeData * data);

// Insert at the end of the list
void insert_end(typeList * list, typeData * data);

// Get the last value from the list
typeData * last_element(typeList * list);

// Remove at the beginning of the list
typeData remove_start(typeList * list);

typeData * seach_in_list(typeList * list, void* key);

typeData remove_with_key(typeList * list, void* key);

int compare(typeData * data, void* key);

void show_datum(typeData * data);
void showDatas(typeList * list);

#endif
