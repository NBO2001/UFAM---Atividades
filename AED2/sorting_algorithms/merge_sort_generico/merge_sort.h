#ifndef _MERGE_SORT_H
#define _MERGE_SORT_H


typedef int (*mergeCMP)(void*, void*);

void merge_sort(void* vet, int n, int sizeEl, mergeCMP cmpFunction );


#endif