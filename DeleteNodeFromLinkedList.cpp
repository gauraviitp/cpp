#include <cassert>

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
	Node* deleteNode(int d){
		Node *n = this, *head = n;
		if(n->data == d){
			head = n->next;
			delete n;
			return head;
		}
		while(n->next){
			if(n->next->data == d){
				Node *t = n->next;
				n->next = n->next->next;
				delete t;
				return head;
			}
			n = n->next;
		}
		return head;
	} 
};

int main(){
	Node *list = new Node(0);
	list->appendToTail(1);
	list->appendToTail(2);
	list->appendToTail(3);
	list->appendToTail(4);
	list->appendToTail(5);
	list = list->deleteNode(3);
	list = list->deleteNode(5);
	list = list->deleteNode(0);
	assert(list->data == 1);
	assert(list->next->data == 2);
	assert(list->next->next->data == 4);
	assert(list->next->next->next == nullptr);
}
