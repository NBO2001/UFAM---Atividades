#include <stdio.h>
#include <stdlib.h>
#include "libs/typeNodeGraph/typeNodeGraph.h"
#include "libs/typeLinkedList/linked_list.h"
#include "libs/typeEvent/typeEvent.h"
#include <assert.h>

int main(int argc, char* *argv){

    assert(argc==2);

    int qntItens;
    double maximunRadios;
    int idTmp;
    double positionXTmp;
    double positionYTmp;
    double distanceTmp;

    FILE *arq = fopen(argv[1], "r");

    TypeNodeGraph* *graph;
    typeList* events = newLinkedList(&comparatorEvent,sizeEvent());
    TypeEvent* event_push;
    TypeEvent* event_now;
    typeList* neighbors;
    

    fscanf(arq, "%d\t%lf", &qntItens, &maximunRadios);

    graph = (TypeNodeGraph**) malloc(sizeof(TypeNodeGraph*)*qntItens); 

    // Insert of the nodes
    for(int i=0; i<qntItens; i++){
        fscanf(arq,"%d\t%lf\t%lf", &idTmp, &positionXTmp, &positionYTmp);
        graph[i] = newNodeGraph(idTmp, positionXTmp, positionYTmp);
    }

    fclose(arq);

    
    // Find neighbors
    for(int i=0; i<qntItens; i++){
        
        for(int j=0; j<qntItens; j++){

            distanceTmp = distanceIntoNodes(graph[i], graph[j]);

            if( (i!=j) && (distanceTmp < maximunRadios)) addNeighbors(graph[i], graph[j]);
        }
    }

    event_push = newEvent(0,1.0, 1);

    insert_with_value(events, event_push);

    TypeNodeGraph* target;
    TypeNodeGraph* nextSend;

    while((event_now = (TypeEvent*) remove_start(events))){

        target = graph[getNodeId(event_now)];
        printEvent(event_now);
        
        neighbors = (typeList*) getNeighborsList(target);

        startInteration(neighbors);

        while ( !getVisited(target) && (nextSend = (TypeNodeGraph*) nextElement(neighbors)))
        {
            if(!getVisited(nextSend)){

                int idNext = getIdNode(nextSend);
                printf("\t--> Repassando pacote para o nó %d ...\n", idNext);
                event_push = newEvent(idNext, getTime(event_now) + 0.1 + ( idNext * 0.01), 1);

                insert_with_value(events, event_push);
            }
        }

        setVisited(target, 1);

    }
}