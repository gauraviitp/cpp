// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> VI;

// Returns the index of the minimum element in the array
int findMinimum(VI& v) {
	int low = 0, high = v.size() - 1;
	while (low < high) {
		int mid = (low + high) / 2;
		// check if the min present in the left half
		if (v[mid] < v[high]) {
			high = mid;
		}
		else {
			low = mid + 1;
		}
	}
	return low;
}

int main() {
	// Read the array elements
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w+", stdout);
	int n;
	cin >> n;
	VI v;
	for (int i = 0; i < n; ++i) {
		int e;
		cin >> e;
		v.push_back(e);
	}
	int minIndex = findMinimum(v);
	cout << minIndex << "\n";
	return 0;
}
