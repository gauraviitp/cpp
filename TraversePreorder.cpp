#include <cassert>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Node{
public:
	int data;
	Node *left, *right;
	Node(int d) : data(d), left(nullptr), right(nullptr){}
	Node(int d, Node *pleft, Node *pright) : data(d), left(pleft), right(pright){}
};

void processNode(Node *node, vector<Node *>& res){
	res.push_back(node);
}

void traversePreOrder(Node *root, vector<Node *>& res){
	stack<Node *> s;
	while(true){
		while(root){
			processNode(root, res);
			s.push(root);
			root = root->left;
		}
		if(s.empty()) break;
		root = s.top()->right; s.pop();
	}
}

void testTraversePreOrder();

int main(){
	testTraversePreOrder();
}

void testTraversePreOrder(){
	Node *root = new Node(10);
	root->left = new Node(5);
	root->left->left = new Node(2);
	root->left->left->left = new Node(1);
	root->left->left->right = new Node(3);
	root->left->left->right->right = new Node(4);
	root->left->right = new Node(8);
	root->left->right->left = new Node(6);
	root->left->right->left->right = new Node(7);
	root->right = new Node(15);
	root->right->left = new Node(13);
	vector<Node *> res;
	traversePreOrder(root, res);
	assert(res[0]->data == 10);
	assert(res[1]->data == 5);
	assert(res[2]->data == 2);
	assert(res[3]->data == 1);
	assert(res[4]->data == 3);
	assert(res[5]->data == 4);
	assert(res[6]->data == 8);
	assert(res[7]->data == 6);
	assert(res[8]->data == 7);
	assert(res[9]->data == 15);
	assert(res[10]->data == 13);
	
	Node *root2 = nullptr;
	vector<Node *> res2;
	traversePreOrder(root2, res2);
	assert(res2.size() == 0);
	
	cout << "Passed :)" << endl;
}
