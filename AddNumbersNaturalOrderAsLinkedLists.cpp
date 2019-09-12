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
};

Node* add(Node *a, Node *b, int& carry){
	if(a && b){
		Node *n = add(a->next, b->next, carry);
		int sum = a->data + b->data + carry;
		carry = sum/10;
		sum = sum%10;
		return new Node(sum, n);
	}
	return nullptr;
}

void padLists(Node **a, Node **b){
	Node *na = *a, *nb = *b;
	while(na || nb){
		if(!na){
			*a = new Node(0, *a);
		}
		if(!nb){
			*b = new Node(0, *b);
		}
		if (na) na = na->next;
		if (nb) nb = nb->next;
	}
}

Node* add(Node *a, Node *b){
	padLists(&a, &b);
	int carry = 0;
	Node *res = add(a, b, carry);
	if (carry == 0) {
		return res;
	}
	else {
		return new Node(carry, res);
	}
}

int main(){
	Node *a = new Node(4);
	a->appendToTail(3);
	a->appendToTail(7);
	Node *b = new Node(6);
	b->appendToTail(7);
	b->appendToTail(5);
	Node *res = add(a, b);
	assert(res->data == 1);
	assert(res->next->data == 1);
	assert(res->next->next->data == 1);
	assert(res->next->next->next->data == 2);
}
