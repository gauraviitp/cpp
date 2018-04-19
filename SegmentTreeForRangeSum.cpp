// Segment tree to compute sum of a given range
// 11:35

#include <cassert>
#include <vector>

using namespace std;
typedef vector<int> VI;

int getSum(VI& tree, int sa, int ea, int qs, int qe, int ct){
	if(qs <= sa && qe >= ea){
		return tree[ct];
	}
	if(ea < qs || sa > qe){
		return 0;
	}
	int mid = (sa + ea) / 2;
	return 	getSum(tree, sa, mid, qs, qe, 2 * ct + 1) + 
		getSum(tree, mid + 1, ea, qs, qe, 2 * ct + 2);
}


int getSum(VI& tree, int qs, int qe, int sza){
	if(qs < 0 || qs >= sza || qs > qe){
		return -1;
	}
	return getSum(tree, 0, sza - 1, qs, qe, 0);
}

void constructSegmentTree(VI& array, int sa, int ea, VI& tree, int ct){
	if(sa == ea){
		tree[ct] = array[sa]; // set the leaf node and return
		return;
	}
	int mid = (sa + ea) / 2;
	constructSegmentTree(array, sa, mid, tree, 2 * ct + 1); // update the left child and subtree
	constructSegmentTree(array, mid + 1, ea, tree, 2 * ct + 2); // update the right child and subtree
	tree[ct] = tree[2 * ct + 1] + tree[2 * ct + 2]; // update the current node by adding left and right child
}

void constructSegmentTree(VI& array, VI& tree){
	int szTree = 2 * array.size() - 1;
	tree = VI(szTree, -1);
	constructSegmentTree(array, 0, array.size() - 1, tree, 0);
}

void updateSegmentTree(VI& array, VI& tree, int sa, int ea, int ui, int diff, int ci){
	if(ui < sa || ui > ea){
		return;
	}
	tree[ci] += diff;
	if(sa != ea) { // this check is required as mid become equal to sa at some point
		int mid = (sa + ea) / 2;
		updateSegmentTree(array, tree, sa, mid, ui, diff, 2 * ci + 1);
		updateSegmentTree(array, tree, mid + 1, ea, ui, diff, 2 * ci + 2);
	}
}

void updateSegmentTree(VI& array, VI& tree, int ui, int val){
	int diff = val - array[ui];
	array[ui] = val; // update the array
	// update the tree
	updateSegmentTree(array, tree, 0, array.size() - 1, ui, diff, 0);
}

int main(){
		VI array = {1, 3, 5, 7, 9, 11};
		VI tree;
		constructSegmentTree(array, tree);
		assert(getSum(tree, 0, 5, array.size()) == 36);
		assert(getSum(tree, 1, 2, array.size()) == 8);
		assert(getSum(tree, -1, 2, array.size()) == -1);
		assert(getSum(tree, 1, 4, array.size()) == 24);
		updateSegmentTree(array, tree, 1, 4);
		assert(getSum(tree, 0, 5, array.size()) == 37);
		assert(getSum(tree, 1, 2, array.size()) == 9);
		assert(getSum(tree, -1, 2, array.size()) == -1);
		assert(getSum(tree, 1, 4, array.size()) == 25);
}
