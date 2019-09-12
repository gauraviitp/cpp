// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

/*	Time begin - 5:31 AM
	Time end -  AM
	Desc: Check whether a string is interleaving of two other strings with memoization.
*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;
typedef vector<int> VI;
typedef vector<VI> VVI;

bool checkInterleaved(string& a, string& b, string& c, int posa, int posb, int posc, VVI& dp) {
	// Base cases
	if (posa == a.size() && posb == b.size() && posc == c.size()) {
		return true; // If all strings are empty
	}
	if (posc == c.size())
	{
		return false; // If c is empty but a and b are not
	}
	if (dp[posa][posb] != -1) return dp[posa][posb];
	bool res = false;
	if (posa < a.size()) {
		res = a[posa] == c[posc] && checkInterleaved(a, b, c, posa + 1, posb, posc + 1, dp);
	}
	if (posb < b.size()) {
		res = res || b[posb] == c[posc] && checkInterleaved(a, b, c, posa, posb + 1, posc + 1, dp);
	}
	dp[posa][posb] = res;
	return res;
}

int main() {
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w+", stdout);
	string a, b, c;
	cin >> a >> b >> c;
	VVI dp(a.size() + 1, VI(b.size() + 1, -1));
	bool result = checkInterleaved(a, b, c, 0, 0, 0, dp);
	cout << result << "\n";
}
