// Given a matrix of mxn, get the number of paths from bottom left to bottom right.
// Paths allowed are i. to the right, ii. to the right upwards, iii. to the right downwards.

#include <cassert>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef pair<int, int> PI;
typedef vector<int> VI;
typedef vector<vector<int>> VVI;

bool isValid(PI &m, PI &cell){
	if(cell.first >= 0 && 
	   cell.first < m.first &&
	   cell.second >= 0 &&
	   cell.second < m.second){
		return true;
	}
	return false;
}

bool isBottomRight(PI &m, PI &cell){
	if(cell.first == m.first - 1 &&
	   cell.second == m.second - 1){
		return true;
	}
	return false;
}

int TopDown(PI &m, PI cell, VVI &dp){
	if(!isValid(m, cell)){
		return 0;
	}
	if(dp[cell.first][cell.second] != -1){
		return dp[cell.first][cell.second];
	}
	if(isBottomRight(m, cell)){
		return 1;
	}
	// Try in all the three directions
	int rightPaths = TopDown(m, make_pair(cell.first, cell.second + 1), dp);
	int rightUpPaths = TopDown(m, make_pair(cell.first + 1, cell.second + 1), dp);
	int rightDownPaths = TopDown(m, make_pair(cell.first - 1, cell.second + 1), dp);
	int paths = rightPaths + rightUpPaths + rightDownPaths;
	return (dp[cell.first][cell.second] = paths);
}

int TopDown(PI& dims){
	VVI dp(dims.first, VI(dims.second, -1));
	return TopDown(dims, make_pair(dims.first - 1, 0), dp);
}

int main(){
	int rows = 2, cols = 2;
	PI dims = make_pair(rows, cols);
	assert(TopDown(dims) == 1);
	
	int rows2 = 2, cols2 = 3;
	PI dims2 = make_pair(rows2, cols2);
	assert(TopDown(dims2) == 2);
	
	int rows3 = 3, cols3 = 3;
	PI dims3 = make_pair(rows3, cols3);
	assert(TopDown(dims3) == 2);
	
	int rows4 = 4, cols4 = 4;
	PI dims4 = make_pair(rows4, cols4);
	assert(TopDown(dims4) == 4);
}
