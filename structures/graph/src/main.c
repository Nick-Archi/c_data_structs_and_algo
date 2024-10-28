#include "graph_adj_mat.h"

int main(int argc, char * argv[])
{
	graph* g1 = create_graph(5);

	add_edge(g1, 0, 1);
	add_edge(g1, 1, 0);
	add_edge(g1, 2, 1);
	add_edge(g1, 1, 2);
	add_edge(g1, 3, 1);
	add_edge(g1, 1, 3);
	add_edge(g1, 0, 0);
	
	
	print_graph(g1);

	destory_graph(g1);

    return 0;
}
