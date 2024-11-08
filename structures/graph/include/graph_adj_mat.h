#ifndef _GRAPH_ADJ_MAT_H_
#define _GRAPH_ADJ_MAT_H_

#include <stdbool.h>

typedef struct mygraph graph;

graph* initializeGraph(int num_of_nodes);
void destroyGraph(graph* g);
void printAdjMap(graph* g);
void addEdge(graph* g, int from, int to);
bool hasEdge(graph* g, int from, int to);

#endif //_GRAPH_ADJ_MAT_H_
