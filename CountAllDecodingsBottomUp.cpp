// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

/*	Time begin - 12:47 PM
	Time end -  PM
	Desc: Count all decodings bottom up.
*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int CountAllDecodings(string str) {
	vector<int> dp(str.size() + 1, -1);
	dp[0] = 1; dp[1] = 1;
	for (int lens = 2; lens <= str.size(); ++lens) {
		int decodings = dp[lens - 1];
		int val = atoi(str.substr(lens - 2, 2).c_str());
		if (val >= 1 && val <= 26) {
			decodings += dp[lens - 2];
		}
		dp[lens] = decodings;
	}
	return dp[str.size()];
}

int main() {
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w+", stdout);
	string str;
	cin >> str;
	int totalDecodings = CountAllDecodings(str);
	cout << totalDecodings << "\n";
}
