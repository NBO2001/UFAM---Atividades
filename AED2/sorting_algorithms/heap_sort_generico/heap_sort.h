#ifndef _HEAP_SORT_H
#define _HEAP_SORT_H

typedef int (*heapCMP)(void*,void*);

/**
 * @brief 
 * 
 * @param vet 
 * @param n 
 * @param sizeEl 
 * @param comparatorFunction 
 */
void heap_sort(void* vet, int n, int sizeEl, heapCMP comparatorFunction );

#endif