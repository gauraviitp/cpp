// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

/*	Time begin - 12:47 PM
	Time end -  PM
	Desc: Count all decodings recursive.
*/

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int countDecodingsRecur(string& str, int pos) {
	if (pos == str.size()) {
		return 1;
	}
	int totalCount = 0;
	// First case: Check with one char
	totalCount += countDecodingsRecur(str, pos + 1);

	// Second case: Check with two chars
	if (pos + 1 < str.size()) {
		int val = atoi(str.substr(pos, 2).c_str());
		if (val >= 1 && val <= 26) {
			totalCount += countDecodingsRecur(str, pos + 2);
		}
	}
	return totalCount;
}

int countAllDecodings(string& str) {
	return countDecodingsRecur(str, 0);
}

int main() {
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w+", stdout);
	string str;
	cin >> str;
	int totalCount = countAllDecodings(str);
	cout << totalCount << "\n";
}
