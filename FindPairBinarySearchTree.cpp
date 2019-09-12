// Start time - 9:57
// Find pair with given sum in BST
#include <bits/stdc++.h>

using namespace std;

class Node{
public:
	int data;
	Node *left, *right;
	Node(int d) : data(d), left(nullptr), right(nullptr){}
	Node(int d, Node *pleft, Node *pright) : data(d), left(pleft), right(pright){}
	void traverseInorder(vector<Node *>& res);
	bool findPair(int sum);
};

void Node::traverseInorder(vector<Node *>& res){
	if(left){
		left->traverseInorder(res);
	}
	res.push_back(this);
	if(right){
		right->traverseInorder(res);
	}
}

bool Node::findPair(int sum){
	vector<Node *> res;
	traverseInorder(res);
	int low = 0, high = res.size() - 1;
	while(low < high){
		if(res[low]->data + res[high]->data == sum){
			return true;
			low++;
		}
		else if(res[low]->data + res[high]->data < sum){
			low++;
		}
		else {
			high--;
		}
	}
	return false;
}

void testFindPair();

int main(){
	testFindPair();
}

void testFindPair(){
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
	root->right->left->left = new Node(12);
	assert(!root->findPair(1));
	assert(!root->findPair(2));
	assert(root->findPair(3));
	assert(root->findPair(4));
	assert(root->findPair(5));
	assert(root->findPair(6));
	assert(root->findPair(7));
	assert(root->findPair(8));
	assert(root->findPair(9));
	assert(root->findPair(10));
	assert(root->findPair(11));
	assert(root->findPair(12));
	assert(root->findPair(13));
	assert(root->findPair(14));
	assert(root->findPair(15));
	assert(root->findPair(16));
	assert(root->findPair(17));
	assert(root->findPair(18));
	assert(root->findPair(19));
	assert(root->findPair(20));
	assert(root->findPair(21));
	assert(root->findPair(22));
	assert(root->findPair(23));
	assert(root->findPair(25));
	assert(!root->findPair(30));
	assert(!root->findPair(0));
}
