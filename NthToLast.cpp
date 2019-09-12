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
	Node* nthToLast(int k){
		Node *p1 = this, *p2 = p1;
		while(k-- > 1 && p1){
			p1 = p1->next;
		}
		if(p1 == nullptr){
			return nullptr;
		}
		while(p1->next){
			p1 = p1->next;
			p2 = p2->next;
		}
		return p2;
	}
};

int main(){
	Node *list = new Node(0);
	list->appendToTail(0);
	list->appendToTail(2);
	list->appendToTail(3);
	list->appendToTail(4);
	list->appendToTail(5);
	assert(list->nthToLast(3)->data == 3);
	assert(list->nthToLast(4)->data == 2);
	assert(list->nthToLast(6)->data == 0);
	assert(list->nthToLast(7) == nullptr);
}
