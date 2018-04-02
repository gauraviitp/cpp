#include <cassert>

class Node {
public:
	int data;
	Node *next;
	Node(int d) : data(d), next(nullptr) {};
	void appendToTail(int d){
		Node *n = this;
		while(n->next != nullptr){
			n = n->next;
		}
		n->next = new Node(d); // assign the end node 
	}
};

int main(){
	Node *list = new Node(0), *nlist = list;
	list->appendToTail(1);
	list->appendToTail(2);
	list->appendToTail(3);
	assert(nlist->data == 0);
	nlist = nlist->next;
	assert(nlist->data == 1);
	nlist = nlist->next;
	assert(nlist->data == 2);
	nlist = nlist->next;
	assert(nlist->data == 3);
}
