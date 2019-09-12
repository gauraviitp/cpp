// Depth First Search
// Graph G is represented by Adjacency Matrix

#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;
typedef vector<vector<int>> VVI;
typedef unordered_set<int> UI;

void visit(VVI &g, int curNode){
	cout << curNode << endl;
}

void depthFirstSearch(VVI &g, int curNode, UI &visited){
	visit(g, curNode);
	visited.insert(curNode);
	for(int node = 0; node < (int)g.size(); ++node){
		if(g[curNode][node] != -1){
			if(visited.find(node) == visited.end()){
				depthFirstSearch(g, node, visited);
			}
		}
	}	
}

void depthFirstSearch(VVI &g, int startNode){
	UI visited;
	depthFirstSearch(g, startNode, visited);
}

int main(){
	VVI g = 
	{
		{-1, 1, 1},
		{1, -1, 1},
		{1, 1, -1}
	};
	depthFirstSearch(g, 0);
}
