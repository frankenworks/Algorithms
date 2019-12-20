#include <vector>
#include "graph.h"
#include "graph_algorithms.h"
#define INF 0x7FFFFFFF

struct dist_values {
	int key;
	int prev;
	int distance;
	dist_values(int k, int p, int d)
		: key(k), prev(p), distance(d) {}
};

inline int getKeyPos(int key, std::vector<dist_values> dists) {
	for (int j = 0; j < dists.size(); j++) {
		if (dists[j].key == key) {
			return j;
		}
	}
}

int bellmanford(Graph g, int start, int end) {
	std::vector<dist_values> dists;
	int size = g.getSize();
	dists.reserve(size);

	// set initial values
	for (int i = 0; i < size; i++) {
		dists.emplace_back(g.getNodeKey(i), INF, INF);
	}
	dists[getKeyPos(start, dists)].distance = g.getNode(start).weight;

	// iterate |V| - 1 times
	bool changed = true;
	for (int i = 0; i < size - 1; i++) {
		// if no change through previous iteration
		if (!changed) {
			break;
		}
		else {
			changed = false;
		}
		// compute and set distances
		for (int j = 0; j < size; j++) {
			int current = dists[j].key;
			Node& currentNode = g.getNode(current);
			for (int k = 0; k < currentNode.adjNodes.size(); k++) {
				int& adjkey = (*(currentNode.adjNodes[k])).key;
				int adjpos = getKeyPos(adjkey, dists);
				int& adjweight = (*(currentNode.adjNodes[k])).weight;
				int& currentdist = dists[getKeyPos(current, dists)].distance;
				int tempdist = currentNode.edgeWeights[k] + adjweight + currentdist;
				// if tempdist < dist of adj node
				if (tempdist < dists[adjpos].distance) {
					dists[adjpos].distance = tempdist;
					dists[adjpos].prev = current;
					changed = true;
				}
			}
		}
	}
	return dists[getKeyPos(end, dists)].distance;
}