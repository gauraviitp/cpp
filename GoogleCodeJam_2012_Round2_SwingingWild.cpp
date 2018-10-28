/*
 * Codejam 2012
 * Round 2
 * Problem A (Swinging wilds)
*/

#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
typedef vector<ll> VI;
typedef vector<vector<ll>> VVI;

bool solve(VVI& v, int d){
	VI rad(v.size(), 0);
	rad[0] = v[0][0];
	for(int i = 1; i < v.size(); ++i){
		for(int j = 0; j < i; ++j){
			ll dist = v[i][0] - v[j][0];
			if(rad[j] >= dist && rad[j] > rad[i]){
				rad[i] = max(rad[i], min(v[i][1], min(rad[j], dist)));
			}
		}
	}
	for(int i = 0; i < v.size(); ++i){
		if(v[i][0] + rad[i] >= d){
			return true;
		}
	}
	return false;
}

void testSample(){
	VVI v = {
		{3, 4}, 
		{4, 10},
		{6, 10}
	};
	int d = 9;
	bool res = solve(v, 9);
	cout << res << endl;
}

void testActual(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w+", stdout);
	int t;
	cin >> t;
	for(int testno = 1; testno <= t; ++testno){
		int n;
		cin >> n;
		VVI v(n, VI(2, -1));
		for(int i = 0; i < n; ++i){
			cin >> v[i][0];
			cin >> v[i][1];
		}
		int d;
		cin >> d;
		bool res = solve(v, d);
		cout << "Case #" << testno << ": " << (res ? "YES" : "NO") << "\n"; 
	}
}

int main(){
	testActual();
}
