#include <queue>
#include "graph.h"
#include "graph_algorithms.h"

struct visited_bfs {
	int key;
	bool visited;
	visited_bfs(int k, bool v)
		: key(k), visited(v) {}
};

inline int getKeyPos(int key, std::vector<visited_bfs> mark) {
	for (int j = 0; j < mark.size(); j++) {
		if (mark[j].key == key) {
			return j;
		}
	}
}

bool bfs(Graph g, int start, int find) {
	std::vector<visited_bfs> mark;
	int size = g.getSize();
	mark.reserve(size);
	std::queue<int> bfs_queue;

	// set initial values
	for (int i = 0; i < size; i++) {
		mark.emplace_back(g.getNodeKey(i), false);
	}
	mark[getKeyPos(start, mark)].visited = true;

	// while queue not empty
	bfs_queue.push(start);
	while (!bfs_queue.empty()) {
		int s = bfs_queue.front();
		int pos = getKeyPos(s, mark);
		Node& current = g.getNode(s);
		bfs_queue.pop();
		// search and mark adjacent nodes
		for (auto &i : current.adjNodes) {
			int& adjkey = (*i).key;
			int adjpos = getKeyPos(adjkey, mark);
			if (!mark[adjpos].visited) {
				bfs_queue.push(adjkey);
				mark[adjpos].visited = true;
			}
			// if node found stop searching
			if (adjkey == find) {
				return true;
			}
		}
	}
	return false;
}