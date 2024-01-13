#include <stdio.h>
#include <stdlib.h>
#include "libs/typeNodeGraph/typeNodeGraph.h"
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

    fscanf(arq, "%d\t%lf", &qntItens, &maximunRadios);

    graph = (TypeNodeGraph**) malloc(sizeof(TypeNodeGraph*)*qntItens); 

    // Insert of the nodes
    for(int i=0; i<qntItens; i++){
        fscanf(arq,"%d\t%lf\t%lf", &idTmp, &positionXTmp, &positionYTmp);
        graph[i] = newNodeGraph(idTmp, positionXTmp, positionYTmp);
    }

    
    // Find neighbors
    for(int i=0; i<qntItens; i++){
        
        for(int j=0; j<qntItens; j++){

            distanceTmp = distanceIntoNodes(graph[i], graph[j]);

            if( (i!=j) && (distanceTmp < maximunRadios)) addNeighbors(graph[i], graph[j]);
        }
    }

    // View results
    for(int i=0; i<qntItens; i++){
        printNodeGraph(graph[i]);
    }


}