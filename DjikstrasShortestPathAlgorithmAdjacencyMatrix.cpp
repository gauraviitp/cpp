// Djikstra's algorithm for shortest path
// It doesn't work for the graphs having negative edge weights
// Also it doesn't work for the graphs having negative cycles
// Anyways, finding path in a graph having negative cycle is a reduction of
// longest path problem and is NP-Hard.

// Priority Queue outputs the largest element first. So the elements
// that "come before" are actually output last. Hence, to use min queue
// we need to use std::greater class.

// Graph is represented by Adjacency Matrix

#include <algorithm>
#include <cassert>
#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;

typedef pair<int, int> PI;
typedef priority_queue<PI, vector<PI>, greater<PI>> PQ;
typedef unordered_set<int> UI;
typedef vector<int> VI;
typedef vector<VI> VVI;

bool shortestPath(VVI& g, int source, int dest, int &dist){
	PQ pq;
	pq.push(make_pair(0, source));
	UI visited({source});
	while(!pq.empty()){
		PI tpair = pq.top(); pq.pop();
		int curNode = tpair.second;
		int curDist = tpair.first;
		visited.insert(curNode);
		if(curNode == dest){
			dist = curDist;
			return true;
		}
		for(int node = 0; node < (int)g.size(); ++node){
			if(g[curNode][node] != 0 &&
			   visited.find(node) == visited.end()){
				pq.push(make_pair(curDist + g[curNode][node], node));
			}
		}
	}
	return false;
}

int shortestPath(VVI &g, int source, int dest){
	int dist;
	bool found = shortestPath(g, source, dest, dist);
	if(found){
		return dist;
	}
	else {
		return numeric_limits<int>::max();
	}
}

int main(){
	VVI g = 
	{
		{0, 10, 5, 7, 0, 0, 0},
		{0,  0, 0, 0, 1, 0, 0},
		{0,  0, 0, 1, 0, 4, 0},
		{0,  1, 0, 0, 0, 4, 6},
		{0,  0, 0, 1, 0, 0, 1},
		{0,  0, 0, 0, 0, 0, 1},
		{0,  0, 0, 0, 0, 0, 0}
	};
	int path = shortestPath(g, 0, 6);
	assert(path == 9);
}

