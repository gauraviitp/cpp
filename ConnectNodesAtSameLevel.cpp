// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

/*	Time begin - 10:51 AM
	Time end -  AM
	Desc: Connect nodes at the same level in a binary tree.
*/

#include "stdafx.h"
#include <iostream>

using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
	Node* nextRight;
	Node(int d, Node* l, Node* r) : data(d), left(l), right(r), nextRight(NULL) {}
	Node(int d) : data(d), left(NULL), right(NULL), nextRight(NULL) {}
};

Node* getNextRight(Node* root) {
	while (root->nextRight) {
		if (root->nextRight->left) {
			return root->nextRight->left;
		}
		else if (root->nextRight->right) {
			return root->nextRight->right;
		}
		root = root->nextRight;
	}
	return NULL;
}

void connectRecur(Node* root) {
	if (root) {
		if (root->nextRight != NULL) {
			connectRecur(root->nextRight);
		}
		if (root->left) {
			if (root->right) {
				root->left->nextRight = root->right;
			}
			else {
				root->left->nextRight = getNextRight(root);
			}
		}
		if (root->right) {
			root->right->nextRight = getNextRight(root);
		}
		if (root->left) {
			connectRecur(root->left);
		}
	}
}

void connect(Node* root) {
	if (root != NULL) {
		root->nextRight = NULL;
		connectRecur(root);
	}
}

void printNextNodes(Node* root) {
	if (root) {
		cout << root->data << " " << ((root->nextRight != NULL) ? root->nextRight->data : -1) << "\n";
		printNextNodes(root->left);
		printNextNodes(root->right);
	}
}

int main() {
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w+", stdout);
	Node *curNode = new Node(1);
	curNode->left = new Node(2);
	curNode->right = new Node(3);
	curNode->left->left = new Node(4);
	curNode->left->right = new Node(5);
	curNode->left->left->left = new Node(8);
	curNode->left->left->right = new Node(9);
	curNode->right->left = new Node(6);
	curNode->right->right = new Node(7);
	curNode->right->right->left = new Node(10);
	curNode->right->right->right = new Node(11);
	connect(curNode);
	printNextNodes(curNode);
}
