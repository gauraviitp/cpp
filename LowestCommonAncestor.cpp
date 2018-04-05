#include <cassert>

class Node{
public:
	int data;
	Node *left, *right;
	Node(int d) : data(d), left(nullptr), right(nullptr) {}
};

Node* lowestCommonAncestor(Node *root, Node *a, Node *b, bool &afound, bool &bfound){
	if(!root){
		return nullptr;
	}
	Node *left = lowestCommonAncestor(root->left, a, b, afound, bfound);
	Node *right = lowestCommonAncestor(root->right, a, b, afound, bfound);
	if(root == a){
		afound = true;
		return root;
	}
	else if(root == b){
		bfound = true;
		return root;
	}
	else if(left && right){
		return root;
	}
	else if(left){
		return left;
	}
	else if(right){
		return right;
	}
	return nullptr;
}

Node* lowestCommonAncestor(Node *root, Node *a, Node *b){
	bool afound = false, bfound = false;
	Node *res = lowestCommonAncestor(root, a, b, afound, bfound);
	if(afound && bfound){
		return res;
	}
	else {
		return nullptr;
	}
}

int main(){
	Node *root = new Node(10);
	root->left = new Node(5);
	root->left->left = new Node(2);
	root->left->left->left = new Node(1);
	root->left->left->right = new Node(3);
	root->left->right = new Node(8);
	root->left->right->left = new Node(7);
	root->left->right->right = new Node(9);
	root->right = new Node(15);
	root->right->left = new Node(13);
	root->right->right = new Node(16);
	assert(lowestCommonAncestor(root, root->left->left->left, root->left->right->left) == root->left);
}
