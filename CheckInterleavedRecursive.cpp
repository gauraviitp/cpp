// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

/*	Time begin - 5:31 AM
	Time end -  AM
	Desc: Check whether a string is interleaving of two other strings.
*/

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

bool checkInterleaved(string& a, string& b, string& c, int posa, int posb, int posc) {
	// Base cases
	if (posa == a.size() && posb == b.size() && posc == c.size()) {
		return true; // If all strings are empty
	}
	if (posc == c.size())
	{
		return false; // If c is empty but a and b are not
	}
	bool res = false;
	if (posa < a.size()) {
		res = a[posa] == c[posc] && checkInterleaved(a, b, c, posa + 1, posb, posc + 1);
	}
	if (posb < b.size()) {
		res = res || b[posb] == c[posc] && checkInterleaved(a, b, c, posa, posb + 1, posc + 1);
	}
	return res;
}

int main() {
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w+", stdout);
	string a, b, c;
	cin >> a >> b >> c;
	bool result = checkInterleaved(a, b, c, 0, 0, 0);
	cout << result << "\n";
}
