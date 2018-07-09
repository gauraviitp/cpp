// UVa 10003
// Cutting sticks

#include <algorithm>
#include <cassert>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<ll> VL;
typedef vector<VL> VVL;


ll cut(VL& v, int left, int right, VVL& dp){
	if(right == left + 1 || right == left){
		return 0;
	}
	//assert(left >= 0);
	//assert(right < v.size());
	if(dp[left][right] != -1){
		return dp[left][right];
	}
	ll cost = numeric_limits<ll>::max();
	for(int i = left + 1; i < right; ++i){
		cost = min(cost, cut(v, left, i, dp) + cut(v, i, right, dp) + (v[right] - v[left]));
	}
	return (dp[left][right] = cost);
}

ll minCost(VL& v){
	VVL dp(v.size() + 1, VL(v.size() + 1, -1));
	return cut(v, 0, v.size() - 1, dp);
}


void testActual(){
	int l, n;
	while(true){
		cin >> l;
		if(l == 0) break;
		cin >> n;
		VL v;
		v.push_back(0);
		for(int i = 0; i < n; ++i){
			int t;
			cin >> t;
			v.push_back(t);
		}
		v.push_back(l);
		ll cost = minCost(v);
		cout << "The minimum cutting is " << cost << ".\n";
	}
}

void test(){
	VL v = {0, 25, 50, 75, 100};
	ll cost = minCost(v);
	cout << cost << endl;
	assert(cost == 200);
}

int main(){
	testActual();
}
