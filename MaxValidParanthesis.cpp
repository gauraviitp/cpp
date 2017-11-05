// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

/*	Time begin - 9:08 AM
	Time end -  AM
	Desc: Find maximum valid paranthesis.
*/

#include "stdafx.h"
#include <algorithm>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int maxValidParanthesis(const string& str) {
	stack<int> s;
	int res = 0;
	int cur = 0;
	for (int i = 0; i < str.size(); ++i) {
		if (str[i] == ')') {
			if (!s.empty()) {
				int posa = s.top(); s.pop(); // posa not required
				cur += 2;
			}
			else {
				cur = 0;
			}
			res = max(res, cur);
		}
		else {
			s.push(i);
		}
	}
	return res;
}

int main() {
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w+", stdout);
	string s;
	cin >> s;
	int maxLen = maxValidParanthesis(s);
	cout << maxLen << "\n";
}
