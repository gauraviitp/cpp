#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
typedef vector<ll> VI;
typedef vector<VI> VVI;

ll solve(VVI& boxes, VVI& toys, int boxno, int toyno, VVI& dp){
	// base condition
	if(boxno >= boxes.size() || toyno >= toys.size()){
		return 0;
	}
	
	if(dp[boxno][toyno] != -1){
		return dp[boxno][toyno];
	}
	
	// check if match
	int type = boxes[boxno][1];
	if(type == toys[toyno][1]){
		// find the total matches
		ll maxMatch = 0;
		ll totaltoys = 0;
		ll totalboxes = 0;
		for(int i = boxno; i < boxes.size(); ++i){
			if(boxes[i][1] == type){
				totalboxes += boxes[i][0];
			}
			for(int j = toyno; j < toys.size(); ++j){
				if(toys[j][1] == type){
					totaltoys += toys[j][0];
				}
				ll minMatch = min(totalboxes, totaltoys);
				maxMatch = max(maxMatch, minMatch + solve(boxes, toys, i + 1, j + 1, dp));
			}
		}
		return (dp[boxno][toyno] = maxMatch);
	}
	// else if no match
	else {
		ll maxMatch;
		// try skipping boxes
		maxMatch = solve(boxes, toys, boxno + 1, toyno, dp);
		
		// try skipping toys
		maxMatch = max(maxMatch, solve(boxes, toys, boxno, toyno + 1, dp));
		return (dp[boxno][toyno] = maxMatch);
	}
}

void testActual(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w+", stdout);
	int t;
	cin >> t;
	for(int testno = 1; testno <= t; ++testno){
		int n, m;
		cin >> n >> m;
		VVI boxes(n, VI(2, 0));
		VVI toys(m, VI(2, 0));
		VVI dp(n, VI(m, -1));
		for(int i = 0; i < n; ++i){
			cin >> boxes[i][0]; // number
			cin >> boxes[i][1]; // type
		}
		for(int i = 0; i < m; ++i){
			cin >> toys[i][0];
			cin >> toys[i][1];
		}
		cout << "Case #" << testno << ": " << solve(boxes, toys, 0, 0, dp) << endl;
	}
}

int main(){
	testActual();
}
