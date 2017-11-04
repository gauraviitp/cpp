// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

/*	Time begin - 6:37 PM
	Time end -  PM
	Desc: Find maximum j - i such that arr[j] > arr[i].
*/

#include "stdafx.h"
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> VI;
const int inf = INT_MAX;
const int ninf = INT_MIN;

int MaxJminusI(VI& v) {
	VI rMax(v.size());
	VI lMin(v.size());
	int curMax = ninf;
	// Fill the vector with running max from right
	for (int i = v.size() - 1; i >= 0; --i) {
		curMax = max(curMax, v[i]);
		rMax[i] = curMax;
	}
	int curMin = inf;
	// Fill the vector with running min from left
	for (int i = 0; i < v.size(); ++i) {
		curMin = min(curMin, v[i]);
		lMin[i] = curMin;
	}
	int lIndex = 0, rIndex = 0, maxDiff = ninf;
	// Compare the leftMin and rightMax vectors and get the max difference
	while (lIndex < v.size() && rIndex < v.size()) {
		if (lMin[lIndex] < rMax[rIndex]) {
			if(rIndex > lIndex) maxDiff = max(maxDiff, rIndex - lIndex);
			rIndex++;
		}
		if (rIndex < v.size() && lMin[lIndex] >= rMax[rIndex]) {
			lIndex++;
		}
	}
	return maxDiff;
}

int main() {
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w+", stdout);
	int n; // Length of the array
	cin >> n;
	VI v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	int maxDiff = MaxJminusI(v);
	cout << maxDiff << "\n";
}
