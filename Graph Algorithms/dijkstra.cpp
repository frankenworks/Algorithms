#include <vector>
#include "graph.h"
#include "graph_algorithms.h"
#define INF 0x7FFFFFFF

struct key_values {
	int key;
	int prev; 
	int distance;
	bool visited;
	key_values(int k, int p, int d, bool v)
		: key(k), prev(p), distance(d), visited(v) {}
};

inline int getKeyPos(int key, std::vector<key_values> dists) {
	for (int j = 0; j < dists.size(); j++) {
		if (dists[j].key == key) {
			return j;
		}
	}
}

inline bool check(Graph g, int key, std::vector<key_values> dists) {
	for (auto &i : g.getNode(key).adjNodes) {
		if (dists[getKeyPos((*i).key, dists)].visited == false) {
			return true;
		}
	}
	return false;
}

int dijkstra(Graph g, int start, int end) {
	std::vector<key_values> dists;
	int size = g.getSize();
	dists.reserve(size);

	// set initial values
	for (int i = 0; i < size; i++) {
		dists.emplace_back(g.getNodeKey(i), INF, INF, false);
	}
	dists[getKeyPos(start, dists)].distance = g.getNode(start).weight;

	// loop through adjacent nodes
	int current = start;
	while (check(g, current, dists)) {
		Node& currentNode = g.getNode(current);
		if (current == end) {
			// target found
			break;
		}
		else {
			// compute and set distances
			for (int i = 0; i < currentNode.adjNodes.size(); i++) {
				int& adjkey = (*(currentNode.adjNodes[i])).key;
				int adjpos = getKeyPos(adjkey, dists);
				bool& nodevisited = dists[adjpos].visited;
				if (nodevisited) {
					continue;
				}
				int& adjweight = (*(currentNode.adjNodes[i])).weight;
				int& currentdist = dists[getKeyPos(current, dists)].distance;
				int tempdist = currentNode.edgeWeights[i] + adjweight + currentdist;
				// if tempdist < dist of adj node
				if (tempdist < dists[adjpos].distance) {
					dists[adjpos].distance = tempdist;
					dists[adjpos].prev = current;
				}
			}
			// choose the shortest
			int tempdist = NULL;
			int tempkey = NULL;
			for (auto &i : currentNode.adjNodes) {
				int& adjkey = (*i).key;
				int adjpos = getKeyPos(adjkey, dists);
				bool& nodevisited = dists[adjpos].visited;
				if (nodevisited) {
					continue;
				}
				if (tempdist == NULL ||
					dists[adjpos].distance < tempdist) {
					tempdist = dists[adjpos].distance;
					tempkey = dists[adjpos].key;
				}
			}
			// change current
			dists[getKeyPos(current, dists)].visited = true;
			current = tempkey;
		}
	}
	return dists[getKeyPos(end, dists)].distance;
}