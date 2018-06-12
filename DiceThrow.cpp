// Time Start: 20:28

// Problem: Find the number of ways sum s can be obtained by throwing n "distinct (colored)" dices.

// Solution: 

// Recursion:

// Ways(i, n, s) = Summation of Ways(i + 1, n, s - j) for all j between 1 and k

// Ways(i, n, s) = 1 for i = n and s = 0
//				 = 0 for i = n and s != 0
// 				 = 0 for all s < 0              -- Missed this scenario in test


// Memoization table dp[dices][sum] should be used for dynamic programming solution

// Time Start: 20:49

#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;

// i denotes the dice number, n is total number of dice, and s is the sum
int Ways(int i, int n, int k, int s, VVI& dp){
	// Base case
	if(i == n + 1){
		if(s == 0){
			return 1;
		}
		else {
			return 0;
		}
	}
	if(s < 0){
		return 0;
	}
	
	if(dp[i][s] != -1){
		return dp[i][s];
	}
	
	int ways = 0;
	for(int j = 1; j <= k; ++j){
		ways += Ways(i + 1, n, k, s - j, dp);
	}
	return dp[i][s] = ways;
}

int Ways(int n, int k, int s){
	VVI dp(n + 1, VI(s + 1, -1));
	return Ways(1, n, k, s, dp);
}

int main(){
	assert(Ways(2, 4, 1) == 0);
	assert(Ways(2, 2, 3) == 2);
	assert(Ways(3, 6, 8) == 21);
	assert(Ways(2, 4, 5) == 4);
	assert(Ways(3, 4, 5) == 6);
}
