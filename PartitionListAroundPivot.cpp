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
	Node* partition(int pivot){
		Node *n = this, *less = nullptr, *hless = less, *more = nullptr, *hmore = more;
		while(n){
			if(n->data < pivot){
				if(less){
					less->next = n;
					less = less->next;
				} else {
					less = n;
					hless = less;
				}
			} else {
				if(more){
					more->next = n;
					more = more->next;
				} else {
					more = n;
					hmore = more;
				}
			}
			n = n->next;
		}
		less->next = hmore;
		return hless;
	}
};

int main(){
	Node *list = new Node(4), *nlist;
	list->appendToTail(1);
	list->appendToTail(5);
	list->appendToTail(2);
	list->appendToTail(7);
	list->appendToTail(3);
	nlist = list->partition(3);
	assert(nlist->data == 1);
	assert(nlist->next->data == 2);
	assert(nlist->next->next->data == 4);
	assert(nlist->next->next->next->data == 5);
	assert(nlist->next->next->next->next->data == 7);
	assert(nlist->next->next->next->next->next->data == 3);
	assert(nlist->next->next->next->next->next->next == nullptr);
}
