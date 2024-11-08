#include "graph_adj_mat.h"

int main(int argc, char * argv[])
{
    graph* g = initializeGraph(5);

    addEdge(g, 0, 1);
    addEdge(g, 1, 0);

    printAdjMap(g);

	destroyGraph(g);

    return 0;
}
