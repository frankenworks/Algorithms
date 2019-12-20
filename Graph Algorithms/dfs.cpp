#include <stack>
#include "graph.h"
#include "graph_algorithms.h"

struct visited_dfs {
	int key;
	bool visited;
	visited_dfs(int k, bool v)
		: key(k), visited(v) {}
};

inline int getKeyPos(int key, std::vector<visited_dfs> mark) {
	for (int j = 0; j < mark.size(); j++) {
		if (mark[j].key == key) {
			return j;
		}
	}
}

bool dfs(Graph g, int start, int find) {
	std::vector<visited_dfs> mark;
	int size = g.getSize();
	mark.reserve(size);
	std::stack<int> dfs_stack;

	// set initial values
	for (int i = 0; i < size; i++) {
		mark.emplace_back(g.getNodeKey(i), false);
	}
	mark[getKeyPos(start, mark)].visited = true;

	// while stack not empty
	dfs_stack.push(start);
	while (!dfs_stack.empty()) {
		int s = dfs_stack.top();
		int pos = getKeyPos(s, mark);
		Node& current = g.getNode(s);
		// mark first adjacent node and move to it
		if (!current.adjNodes.empty()) {
			bool changed = false;
			for (auto &i : current.adjNodes) {
				int& adjkey = (*i).key;
				int adjpos = getKeyPos(adjkey, mark);
				if (!mark[adjpos].visited) {
					dfs_stack.push(adjkey);
					mark[adjpos].visited = true;
					changed = true;
					// if node found stop searching
					if (adjkey == find) {
						return true;
					}
					break;
				}
			}
			if (!changed) {
				dfs_stack.pop();
			}
		}
		else {
			dfs_stack.pop();
		}
	}
	return false;
}

