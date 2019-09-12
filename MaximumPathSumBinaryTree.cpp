// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

/*	Time begin - 10:17 AM
	Time end -  AM
	Desc: Maximum path sum in a binary tree.
*/

#include "stdafx.h"
#include <algorithm>
#include <climits>
#include <iostream>

using namespace std;
const int ninf = INT_MIN;

struct Node {
	int data;
	Node* left;
	Node* right;
	Node(int d) : data(d), left(NULL), right(NULL) {}
};

int maximumPathSum(Node* root, int& maxPath) {
	if (root == NULL) {
		return ninf;
	}
	
	// First: Check the max from left node and root node
	int leftValue = maximumPathSum(root->left, maxPath);
	if (leftValue != ninf) {
		maxPath = max(maxPath, root->data + leftValue);
	}

	// Second: Check the root
	maxPath = max(maxPath, root->data);

	// Third: Check the max from right node and root node
	int rightValue = maximumPathSum(root->right, maxPath);
	if (rightValue != ninf) {
		maxPath = max(maxPath, root->data + rightValue);
	}

	// Fourth: Check the max
	if (leftValue != ninf && rightValue != ninf) {
		maxPath = max(maxPath, leftValue + root->data + rightValue);
	}

	return max(root->data, root->data + max(leftValue, rightValue));
}

int main() {
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w+", stdout);
	Node* root = new Node(10);
	root->left = new Node(2);
	root->left->left = new Node(20);
	root->left->right = new Node(1);
	
	root->right = new Node(10);
	root->right->right = new Node(-25);
	root->right->right->left = new Node(3);
	root->right->right->right = new Node(4);
	int maxPath = ninf;
	maximumPathSum(root, maxPath);
	cout << maxPath << "\n";
}
