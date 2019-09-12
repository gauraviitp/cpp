// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> VI;

// Returns the index of the element in the array if found
// Else returns -1
int findElement(VI& v, int k) {
	int low = 0, high = v.size() - 1;
	while (low < high) {
		int mid = (low + high) / 2;
		if (v[mid] == k) return mid;
		// check if the min present in the left half
		if (v[mid] < v[high]) { // right half is sorted
			if (k > v[mid] && k <= v[high]) { // check if element present in the sorted half
				low = mid + 1;
			}
			else {
				high = mid - 1;
			}
		}
		else { // left half is sorted
			if (k < v[mid] && k >= v[low]) { // check if element present in the sorted half
				high = mid - 1;
			}
			else {
				low = mid + 1;
			}
		}
	}
	return v[low] == k ? low : -1;
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
	int k; // element to be searched
	cin >> k;
	int foundIndex = findElement(v, k);
	cout << foundIndex << "\n";
	return 0;
}
