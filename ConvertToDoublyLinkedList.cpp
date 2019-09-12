// Start time - 9:57
// Find pair with given sum in BST
#include <bits/stdc++.h>

using namespace std;

class Node{
public:
	int data;
	Node *left, *right;
	Node() : data(0), left(nullptr), right(nullptr){}
	Node(int d) : data(d), left(nullptr), right(nullptr){}
	Node(int d, Node *pleft, Node *pright) : data(d), left(pleft), right(pright){}
};

void ConvertToDoublyLinkedList(Node *root, Node **head, Node **prev){
	if(!root){
		return;
	}
	ConvertToDoublyLinkedList(root->left, head, prev);
	if(!*head) {
		*head = root;
	}
	else {
		(*prev)->right = root;
		root->left = *prev;
	}
	*prev = root;
	ConvertToDoublyLinkedList(root->right, head, prev);
}

void testDoublyLinkedList();

int main(){
	testDoublyLinkedList();
}

void testDoublyLinkedList(){
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
	
	Node *head = nullptr, *prev = nullptr;
	ConvertToDoublyLinkedList(root, &head, &prev);
	assert(head != nullptr);
	assert((head)->data == 1);
	assert((head)->left == nullptr);
	assert((head)->right->data == 2);
	assert((head)->right->right->data == 3);
	assert((head)->right->right->right->data == 4);
	assert((head)->right->right->right->right->data == 5);
	assert((head)->right->right->right->right->right->data == 6);
}
