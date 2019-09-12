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
	void breadthFirstSearch(vector<Node *>& res);
};

void Graph::addEdge(Node *a, Node *b){
	a->adjacent.push_back(b);
}

void visit(Node *node, vector<Node *>& res){
	res.push_back(node);
}

void breadthFirstSearch(Node *node, unordered_set<Node *>& set, vector<Node *>& res){
	queue<Node *> q({node});
	while(!q.empty()){
		Node *curNode = q.front(); q.pop();
		visit(curNode, res);
		set.insert(curNode); // set visited to true after visiting the node
		for(const auto& nextNode : curNode->adjacent){
			if(set.find(nextNode) == set.end()){
				q.push(nextNode);
			}
		}
	}
}

void Graph::breadthFirstSearch(vector<Node *>& res){
	unordered_set<Node *> set;
	using ::breadthFirstSearch;
	for(const auto& node : this->nodes){
		if(set.find(node) == set.end()){
			breadthFirstSearch(node, set, res);
		}
	}
}

void testBreadthFirstSearch();

int main(){
	testBreadthFirstSearch();
}

void testBreadthFirstSearch(){
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
	vector<Node *> res;
	g->breadthFirstSearch(res);
	assert(res[0] == n1);
	assert(res[1] == n4);
	assert(res[2] == n2);
	assert(res[3] == n5);
	assert(res[4] == n3);
	assert(res[5] == n6);
	cout << "Passed :)" << endl;
}
