#include <cassert>

using namespace std;

class Node {
public:
	int data;
	Node *next;
	Node() : data(0), next(nullptr) {};
	Node(int d, Node *n = nullptr) : data(d), next(n) {};
	void appendToTail(int d){
		Node *n = this;
		while(n->next){
			n = n->next;
		}
		n->next = new Node(d); // assign the end node 
	}
	Node* findFirstNode(){
		Node *s = this->next, *f = this->next ? this->next->next : nullptr;
		while(f && s != f){
			s = s->next;
			f = (f->next ? f->next->next : nullptr);
		}
		s = this;
		while(f && s != f){
			s = s->next;
			f = f->next;
		}
		if(!f) return nullptr;
		else return s;
	}
};

int main(){
	// positive test
	Node *a = new Node(4);
	a->appendToTail(3);
	a->appendToTail(2);
	a->appendToTail(5);
	a->next->next->next->next = a->next; // link back 5 to 3
	Node *res = a->findFirstNode();
	assert(res->data == 3);
	
	// negative test
	Node *b = new Node(4);
	b->appendToTail(3);
	b->appendToTail(2);
	assert(b->findFirstNode() == nullptr);
}
