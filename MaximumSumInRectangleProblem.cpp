// maximum sum problem

// find the rectangle having maximum sum in a matrix

// following alogirthm solves it in O(n^6).

// DP should be used to improve upon this runtime.

#include <cassert>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<vector<ll>> VVI;

ll maximumSum(VVI& m){
	ll res = numeric_limits<ll>::min(); 
	int n = (int)m.size();
	for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j){ // start coordinate
		for(int k = i; k < n; ++k) for(int l = j; l < n; ++l){ // end coordinate
			ll tsum = 0;
			for(int p = i; p <= k; ++p) for(int q = j; q <= l; ++q){ // sum each cell in the rectangle
				tsum += m[p][q];
			}
			if(tsum > res) res = tsum;
		}
	}
	return res;
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
