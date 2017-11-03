// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

/*	Time begin - 10:15 AM
	Time end -  PM
	Desc: Print the spiral matrix of n x n.
*/

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> VI;
typedef vector<VI> VVI;

void printSpiral(int n) {
	VVI v(n, VI(n, 0));
	VI dx = {0, 1, 0, -1};
	VI dy = {1, 0, -1, 0};
	int xs = 0, xe = n - 1, ys = 0, ye = n - 1;
	int x, y, sqn = n;
	bool hasNext = true;
	while (hasNext) { // For all the loops
		hasNext = false;
		x = xs, y = ys - 1;
		int elementno = 0;
		for (int i = 0; i < 4; ++i) { // For all the directions of one loop
			while (true) {
				int tx = x + dx[i];
				int ty = y + dy[i];
				if (tx >= xs && tx <= xe && ty >= ys && ty <= ye) {
					if (i == 3 && tx == xs) break;
					x = tx;
					y = ty;
					v[x][y] = sqn * sqn - elementno;
					++elementno;
					hasNext = true;
				}
				else {
					break;
				}
			}
		}
		++xs, --xe, ++ys, --ye;
		sqn -= 2;
	}
	// Print matrix
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << v[i][j] << " ";
		}
		cout << "\n";
	}
}

int main() {
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w+", stdout);
	// Read the input
	int n;
	cin >> n;
	printSpiral(n);
	return 0;
}
