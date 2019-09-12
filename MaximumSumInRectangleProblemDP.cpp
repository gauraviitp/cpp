// maximum sum problem

// find the rectangle having maximum sum in a matrix

// Using DP

#include <algorithm>
#include <cassert>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<vector<ll>> VVI;

ll maximumSum(VVI& m){
	ll result = numeric_limits<ll>::min();
	int n = (int)m.size();
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j){
			if(i > 0) m[i][j] += m[i - 1][j];
			if(j > 0) m[i][j] += m[i][j - 1];
			if(i > 0 && j > 0) m[i][j] -= m[i - 1][j - 1];
		}
	for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j){ // start coordinate
		for(int k = i; k < n; ++k) for(int l = j; l < n; ++l){ // end coordinate
			ll tSum = m[k][l];
			if(i > 0) tSum -= m[i - 1][l];
			if(j > 0) tSum -= m[k][j - 1];
			if(i > 0 && j > 0) tSum += m[i - 1][j - 1];
			result = max(result, tSum);
		}
	}
	return result;
}


void test(){
	VVI m = 
	{
		{0, -2, -7, 0},
		{9, 2,  -6, 2},
		{-4, 1, -4, 1},
		{-1, 8, 0, -2}
	};
	ll result = maximumSum(m);
	assert(result == 15);
}

int main(){
	test();
}
