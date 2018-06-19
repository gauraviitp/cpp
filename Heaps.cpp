// Build heap operation

#include <iostream>
#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;
typedef vector<int> VI;

int upperIndex(int n){
	int i = 1;
	for(;i <= n; i *= 2);
	return i - 1;
}

template<typename T>
void percolateDown(VI &v, int i, T op){
	int l = 2 * i + 1, r = 2 * i + 2;
	int imin = i;
	if(l < (int)v.size()){
		if(op(v[l], v[imin])){
			imin = l;
		}
	}
	if(r < (int)v.size()){
		if(op(v[r], v[imin])){
			imin = r;
		}
	}
	if(imin != i){
		swap(v[imin], v[i]);
		percolateDown(v, imin, op);
	}
}

template<typename T>
void buildHeap(VI &v, T op){
	for(int i = upperIndex(v.size()); i >= 0; --i){
		percolateDown(v, i, op);
	}
}

template<typename T>
void popHeap(VI &v, T op){
	int e = v[0]; // element to be popped
	v[0] = v[v.size() - 1];
	percolateDown(v, 0, op);
	v[v.size() - 1] = e;
}

template<typename T>
bool testHeap(VI &v, T op){
	for(int i = 0; i < (int)v.size(); ++i){
		if(i * 2 + 1 < (int)v.size()){
			if(op(v[i * 2 + 1], v[i])){
				return false;
			}
		}
		if(i * 2 + 2 < (int)v.size()){
			if(op(v[i * 2 + 2], v[i])){
				return false;
			}
		}
	}
	return true;
}

int main(){
	VI v = {100, 200, 300, 1, 2, 3, 4, 10, 250, 350, 450, 20, 30, 1000, 0};
	buildHeap(v, greater<int>());
	assert(testHeap(v, greater<int>()));
	//Test popHeap
	VI sorted(v);
	sort(sorted.begin(), sorted.end(), greater<int>());
	for(int i = 0; i < (int)v.size(); ++i){
		popHeap(v, greater<int>());
		assert(sorted[i] == v.back());
		v.pop_back();
	}
}
