// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

/*	Time begin - 1:47 PM
	Time end - 1:50 PM
*/

#include "stdafx.h"

#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <vector>

using namespace std;
typedef vector<int> VI;
typedef map<int, int> MII;
const int inf = INT_MAX;

int findMinCoins(const VI& v, int S, MII& m) {
	if (m.find(S) != m.end()) {
		return m[S];
	}
	if (S < 0) {
		m[S] = inf;
		return inf;
	}
	if (S == 0) {
		m[S] = 0;
		return 0;
	}
	int minc = inf;
	for (const int e : v) {
		if (e <= S) {
			minc = min(minc, findMinCoins(v, S - e, m) + 1);
		}
	}
	m[S] = minc;
	return minc;
}


int main() {
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w+", stdout);
	int n, s;
	cin >> n >> s;
	VI v;
	MII m; // map for memoization
	for (int i = 0; i < n; ++i) {
		int val;
		cin >> val;
		v.push_back(val);
	}
	int minCount = findMinCoins(v, s, m);
	cout << minCount << "\n";
}
