#ifndef _HEAP_H
#define _HEAP_H

typedef struct typeHeap typeHeap;
typedef char (*comparator)(void*, void*);

typeHeap * createHeap(int sizeItem, comparator cmpf);

char insertElement(typeHeap * heap,void * item);
void * removeElement(typeHeap * heap);

#endif