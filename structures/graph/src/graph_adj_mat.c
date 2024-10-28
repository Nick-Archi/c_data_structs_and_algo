#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#include "graph_adj_mat.h"

struct mygraph
{
	int numnodes;
	bool **edges;
};

graph* create_graph(int num)
{
	graph* new_graph = (graph*)calloc(sizeof(graph), 1);
	if(new_graph == NULL)
	{
		return new_graph;
	}
	new_graph->numnodes = num;

	// allocate matrix down here...
	new_graph->edges = (bool**)calloc(sizeof(bool*), new_graph->numnodes);
	if(new_graph->edges == NULL)
	{free(new_graph); return NULL;}

	for(int i = 0; i < new_graph->numnodes; i++)
	{
		new_graph->edges[i] = calloc(sizeof(bool), new_graph->numnodes);
		if(new_graph->edges[i] == NULL)
		{
			destory_graph(new_graph);
			return NULL;
		}
	}

	return new_graph; 
}
void destory_graph(graph* g)
{
	if(g->edges == NULL)
	return;

	for(int i = 0; i < g->numnodes; i++)
	{
		if(g->edges[i] != NULL)
		{
			free(g->edges[i]);
		}
	}

	free(g->edges);
	free(g);
}
void print_graph(graph* g)
{
	printf("digraph {\n");
	
	for(int from = 0; from < g->numnodes; from++)
	{
		for(int to = 0; to < g->numnodes; to++)
		{
			if(g->edges[from][to])
			{
				printf("%d -> %d;\n", from, to);
			}
		}
	}

	printf("}\n");
}
bool add_edge(graph* g, unsigned int from_node, unsigned int to_node)
{
	if(g->edges == NULL)
		return false;

	if(has_edge(g, from_node, to_node))
	{
		return false;
	}

	g->edges[from_node][to_node] = true;
	return true;
}
bool has_edge(graph* g, unsigned int from_node, unsigned int to_node)
{
	assert(g != NULL);
	assert(from_node < g->numnodes);
	assert(to_node < g->numnodes);
	return g->edges[from_node][to_node];
}
