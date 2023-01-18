#include <stdio.h>
#include <string.h>
#include "stdlib.h"
#include "heap.h"

struct typeHeap{

    void * els;
    int size;
    int sizeItem;
    int endIndx;
    comparator cmpf;

};

typeHeap * createHeap(int sizeItem, comparator cmpf){

    typeHeap * heap = malloc(sizeof(typeHeap));

    heap->size = 2;
    heap->els = malloc(sizeItem*heap->size);
    heap->sizeItem = sizeItem;
    heap->cmpf = cmpf;
    heap->endIndx = -1;

}

void rotateIni(typeHeap * heap, int father){

    int left = (2*father)+ 1;
    int rigth = (2*father) + 2;

    void * tmp;

    if( (rigth <= heap->endIndx) && (heap->cmpf(heap->els + (rigth*heap->sizeItem),heap->els + (father*heap->sizeItem)) > 0) ){

        if( (left <= heap->endIndx) && (heap->cmpf(heap->els + (left*heap->sizeItem),heap->els + (rigth*heap->sizeItem)) > 0)){

            tmp = malloc(heap->sizeItem);

            memcpy(tmp, heap->els + (left*heap->sizeItem), heap->sizeItem);
            memcpy(heap->els + (left*heap->sizeItem), heap->els + (father*heap->sizeItem), heap->sizeItem);
            memcpy(heap->els + (father*heap->sizeItem), tmp, heap->sizeItem);

            free(tmp);

            rotateIni(heap, left);

        }else{

            tmp = malloc(heap->sizeItem);

            memcpy(tmp, heap->els + (rigth*heap->sizeItem), heap->sizeItem);
            memcpy(heap->els + (rigth*heap->sizeItem), heap->els + (father*heap->sizeItem), heap->sizeItem);
            memcpy(heap->els + (father*heap->sizeItem), tmp, heap->sizeItem);

            free(tmp);

            rotateIni(heap, rigth);

            
        }

    }else{

        if( (left <= heap->endIndx) && (heap->cmpf(heap->els + (left*heap->sizeItem),heap->els + (father*heap->sizeItem)) > 0)){

            tmp = malloc(heap->sizeItem);

            memcpy(tmp, heap->els + (left*heap->sizeItem), heap->sizeItem);
            memcpy(heap->els + (left*heap->sizeItem), heap->els + (father*heap->sizeItem), heap->sizeItem);
            memcpy(heap->els + (father*heap->sizeItem), tmp, heap->sizeItem);

            free(tmp);

            rotateIni(heap, left);

        }else{

            return;

        }



    }

}

void rotate(typeHeap * heap, int father){

    if(father < 0){ return; }

    int left, rigth;
    
    int newFather = (father-1) >= 0? (father-1)/2: -1;

    void * tmp;
    left = (2*father)+ 1;
    rigth = (2*father) + 2;

    if( (rigth <= heap->endIndx) && (heap->cmpf(heap->els + (rigth*heap->sizeItem),heap->els + (father*heap->sizeItem)) > 0) ){
        
        tmp = malloc(heap->sizeItem);

        memcpy(tmp, heap->els + (rigth*heap->sizeItem), heap->sizeItem);
        memcpy(heap->els + (rigth*heap->sizeItem), heap->els + (father*heap->sizeItem), heap->sizeItem);
        memcpy(heap->els + (father*heap->sizeItem), tmp, heap->sizeItem);

        free(tmp);

        rotate(heap, newFather);
        return;
    }

    if((left <= heap->endIndx) && (heap->cmpf(heap->els + (left*heap->sizeItem),heap->els + (father*heap->sizeItem)) > 0)){

        tmp = malloc(heap->sizeItem);
        
        memcpy(tmp, heap->els + (left*heap->sizeItem), heap->sizeItem);
        memcpy(heap->els + (left*heap->sizeItem), heap->els + (father*heap->sizeItem), heap->sizeItem);
        memcpy(heap->els + (father*heap->sizeItem), tmp, heap->sizeItem);

        free(tmp);

        rotate(heap, newFather);
        return;
    }
    
    rotate(heap, newFather);



}


char insertElement(typeHeap * heap, void * item){

    if(heap->endIndx < 0){
        memcpy(heap->els, item, heap->sizeItem);

        (heap->endIndx)++;

        return 1;
    }else{

        heap->endIndx = heap->endIndx + 1;
        
        if(heap->endIndx >= heap->size){
            heap->size = heap->size*2;
            heap->els = realloc(heap->els, heap->sizeItem * heap->size);
        }

        memcpy(heap->els + (heap->endIndx*heap->sizeItem), item, heap->sizeItem);

        rotate(heap, heap->endIndx);     

        return 1;

    }



}

void * removeElement(typeHeap * heap){

    if(heap->endIndx < 0){ return NULL; }
    
    void * tmp_return = malloc(heap->sizeItem);

    memcpy(tmp_return, heap->els, heap->sizeItem);

    memcpy(heap->els, heap->els + (heap->endIndx * heap->sizeItem), heap->sizeItem);

    (heap->endIndx)--;

    rotateIni(heap,0);

    return tmp_return;
}