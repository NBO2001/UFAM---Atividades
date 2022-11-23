#ifndef _QUEUE_H
#define _QUEUE_H

typedef struct typeQueue typeQueue;

typeQueue * createQueue(int length);

char toQueue(typeQueue * queu, void * elemt);

void * unqueue(typeQueue * queu);

int lenQueue(typeQueue * queu);

void * fistElement(typeQueue * queu);

#endif