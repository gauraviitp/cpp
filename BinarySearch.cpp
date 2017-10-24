// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> VI;

// Returns index of the element if found 
// Else returns -1.
int binarySearch(VI v, int k) {
	int low = 0, high = v.size() - 1;
	while (low < high) {
		int mid = (low + high) / 2;
		if (v[mid] == k) {
			return mid;
		}
		else if (v[mid] < k) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	return -1;
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
	sort(v.begin(), v.end());
	int k; // element to be searched
	cin >> k;
	int foundIndex = binarySearch(v, k);
	cout << foundIndex << "\n";
	return 0;
}
