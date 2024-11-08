// implement a graph using an adjacency map in C

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

typedef struct graph_t
{
	int num_of_nodes;
	bool** edges; // 2D matrix containing connections b/w nodes
}graph;

void destroyGraph(graph* g)
{
	if(g == NULL)
	{
		printf("graph is NULL\nExiting\n");
		return;
	}

	for(int i = 0; i < g->num_of_nodes; i++)
	{
		if(g->edges[i] != NULL)
		{
			free(g->edges[i]);
		}
	}

    free(g->edges);
    free(g);

	printf("Graph deleted\n");
	return;
}

graph* initializeGraph(int num_of_nodes)
{
	graph* g = (graph*)calloc(sizeof(graph), 1);
	if(g == NULL)
	{
		printf("Pointer Null\nExiting\n");
		return NULL;
	}

	g->num_of_nodes = num_of_nodes;

	// allocate space for 2D matrix
	g->edges = (bool**)calloc(sizeof(bool*), num_of_nodes);
	if(g->edges == NULL)
	{
		printf("g->edges NULL\nExiting\n");
		free(g->edges);
		return NULL;
	}

	// init each 1D vector in matrix
	for(int i = 0; i < g->num_of_nodes; i++)
	{
		g->edges[i] = (bool*)calloc(sizeof(bool), num_of_nodes);
		if(g->edges[i] == NULL)
		{
			printf("g->edges[%d] NULL\nExiting\n", i);
            destroyGraph(g);
			// destroy entire graph...
			return NULL;
		}
	}

	// grpah has been created..
	return g;
}

bool hasEdge(graph* g, int from, int to)
{
	assert(g != NULL);
	assert(from < g->num_of_nodes);
	assert(to < g->num_of_nodes);

	return g->edges[from][to];
}

void addEdge(graph* g, int from, int to)
{
	if(g == NULL)
	{
		printf("Graph Empty\n");
		return;
	}

	if(hasEdge(g, from, to) == false)
	{
		g->edges[from][to] = true;
		printf("Edge added from: %d, to: %d\n", from, to);
		return;
	}

	printf("Edge already exists b/w from: %d, and to: %d\n", from, to);
	return;
}

void printAdjMap(graph* g)
{
	if(g == NULL)
	return; 

	printf("digraph {\n");

	for(int from = 0; from < g->num_of_nodes; from++)
	{
		for(int to = 0; to < g->num_of_nodes; to++)
		{
			if(hasEdge(g, from, to))
			{
				printf("%d -> %d;\n", from, to);
			}
			//printf("from: %d, to: %d = %d\n", rows, cols, g->edges[rows][cols]);
		}
	}

    printf("}\n");
}