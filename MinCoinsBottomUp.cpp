// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

/*	Time begin - 1:50 PM
	Time end - 2:03 PM
*/

#include "stdafx.h"

#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> VI;
const int inf = INT_MAX;

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
	VI dp(s + 1, inf);
	dp[0] = 0;
	for (int sum = 0; sum <= s; ++sum) {
		for (const auto& e : v) {
			if (sum >= e) {
				if (dp[sum - e] != inf) {
					dp[sum] = min(dp[sum], dp[sum - e] + 1);
				}
			}
		}
	}
	cout << dp[s] << "\n";
}
