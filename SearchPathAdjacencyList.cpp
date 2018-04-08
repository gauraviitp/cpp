#include <cassert>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;

class Node{
public:
	int data;
	vector<Node *> adjacent;
	Node(int d) : data(d) {}
};

class Graph{
public:
	vector<Node *> nodes;
	void addEdge(Node *a, Node *b);
	bool searchPath(Node *start, Node *end);
};

void Graph::addEdge(Node *a, Node *b){
	a->adjacent.push_back(b);
}

bool Graph::searchPath(Node *start, Node *end){
	unordered_set<Node *> set;
	queue<Node *> q({start});
	while(!q.empty()){
		Node *curNode = q.front(); q.pop();
		set.insert(curNode); // add to visited set
		if(curNode == end){
			return true;
		}
		for(const auto& nextNode : curNode->adjacent){
			if(set.find(nextNode) == set.end()){
				q.push(nextNode);
			}
		}
	}
	return false;
}

void testSearchPath();

int main(){
	testSearchPath();
}

void testSearchPath(){
	Graph *g = new Graph();
	Node *n1 = new Node(1);
	Node *n2 = new Node(2);
	Node *n3 = new Node(3);
	Node *n4 = new Node(4);
	Node *n5 = new Node(5);
	Node *n6 = new Node(6);
	g->nodes.push_back(n1);
	g->nodes.push_back(n2);
	g->nodes.push_back(n3);
	g->nodes.push_back(n4);
	g->nodes.push_back(n5);
	g->nodes.push_back(n6);
	g->addEdge(n1, n4);
	g->addEdge(n1, n2);
	g->addEdge(n2, n3);
	g->addEdge(n4, n5);
	assert(!g->searchPath(n1, n6));
	assert(g->searchPath(n1, n2));
	assert(!g->searchPath(n2, n4));
	assert(!g->searchPath(n3, n4));
	assert(!g->searchPath(n2, n5));
	assert(g->searchPath(n2, n3));
	cout << "Passed :)" << endl;
}
