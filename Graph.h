#ifndef GRAPH_H
#define GRAPH_H

#include "Edge.h"
#include "ST.h"


typedef struct graph *Graph;

Graph GRAPHinit(int);
void  GRAPHread(FILE *, Graph);
void  GRAPHpath(Graph);

#endif
