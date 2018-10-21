#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
typedef vector<ll> VI;
typedef vector<VI> VVI;

ll solve(VVI& boxes, VVI& toys, int boxno, int toyno){
	// base condition
	if(boxno >= boxes.size() || toyno >= toys.size()){
		return 0;
	}
	
	// check if match
	if(boxes[boxno][1] == toys[toyno][1]){
		ll matchno = min(boxes[boxno][0], toys[toyno][0]);
		int newboxno = boxno, newtoyno = toyno;
		if((boxes[boxno][0] -= matchno) == 0) newboxno += 1;
		if((toys[toyno][0] -= matchno) == 0) newtoyno += 1;
		ll resno = matchno + solve(boxes, toys, newboxno, newtoyno);
		
		// revert the state of array to original one for backtracking
		boxes[boxno][0] += matchno;
		toys[toyno][0] += matchno;
		return resno;
	}
	// else if no match
	else {
		ll maxMatch;
		// try skipping boxes
		maxMatch = solve(boxes, toys, boxno + 1, toyno);
		
		// try skipping toys
		maxMatch = max(maxMatch, solve(boxes, toys, boxno, toyno + 1));
		return maxMatch;
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
		for(int i = 0; i < n; ++i){
			cin >> boxes[i][0]; // number
			cin >> boxes[i][1]; // type
		}
		for(int i = 0; i < m; ++i){
			cin >> toys[i][0];
			cin >> toys[i][1];
		}
		cout << "Case #" << testno << ": " << solve(boxes, toys, 0, 0) << endl;
	}
}

int main(){
	testActual();
}
