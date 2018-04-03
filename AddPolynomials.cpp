#include <cassert>

using namespace std;

class Node {
public:
	int data;
	Node *next;
	Node() : data(0), next(nullptr) {};
	Node(int d) : data(d), next(nullptr) {};
	void appendToTail(int d){
		Node *n = this;
		while(n->next){
			n = n->next;
		}
		n->next = new Node(d); // assign the end node 
	}
};

Node* add(Node *a, Node *b){
	Node *res = new Node(), *hres = res; // dummy head
	int carry = 0;
	while(a || b || carry){
		int sum = (a ? a->data : 0) + (b ? b->data : 0) + carry;
		carry = sum/10; // calculate carry for next iteration
		sum = sum%10; // adjust sum
		res->next = new Node(sum);
		res = res->next;
		if(a) a = a->next;
		if(b) b = b->next;
	}
	return hres->next;
}

int main(){
	Node *a = new Node(4);
	a->appendToTail(3);
	a->appendToTail(5);
	Node *b = new Node(2);
	b->appendToTail(7);
	b->appendToTail(5);
	Node *res = add(a, b);
	assert(res->data == 6);
	assert(res->next->data == 0);
	assert(res->next->next->data == 1);
	assert(res->next->next->next->data == 1);
}
