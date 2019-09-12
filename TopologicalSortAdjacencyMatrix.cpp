// Depth First Search
// Graph G is represented by Adjacency Matrix

#include <cassert>
#include <iostream>
#include <stack>
#include <unordered_set>
#include <vector>

using namespace std;
typedef vector<int> VI;
typedef vector<vector<int>> VVI;
typedef unordered_set<int> UI;

void depthFirstSearch(VVI &g, int curNode, UI &visited, stack<int> &sortedNodes){
	if(curNode < 0 || 
	   curNode >= g.size() ||
	   visited.find(curNode) != visited.end()){
		   return;
	   }
	visited.insert(curNode);
	for(int node = 0; node < (int)g.size(); ++node){
		if(g[curNode][node] != 0){
			if(visited.find(node) == visited.end()){
				depthFirstSearch(g, node, visited, sortedNodes);
			}
		}
	}
    sortedNodes.push(curNode);	
}

void topologicalSort(VVI &g, VI &order){
	UI visited;
	stack<int> sortedNodes;
	for(int node = 0; node < g.size(); ++node){
		depthFirstSearch(g, node, visited, sortedNodes);
	}
	while(!sortedNodes.empty()){
		int node = sortedNodes.top(); sortedNodes.pop();
		order.push_back(node);
	}
}

int main(){
	VVI g = 
	{
		{0, 0, 0, 1, 0, 0},
		{0, 0, 0, 1, 0, 1},
		{0, 0, 0, 0, 0, 1},
		{0, 0, 0, 0, 1, 1},
		{0, 0, 0, 0, 0, 1},
		{0, 0, 0, 0, 0, 0}
	};
	VI order;
	topologicalSort(g, order);
	assert(order.size() == 6);
	assert(order[0] = 2);
	assert(order[1] = 1);
	assert(order[2] = 0);
	assert(order[3] = 3);
	assert(order[4] = 4);
	assert(order[5] = 5);
}
