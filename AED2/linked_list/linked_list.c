#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

// Create new linked list
void create(typeList * list){

	list->first = NULL;

}

// Create new node
typeNode * new_node(typeData * data){

	typeNode * node;

	node = (typeNode *) malloc(sizeof(typeNode));

	node->data = *data;
	node->next = NULL;
	node->previus = NULL;

}

// Insert at the beginning of the list
void insert_start(typeList * list, typeData * data){

	typeNode * new_nd = new_node(data);
	typeNode * aux;

	aux = list->first;

	if(aux){

		aux->previus = new_nd;
		new_nd->next = aux;

	}

	list->first = new_nd;

}

typeData remove_start(typeList * list){

	typeNode * aux;
	typeData data;

	aux = list->first;

	if(aux){

		list->first = aux->next;

		list->first->previus = NULL;
	
	}

	data = aux->data;

	free(aux);

	return data;

}


typeData * seach_in_list(typeList * list, int key){

	typeNode * aux;

	aux = list->first;

	while( aux && aux->data.id != key){
		aux = aux->next;
	}

	if(aux){
		return &(aux->data);
	}else{
		return NULL;
	}



}

typeData remove_with_key(typeList * list, int key){

	typeNode* aux, *tmp;
	typeData data;

	aux = list->first;

	while( aux && aux->data.id != key){
		aux = aux->next;
	}


	if(aux){
		if(aux->previus){

			aux->previus->next = aux->next;

			if(aux->next){
				aux->next->previus = aux->previus; 
			}
			
		
		}else{
			
			list->first = aux->next;
			list->first->previus = NULL;

		}
		data = aux->data;
		free(aux);

		return data;
	}else{
		return data;
	}

}

void insert_end(typeList * list, typeData * data){

	typeNode * aux;
	
	typeNode * new_nd = new_node(data);

	aux = list->first;

	while (aux && aux->next)
	{
		aux = aux->next;
	}
	if(aux){

		new_nd->previus = aux;
		aux->next = new_nd;
	
	}else{
		list->first = new_nd;
	}

}

typeData * last_element(typeList * list){

	typeNode * aux;
	
	aux = list->first;

	while(aux && aux->next){
		aux = aux->next;
	}

	if(aux){
		return &(aux->data);
	}else{
		return NULL;
	}

}
void show_datum(typeData * data){

	printf("{ id: %d, name: %s, age: %d } \n", data->id, data->name, data->age);
}

void showDatas(typeList * list){

	typeNode * aux;

	aux = list->first;

	while(aux){
		show_datum(&aux->data);
		aux = aux->next;
	}

}
