// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

/*	Time begin - 1:24 PM
	Time end - 
*/

#include "stdafx.h"

#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> VI;
const int inf = INT_MAX;

int findMinCoins(const VI& v, int S) {
	if (S < 0) {
		return inf;
	}
	if (S == 0) {
		return 0;
	}
	int minc = inf;
	for (const int e : v) {
		if (e <= S) {
			minc = min(minc, findMinCoins(v, S - e) + 1);
		}
	}
	return minc;
}


int main() {
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w+", stdout);
	int n, s;
	cin >> n >> s;
	VI v;
	for (int i = 0; i < n; ++i) {
		int val;
		cin >> val;
		v.push_back(val);
	}
	int minCount = findMinCoins(v, s);
	cout << minCount << "\n";
}
