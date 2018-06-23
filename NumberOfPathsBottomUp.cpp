// Given a matrix of mxn, get the number of paths from bottom left to bottom right.
// Paths allowed are i. to the right, ii. to the right upwards, iii. to the right downwards.
// 2D dp can be optimized to 1D dp by keeping track of column being processed.

#include <cassert>
#include <iostream>
#include <algorithm>
#include <vector>

typedef long long ll;

using namespace std;
typedef pair<int, int> PI;
typedef vector<ll> VI;

ll BottomUp(PI& dims){
	if(dims.first == 0 || dims.second == 0){
		return 0;
	}
	VI dp(dims.first, 0);
	dp[dims.first - 1] = 1; // bottom left initialized to 1
	// lower left value
	ll pathsLeftDown = 0;
	for(int col = 1; col < dims.second; ++col){
		for(int row = dims.first - 1; row >= 0; --row){
			ll paths = dp[row];
			if(row - 1 >= 0){
				paths += dp[row - 1];
			}
			if(row + 1 < dims.first){
				paths += pathsLeftDown;
			}
			pathsLeftDown = dp[row];
			dp[row] = paths;
		}
	}
	return dp[dims.first - 1];
}

int main(){
	int rows = 2, cols = 2;
	PI dims = make_pair(rows, cols);
	assert(BottomUp(dims) == 1);
	
	int rows2 = 2, cols2 = 3;
	PI dims2 = make_pair(rows2, cols2);
	assert(BottomUp(dims2) == 2);
	
	int rows3 = 3, cols3 = 3;
	PI dims3 = make_pair(rows3, cols3);
	assert(BottomUp(dims3) == 2);
	
	int rows4 = 4, cols4 = 4;
	PI dims4 = make_pair(rows4, cols4);
	assert(BottomUp(dims4) == 4);
	
	int rows5 = 10, cols5 = 10;
	PI dims5 = make_pair(rows5, cols5);
	assert(BottomUp(dims5) == 835);
	
	int rows6 = 40, cols6 = 40;
	PI dims6 = make_pair(rows6, cols6);
	assert(BottomUp(dims6) == 22944749046030949);
	
	int rows7 = 1, cols7 = 1;
	PI dims7 = make_pair(rows7, cols7);
	assert(BottomUp(dims7) == 1);
	
	int rows8 = 0, cols8 = 0;
	PI dims8 = make_pair(rows8, cols8);
	assert(BottomUp(dims8) == 0);
}
