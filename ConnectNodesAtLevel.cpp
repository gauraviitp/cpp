#include <cassert>

class Node{
public:
	int data;
	Node *left, *right, *rightSibling;
	Node(int d) : data(d), left(nullptr), right(nullptr), rightSibling(nullptr) {}
};

Node* getRightNode(Node *root){
	if(root->rightSibling){
		if(root->rightSibling->left){
			return root->rightSibling->left;
		}
		else if(root->rightSibling->right) {
			return root->rightSibling->right;
		}
	}
	return nullptr;
}


/*
 * Fill the rightSibling pointers in top to bottom and
 * right to left manner.
 */ 
void connectNodesAtLevel(Node *root){
	if(!root){
		return;
	}
	if(root->left){
		if(root->right){
			root->left->rightSibling = root->right;
		}
		else {
			root->left->rightSibling = getRightNode(root);
		}
	}
	if(root->right){
		root->right->rightSibling = getRightNode(root);
	}
	connectNodesAtLevel(root->right);
	connectNodesAtLevel(root->left);
}

int main(){
	
	// Test case 1.
	Node *root = new Node(10);
	root->left = new Node(5);
	root->left->left = new Node(3);
	root->left->left->left = new Node(1);
	root->right = new Node(15);
	root->right->right = new Node(17);
	root->right->right->right = new Node(19);
	connectNodesAtLevel(root);
	assert(root->left->left->left->rightSibling == root->right->right->right);
	assert(root->left->left->rightSibling == root->right->right);
	assert(root->left->rightSibling == root->right);
	assert(root->rightSibling == nullptr);
	
	
	// Test case 2.
	Node *a = new Node(10);
	a->left = new Node(5);
	a->left->left = new Node(3);
	a->left->left->left = new Node(1);
	a->left->right = new Node(7);
	a->left->right->left = new Node(6);
	a->right = new Node(15);
	a->right->right = new Node(17);
	a->right->right->left = new Node(18);
	a->right->right->right = new Node(19);
	connectNodesAtLevel(a);
	assert(a->left->left->left->rightSibling == a->left->right->left);
	assert(a->left->right->left->rightSibling == a->right->right->left);
}
