#include <cassert>
#include <iostream>

using namespace std;

class Node{
public:
	int data;
	Node *left, *right;
	Node(int d) : data(d), left(nullptr), right(nullptr){}
	Node(int d, Node *pleft, Node *pright) : data(d), left(pleft), right(pright){}
};

bool isBalanced(Node *root, int& height){
	if(!root){
		height = -1;
		return true;
	}
	int leftHeight, rightHeight;
	bool isLeftBalanced = isBalanced(root->left, leftHeight);
	bool isRightBalanced = isBalanced(root->right, rightHeight);
	height = max(leftHeight, rightHeight) + 1;
	return isLeftBalanced && isRightBalanced && (abs(leftHeight - rightHeight) <= 1);
}

bool isBalanced(Node *root){
	int height;
	return isBalanced(root, height);
}

void testIsBalanced();

int main(){
	testIsBalanced();
}

void testIsBalanced(){
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
	
	assert(!isBalanced(root));
	assert(isBalanced(root->left->left));
	assert(!isBalanced(root->left->right));
	assert(!isBalanced(root->left));
	assert(isBalanced(root->right->left));
	assert(!isBalanced(root->right));
	
	Node *root2 = nullptr;
	assert(isBalanced(root2));
	
	cout << "Passed :)" << endl;
}
