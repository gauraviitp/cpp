// Given a binary tree
// Find the maximum difference between node and its ancestors

#include <algorithm>
#include <cassert>

using namespace std;

class Node{
public:
	int data;
	Node *left, *right;
	Node(int d) : data(d), left(nullptr), right(nullptr){}
};

int MaxDiffNodeAncestor(Node *root, int left, int right){
	if(!root) return -1;
	int diffCurNode = max(abs(root->data - left), abs(root->data - right));
	int diffLeftSubtree = MaxDiffNodeAncestor(root->left, min(left, root->data), max(right, root->data));
	int diffRightSubtree = MaxDiffNodeAncestor(root->right, min(left, root->data), max(right, root->data));
	return max(diffCurNode, max(diffLeftSubtree, diffRightSubtree));
}

int MaxDiffNodeAncestor(Node *root){
	if(!root) return -1;
	return MaxDiffNodeAncestor(root, root->data, root->data);
}

int main(){
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
	int res = MaxDiffNodeAncestor(root);
	assert(res == 9);
}
