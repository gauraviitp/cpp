// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

/*	Time begin - 3:47 PM
	Time end -  PM
*/

#include "stdafx.h"

#include <iostream>
#include <string>
#include <map>

using namespace std;
typedef map<int, char> MIC;


void generateValidCodes(const string& s, int pos, MIC& m, string& res) {
	if (pos >= s.size()) {
		cout << res << " ";
		return;
	}
	res.push_back(m[s[pos] - '0']);
	generateValidCodes(s, pos + 1, m, res);
	res.pop_back();
	if (pos + 1 < s.size() && m.find(atoi(s.substr(pos, 2).c_str())) != m.end()) {
		res.push_back(m[atoi(s.substr(pos, 2).c_str())]);
		generateValidCodes(s, pos + 2, m, res);
		res.pop_back();
	}
}

int main() {
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w+", stdout);
	string s;
	cin >> s;
	MIC m;
	for (int i = 1; i <= 26; ++i) {
		m[i] = 'a' + i - 1;
	}
	string t;
	generateValidCodes(s, 0, m, t);
	return 0;
}
