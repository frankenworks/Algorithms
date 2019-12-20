#include <vector>
#include "graph.h"

/*
to make weightless graphs/edges, you can create inline functions which call
functions addNode/addEdge etc and you can set the parameter for weight to an arbitrary value
minor code improvements can also be made with memory management such as implementing
shrink_to_fit on vectors after erase has been called, as well as other improvements
like declaring certain methods/variables as const and others I have not mentioned here
can also be done, however these are very minor improvements
*/

Node::Node(int k, int w) 
	: key(k), weight(w) {}

Graph::Graph() {}

Graph::Graph(int size) {
	nodes.reserve(size);
}

int Graph::getNodeKey(int pos) {
	return nodes[pos].key;
}

int Graph::getSize() {
	return nodes.size();
}

bool Graph::checkKeys(int key) {
	for (auto &n : nodes) {
		if (n.key == key) {
			return true;
		}
	}
	return false;
}

int Graph::getPos(int key) {
	for (int i = 0; i < nodes.size(); i++) {
		if (nodes[i].key == key) {
			return i;
		}
	}
	return -1;
}

Node& Graph::getNode(int key) {
	for (auto &n : nodes) {
		if (n.key == key) {
			return n;
		}
	}
}

std::vector<Node>::iterator Graph::getNodeIt(int key) {
	for (auto it = nodes.begin(); it != nodes.end(); ++it) {
		if ((*it).key == key) {
			return it;
		}
	}
}

void Graph::addNode(int key, int weight) {
	if (!checkKeys(key)) {
		nodes.emplace_back(key, weight);
	}
}

void Graph::addDEdge(int from, int to, int weight) {
	if (checkKeys(from) && checkKeys(to)) {
		this->getNode(from).adjNodes.push_back(this->getNodeIt(to));
		this->getNode(from).edgeWeights.push_back(weight);
	}
}

void Graph::addEdge(int from, int to, int weight) {
	this->addDEdge(from, to, weight);
	this->addDEdge(to, from, weight);
}

void Graph::removeNode(int key) {
	if (checkKeys(key)) {
		for (auto &i : getNode(key).adjNodes) {
			auto k = (*i).edgeWeights.begin();
			for (auto j = (*i).adjNodes.begin();
				j != (*i).adjNodes.end();) {
				if ((*j) == getNodeIt(key)) {
					(*i).adjNodes.erase(j);
					(*i).edgeWeights.erase(k);
					break;
				}
				else {
					++j;
					++k;
				}
			}
		}
		nodes.erase(getNodeIt(key));
	}
}