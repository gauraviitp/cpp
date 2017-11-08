// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

/*	Time begin - 10:17 AM
	Time end -  AM
	Desc:	Construct complete binary tree from its linked list representation.
			Preorder traversal iterative version
			Inorder traversal iterative version
			Postorder traversal iterative version
*/

#include "stdafx.h"
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

struct LinkedListNode {
	int data;
	LinkedListNode* next;
	LinkedListNode(int d) : data(d), next(NULL) {}
};

struct BinaryTreeNode {
	int data;
	BinaryTreeNode* left;
	BinaryTreeNode* right;
	BinaryTreeNode(int d) : data(d), left(NULL), right(NULL) {}
};

typedef LinkedListNode LLNode;
typedef BinaryTreeNode BTNode;

void AppendLinkedListNode(LLNode** curNode, int data) {
	if (curNode == NULL || (*curNode) == NULL) return;
	else {
		(*curNode)->next = new LLNode(data);
	}
	(*curNode) = (*curNode)->next; // pointer value of curnode now points to the next node
}

BTNode* CreateCompleteBinaryTreeFromLinkedList(LLNode* head) {
	if (head == NULL) return NULL;
	BTNode* root = new BTNode(head->data);
	queue<BTNode*> q({ root });
	head = head->next;
	while (!q.empty()) {
		BTNode* parent = q.front(); q.pop();
		// create left child
		if (head) {
			parent->left = new BTNode(head->data);
			q.push(parent->left);
			head = head->next;
		}
		// create right child
		if (head) {
			parent->right = new BTNode(head->data);
			q.push(parent->right);
			head = head->next;
		}
	}
	return root;
}


void PrintPreorderBinaryTree(BTNode* root) {
	stack<BTNode*> s;
	while (true) {
		while (root) { // root acts as the current node
			cout << root->data << " ";
			s.push(root);
			root = root->left;
		}
		if (s.empty()) break;
		root = s.top(); s.pop();
		if (root) {
			root = root->right;
		}
	}
}

void PrintInorderBinaryTree(BTNode* root) {
	stack<BTNode*> s;
	while (true) {
		while (root) { // root acts as the current node
 			s.push(root);
			root = root->left;
		}
		if (s.empty()) break;
		root = s.top(); s.pop();
		cout << root->data << " ";
		if (root) {
			root = root->right;
		}
	}
}

void PrintPostorderBinaryTree(BTNode* root) {
	stack<BTNode*> s;
	while (true) {
		while (root) {
			s.push(root);
			root = root->left;
		}
		if (s.empty()) break;
		root = s.top()->right; // point the root to the right subtree of the current candidate in the stack
		if (root == NULL) {
			root = s.top(); s.pop();
			cout << root->data << " ";
			while (!s.empty() && s.top()->right == root) {
				root = s.top(); s.pop();
				cout << root->data << " ";
			}
			if (!s.empty()) root = s.top()->right;
			else root = NULL;
		}
	}
}

int main() {
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w+", stdout);
	LLNode* curNode = new LLNode(10), *head = curNode;
	AppendLinkedListNode(&curNode, 20);
	AppendLinkedListNode(&curNode, 15);
	AppendLinkedListNode(&curNode, 25);
	AppendLinkedListNode(&curNode, 30);
	AppendLinkedListNode(&curNode, 36);
	AppendLinkedListNode(&curNode, 40);
	AppendLinkedListNode(&curNode, 23);
	AppendLinkedListNode(&curNode, 28);
	AppendLinkedListNode(&curNode, 18);
	AppendLinkedListNode(&curNode, 24);
	AppendLinkedListNode(&curNode, 31);
	BTNode* root = CreateCompleteBinaryTreeFromLinkedList(head);
	PrintPreorderBinaryTree(root);
	cout << "\n";
	PrintInorderBinaryTree(root);
	cout << "\n";
	PrintPostorderBinaryTree(root);
}
