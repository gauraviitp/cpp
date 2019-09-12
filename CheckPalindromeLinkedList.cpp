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
	
	Node* reverseList(){
		Node *n = this, *prev = nullptr;
		while(n){
			Node *t = n->next;
			n->next = prev;
			prev = n;
			n = t;
		}
		return prev;
	}
	
	bool checkPalindrome(){
		Node *s = this, *f = this, *revpoint = s;
		while(f && f->next){
			revpoint = s;
			s = s->next;
			f = f->next->next;
		}
		Node *reversed = this; // handles simple case of one element in the list
		if(f){ // odd case
			Node *t = revpoint->next ? revpoint->next->next : nullptr;
			if(t){
				reversed = t->reverseList();
			}
			revpoint->next = nullptr;
		}
		else {
			Node *t = revpoint->next;
			if(t){
				reversed = t->reverseList();
			}
			revpoint->next = nullptr;
		}
		s = this;
		while(s || reversed){
			if((s && !reversed) || (!s && reversed) || (s->data != reversed->data)) {
				return false;
			}
			s = s->next;
			reversed = reversed->next;
		}
		return true;
	}
};

int main(){
	// negative test
	Node *a = new Node(4);
	a->appendToTail(3);
	a->appendToTail(2);
	a->appendToTail(5);
	assert(!a->checkPalindrome());
	
	// positive test - odd case
	Node *b = new Node(1);
	b->appendToTail(2);
	b->appendToTail(3);
	b->appendToTail(2);
	b->appendToTail(1);
	assert(b->checkPalindrome());
	
	// positive test - even case
	Node *c = new Node(1);
	c->appendToTail(2);
	c->appendToTail(3);
	c->appendToTail(3);
	c->appendToTail(2);
	c->appendToTail(1);
	assert(c->checkPalindrome());
	
	// negative test - even case
	Node *d = new Node(1);
	d->appendToTail(2);
	d->appendToTail(3);
	d->appendToTail(3);
	d->appendToTail(2);
	d->appendToTail(4);
	assert(!d->checkPalindrome());
	
	// negative test - odd case
	Node *e = new Node(1);
	e->appendToTail(2);
	e->appendToTail(3);
	e->appendToTail(2);
	e->appendToTail(4);
	assert(!e->checkPalindrome());
	
	// positive test - simple case
	Node *f = new Node(1);
	assert(f->checkPalindrome());

	// positive test - simple case
	Node *g = new Node(1);
	g->appendToTail(1);
	assert(g->checkPalindrome());	
	
	// negative test - simple case
	Node *h = new Node(1);
	h->appendToTail(2);
	assert(!h->checkPalindrome());
}
