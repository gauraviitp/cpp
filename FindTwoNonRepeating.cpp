// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

/*	Time begin - 9:08 AM
	Time end -  AM
	Desc: Find two non-repeating elements in an array of repeating elements.
*/

#include "stdafx.h"
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> VI;

pair<int, int>& findTwoNonRepeating(const VI& v) {
	int xor = 0;
	// Get xor of all the elements
	for (int i = 0; i < v.size(); ++i) {
		xor ^= v[i];
	}
	// Get the lowest set bit in xor
	int bit = xor & (-xor);
	int xora = 0, xorb = 0;
	for (int i = 0; i < v.size(); ++i) {
		if (v[i] & bit) {
			xora ^= v[i];
		}
		else {
			xorb ^= v[i];
		}
	}
	pair<int, int> res = make_pair(xora, xorb);
	return res;
}

int main() {
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w+", stdout);
	int n; // Count of numbers
	cin >> n; 
	VI v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	pair<int, int> res = findTwoNonRepeating(v);
	cout << res.first << " " << res.second << "\n";
}
