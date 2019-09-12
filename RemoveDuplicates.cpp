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
	void RemoveDuplicates(){
		Node *n = this;
		US set;
		set.insert(n->data);
		while(n->next){
			if(set.find(n->next->data) != set.end()){
				// delete the duplicate and remove from the list
				Node *t = n->next;
				// "next" for the subsequent iteration points to next of next
				n->next = n->next->next;
				delete t;
			}
			else {
				set.insert(n->next->data);
				// "next" for the subsequent iteration points to next of next
				n = n->next;
			}
		}
	}
};

int main(){
	Node *list = new Node(0);
	list->appendToTail(0);
	list->appendToTail(2);
	list->appendToTail(2);
	list->appendToTail(2);
	list->appendToTail(3);
	list->appendToTail(4);
	list->appendToTail(5);
	list->appendToTail(5);
	list->RemoveDuplicates();
	assert(list->data == 0);
	assert(list->next->data == 2);
	assert(list->next->next->data == 3);
	assert(list->next->next->next->data == 4);
	assert(list->next->next->next->next->data == 5);
}
