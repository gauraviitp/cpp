#include <cassert>
#include <unordered_set>

using namespace std;
typedef unordered_set<int> US;

class Node {
public:
	int data;
	Node *next;
	Node(int d) : data(d), next(nullptr) {};
	void appendToTail(int d){
		Node *n = this;
		while(n->next){
			n = n->next;
		}
		n->next = new Node(d); // assign the end node 
	}
};

/*
 * Deletes the node provided in input.
 * It does so by copying the data from next to current
 * and deleting the next node.
 */ 
bool deleteNode(Node *nodeToDelete){
	if(nodeToDelete == nullptr || nodeToDelete->next == nullptr){
		return false;
	}
	Node *nextNode = nodeToDelete->next;
	nodeToDelete->data = nextNode->data;
	nodeToDelete->next = nextNode->next;
	delete nextNode;
	return true;
}

int main(){
	Node *list = new Node(0);
	list->appendToTail(1);
	list->appendToTail(2);
	list->appendToTail(3);
	list->appendToTail(4);
	list->appendToTail(5);
	bool res = deleteNode(list->next->next); // 2
	assert(res);
	assert(list->next->next->data == 3);
	res = deleteNode(list); // 0
	assert(res);
	assert(list->data == 1);
	res = deleteNode(list->next->next->next); // 5
	assert(!res);
	assert(list->next->next->next->data == 5);
}
