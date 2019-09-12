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

template <typename T>
class Edge{
public:
	T source,
		dest;
	int	dist;
	Edge(T psource, T pdest, int pdist) :
		 source(psource),
		 dest(pdest),
		 dist(pdist){}
};


template <typename T>
class Graph{
public:
	Graph(){}
	virtual ~Graph(){}
	virtual vector<Edge<T>> getEdges(T source) = 0;
};

class AdjacencyMatrix : public Graph<int>{
private:
	VVI matrix;
public:
	AdjacencyMatrix(VVI pmatrix) : matrix(pmatrix){}
	~AdjacencyMatrix(){}
	vector<Edge<int>> getEdges(int source);
};

vector<Edge<int>> AdjacencyMatrix::getEdges(int source){
	vector<Edge<int>> edges;
	for(int node = 0; node < (int)matrix.size(); ++node){
		if(matrix[source][node] != 0){
			edges.push_back(Edge<int>(source, node, matrix[source][node]));
		}
	}
	return edges;
}

bool shortestPath(Graph<int> &g, int source, int dest, int &dist){
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
		for(auto node : g.getEdges(curNode)){
			if(visited.find(node.dest) == visited.end()){
				pq.push(make_pair(curDist + node.dist, node.dest));
			}
		}
	}
	return false;
}

int shortestPath(Graph<int> &g, int source, int dest){
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
	VVI matrix = 
	{
		{0, 10, 5, 7, 0, 0, 0},
		{0,  0, 0, 0, 1, 0, 0},
		{0,  0, 0, 1, 0, 4, 0},
		{0,  1, 0, 0, 0, 4, 6},
		{0,  0, 0, 1, 0, 0, 1},
		{0,  0, 0, 0, 0, 0, 1},
		{0,  0, 0, 0, 0, 0, 0}
	};
	AdjacencyMatrix g(matrix);
	int path = shortestPath(g, 0, 6);
	assert(path == 9);
}

