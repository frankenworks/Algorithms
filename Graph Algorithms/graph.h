#pragma once
#include <vector>

/*
The Graph Class is used to create a graph with weighted nodes and edges
In this implementation, keys and weights are stored as integers, restricting values and functionality
You can edit this type however if you intend to use my implementation of graph algorithms,
you should also edit the type of affected/similar variables/methods to be consistent
*/

struct Node {
	int key;
	int weight;
	std::vector<std::vector<Node>::iterator> adjNodes;
	std::vector<int> edgeWeights;
	Node(int, int);
};

class Graph {
private:
	std::vector<Node> nodes;
public:
	Graph();
	Graph(int);
	int getNodeKey(int);
	int getSize();
	bool checkKeys(int);
	int getPos(int);
	Node& getNode(int);
	std::vector<Node>::iterator getNodeIt(int);
	void addNode(int, int);
	void addDEdge(int, int, int);
	void addEdge(int, int, int);
	void removeNode(int);
};