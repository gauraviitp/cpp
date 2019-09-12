#include <cassert>

class Node{
public:
	int data;
	Node *left, *right;
	Node(int d) : data(d), left(nullptr), right(nullptr){}
};

void nodesSum(Node *root){
	if(!root) return;
	nodesSum(root->left);
	nodesSum(root->right);
	root->data += (root->left ? root->left->data : 0) + (root->right ? root->right->data : 0);
}

void testNodesSum();

int main(){
	testNodesSum();
}

void testNodesSum(){
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
	nodesSum(root);
	assert(root->data == 86);
}
