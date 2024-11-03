/*
* Most of the examples I found online of an adj graph seemed to use points that were
* contiguous, ex) 0 -> 1, 1 -> 2, 2 -> 0. What happens if I wanted to insert a 22 into the * graph and have that be connected with 1?
*
* Create an adjacency map that has these characteristics:
* structure that has a head node...
* head node will have children signifying edges
* each node could be a particular value, eg) Node.val = 59, inside head of Node.val = 1
	cont... edge from Node 1 -> Node 59
* hasEdge, addEdge, printGraph, functionality...
*
* This implementation should allow for swapping out the type of val in Node_t
* TODO: maybe create a C++ implementation one day?
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct Node_t
{
	int val;
}Node;

// linked list type DS for containing connected edges between nodes
typedef struct Edge_t
{
	Node* node; // node connected to head
	struct Edge_t* next; // pointer to next node
}Edge;

// characterizing a node in a graph
typedef struct Head_t
{
	Node* head;
	Edge* edges;
}Head;

typedef struct Graph_t
{
	int num_of_nodes;
	Head* vertices; // every point in the graph
}Graph;

Graph* initGraph(int num_of_nodes)
{
	Graph* g = (Graph*)calloc(1, sizeof(Graph));
	if(g == NULL)
	{
		printf("Error in calloc\n");
		return NULL;
	}

	g->num_of_nodes = num_of_nodes;

	// init storage for all possible vertices
	g->vertices = (Head*)calloc(g->num_of_nodes, sizeof(Head));
	for(int i = 0; i < g->num_of_nodes; i++)
	{
		/*
		* assign each head and edge to NULL initially
		* b/c calloc doesn't seem to do this for each entry?
		*/
		g->vertices[i].head = NULL;
		g->vertices[i].edges = NULL;
	}

	return g;
}

Head* findVertex(Graph* g, int val)
{
	if(g == NULL)
	{
		printf("Error\n");
		return NULL;
	}

	for(int i = 0; i < g->num_of_nodes; i++)
	{
		if(g->vertices[i].head != NULL && g->vertices[i].head->val == val)
		{
			return &(g->vertices[i]);
		}
	}

	return NULL;
}

Node* createNode(int val)
{
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->val = val;
	return new_node;
}

void addVertex(Graph* g, int val)
{
	if(g == NULL)
	{
		printf("Error\n");
		return;
	}

	if(findVertex(g, val) != NULL)
	{
		printf("Point already present. Not added!\n");
		return;
	}


	// place into graph's vertices 
	int i = 0;
	while(g->vertices[i].head != NULL)
	{
		i++;
	}

	g->vertices[i].head = createNode(val);
	
}

Edge* createEdge(Node* node)
{
	Edge* new_edge = (Edge*)malloc(sizeof(Edge));
	new_edge->node = node;
	new_edge->next = NULL;
	return new_edge;
}

void addEdge(Graph* g, int from, int to)
{
	if(g == NULL)
	{
		printf("Error\n");
		return;
	}

	Head* from_head = findVertex(g, from);
	if(from_head == NULL)
	{
		printf("Vertex not found in graph\n");
		return;
	}

	// search for to's vertex
	Head* to_head = findVertex(g, to);
	if(to_head == NULL)
	{
		printf("To's vertex hasn't been added yet\n");
		return;
	}

	// insert into vertex's edges
	if(from_head->edges == NULL)
	{
		from_head->edges = createEdge(to_head->head);
		printf("Added edge\n");
		return;
	}

	Edge* curr_edge = from_head->edges;
	while(curr_edge->next != NULL)
	{
		curr_edge = curr_edge->next;
	}

	curr_edge->next = createEdge(to_head->head);
	printf("eventually inserted the edge");
	return;
	
}

void deleteGraph(Graph* g)
{
	if(g == NULL)
	{
		printf("Cannot delete. NULL Graph\n");
		return;
	}
	
	int num_of_nodes = g->num_of_nodes;

	for(int i = 0; i < num_of_nodes; i++)
	{
		free(g->vertices[i].head);
		Edge* curr_edge = g->vertices[i].edges;
		while(curr_edge != NULL)
		{
			Edge* prev = curr_edge;
			curr_edge=curr_edge->next;
			free(prev);
		}
	}

	free(g);
	return;
}

void printGraph(Graph* g)
{
    for(int i = 0; i < g->num_of_nodes; i++)
    {
        if(g->vertices[i].head == NULL)
        {
            printf("NULL\n");
        }
        else
        {
            printf("vertex[%d], head = %d, EDGES: ", i, g->vertices[i].head->val);
		    Edge* curr = g->vertices[i].edges;
		    while(curr != NULL)
		    {
		    	printf("%d, ", curr->node->val);
		    	curr = curr->next;
		    }
		    printf("\n");
        }
    }
}

#define SIZE (4)
/*
int main()
{
	Graph* g = initGraph(SIZE);
//	printGraph(g);
	addVertex(g, 1);
	addVertex(g, 2);
	addVertex(g, 3);
	addVertex(g, 10);
	addEdge(g, 1, 2);
	addEdge(g, 1, 10);
	addEdge(g, 3, 10);
	addEdge(g, 10, 3);
	printGraph(g);
	deleteGraph(g);
	return 0;
}
*/