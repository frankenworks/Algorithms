#pragma once
#include "graph.h"

/*
All functions take in a Graph Object as a parameter
The graph object can also be passed by const reference for space efficiency
however this requires modification of some methods and results will be the same
These are not the only implementations of these algorithms, for example you can modify/extend
the Graph class for Nodes to have pointers/iterators point to the next/prev node/vertex
or you can even forego classes altogether and use an adjacency matrix/some other matrix;
data types can also be changed to allow more flexibility/functionality
*/

// search
bool bfs(Graph, int, int);
bool dfs(Graph, int, int);

// shortest path
int dijkstra(Graph, int, int);
int bellmanford(Graph, int, int);

// shortest path all pairs
// Coming Soon
// floyd-warshall, johnsons

// maximum flow
// Coming Soon
// ford-fullkerson, push-relabel, tarjan, dinic