#include "queue.h"
#include "stdlib.h"

struct typeQueue{

    int length;
    int width;
    int fistElementIdx;
    int endElementidx;
    short isInfinity;
    void* *elements;

};

typeQueue * createQueue(int length){

    typeQueue * queue;

    queue = (typeQueue *) malloc(sizeof(typeQueue));

    queue->length = ( length > 0? length: 2);
    queue->isInfinity = ( length > 0? 0: 1);
    queue->endElementidx = -1;
    queue->fistElementIdx = 0;
    queue->width = 0;
    queue->elements = malloc(sizeof(void*)*queue->length);

    return queue;

}

char toQueue(typeQueue * queu, void * elemt){

    if(!(queu)){ return 0; }

    if( (queu->width >= queu->length) ){

        if(!queu->isInfinity){return 0; }

        int old_length = queu->length;

        queu->length = queu->length * 2;

        queu->elements = realloc(queu->elements, sizeof(void*)*queu->length);

        while(queu->endElementidx >= 0 && (queu->endElementidx < queu->fistElementIdx)){

            queu->elements[old_length] = queu->elements[queu->endElementidx];

            (queu->endElementidx)--;

            old_length++;

        }

        queu->endElementidx = old_length - 1;

        int varTemp = queu->fistElementIdx;

        queu->fistElementIdx = 0;

        for(int i=0; i < queu->width; i++){

            queu->elements[queu->fistElementIdx+i] = queu->elements[varTemp];
            (varTemp)++;

        }

        queu->endElementidx = queu->width - 1;


    }

    queu->endElementidx = (queu->endElementidx+1) % queu->length;

    queu->elements[queu->endElementidx] = elemt;

    (queu->width)++;

    return 1;

}

void * unqueue(typeQueue * queu){

    if(!(queu)){ return NULL; }
    
    if(queu->width == 0){ return NULL; }

    void * tmp = queu->elements[queu->fistElementIdx];

    queu->fistElementIdx = (queu->fistElementIdx+1) % queu->length;

    (queu->width)--;

    if(queu->width == 0){
        queu->endElementidx = -1;
    }

    return tmp;

}

int lenQueue(typeQueue * queu){

    if(!queu){ return -1; }

    return queu->width;
}

void * fistElement(typeQueue * queu){
    
    if(!queu){ return NULL; }

    return queu->elements[queu->fistElementIdx];
}