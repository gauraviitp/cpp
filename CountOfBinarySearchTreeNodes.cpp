// C++ program to count BST nodes withing a given range
// Only getCount method is written by me

#include<bits/stdc++.h>
using namespace std;
 
// A BST node
struct node
{
    int data;
    struct node* left, *right;
};
 
// Utility function to create new node
node *newNode(int data)
{
    node *temp = new node;
    temp->data  = data;
    temp->left  = temp->right = NULL;
    return (temp);
}
 
// written by me
int getCount(node *root, int low, int high)
{
	if(!root){
		return 0;
	}
	
	// recur to the right
	if(root->data < low){
		return getCount(root->right, low, high);
	}
	// recur to the left
	else if(root->data > high){
		return getCount(root->left, low, high);
	}
	else {
		return getCount(root->left, low, high) + 
			   getCount(root->right, low, high) + 
			   1;
	}
	return 0;
}
 
// Driver program
int main()
{
    // Let us construct the BST shown in the above figure
    node *root        = newNode(10);
    root->left        = newNode(5);
    root->right       = newNode(50);
    root->left->left  = newNode(1);
    root->right->left = newNode(40);
    root->right->right = newNode(100);
    /* Let us constructed BST shown in above example
          10
        /    \
      5       50
     /       /  \
    1       40   100   */
    int l = 5;
    int h = 45;
    cout << "Count of nodes between [" << l << ", " << h
         << "] is " << getCount(root, l, h) << endl;
    return 0;
}
