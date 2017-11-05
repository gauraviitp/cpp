// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

/*	Time begin - 5:31 AM
	Time end -  AM
	Desc: Check whether a string is interleaving of two other strings with bottom up approach.
*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;
typedef vector<int> VI;
typedef vector<VI> VVI;

bool checkInterleaved(string& a, string& b, string& c) {
	VVI dp(a.size() + 1, VI(b.size() + 1, 0));
	if (a.size() + b.size() != c.size()) return false;
	
	for (int lena = 0; lena <= a.size(); ++lena) { // lena - 1 th char in a
		for (int lenb = 0; lenb <= b.size(); ++lenb) { // lenb - 1 th char in b
			if (lena == 0 && lenb == 0) { // lenc = lena + lenb = 0
				dp[lena][lenb] = 1;
			}
			else if (lena == 0 && b[lenb - 1] == c[lenb - 1]) { // a is empty and c matches with b
				dp[lena][lenb] = dp[lena][lenb - 1];
			}
			else if (lenb == 0 && a[lena - 1] == c[lena - 1]) { // b is empty and c matches with a
				dp[lena][lenb] = dp[lena - 1][lenb];
			}
			else {
				dp[lena][lenb] = lena > 0 && a[lena - 1] == c[lena + lenb - 1] && dp[lena - 1][lenb]
					|| lenb > 0 && b[lenb - 1] == c[lena + lenb - 1] && dp[lena][lenb - 1];
			}
		}
	}
	return dp[a.size()][b.size()];
}

int main() {
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w+", stdout);
	string a, b, c;
	cin >> a >> b >> c;
	bool result = checkInterleaved(a, b, c);
	cout << result << "\n";
}
