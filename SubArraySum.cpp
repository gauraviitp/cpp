// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

/*	Time begin - 5:50 PM
	Time end -  PM
	Desc: Find subarray with given sum.
*/

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> VI;

void subArraySum(VI& v, int& si, int& ei, int sum) {
	int low = 0, high = 0;
	int curSum = 0;
	while (low < v.size() && high < v.size()) {
		// Add the element to current sum
		curSum += v[high];

		// Remove the element from the current sum till current sum becomes lesser than or equal to the given sum
		while (curSum > sum && low < high) {
			curSum -= v[low++];
		}

		if (curSum == sum) {
			si = low, ei = high;
			return;
		}

		high++;
	}
}

int main() {
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w+", stdout);
	int n; // Length of the subarray
	int s; // Given sum
	cin >> n >> s;
	VI v(n, -1);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	int si = -1, ei = -1;
	subArraySum(v, si, ei, s);
	cout << si << " " << ei << "\n";
}
