// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

/*	Time begin - 10:15 AM
	Time end -  PM
	Desc: Print the matrix in spiral order.
*/

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> VI;
typedef vector<VI> VVI;

void printSpiral(VVI& v) {
	VI dx = {0, 1, 0, -1};
	VI dy = {1, 0, -1, 0};
	int xs = 0, xe = v.size() - 1, ys = 0, ye = v[0].size() - 1;
	int x, y;
	bool hasNext = true;
	while (hasNext) { // Runs for all the loops
		hasNext = false;
		x = xs;
		y = ys - 1; // since starting with y, will print by incrementing it
		for (int i = 0; i < 4; ++i) {
			while (true) {
				int tx = x + dx[i];
				int ty = y + dy[i];
				if (tx <= xe && tx >= xs && ty <= ye && ty >= ys) {
					if (i == 3 && tx == xs) break; // special case
					x = tx;
					y = ty;
					cout << v[x][y] << " ";
					hasNext = true;
				}
				else break;
			}
		}
		++xs, ++ys, --ye, --xe;
	}
}

int main() {
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w+", stdout);
	// Read the matrix
	int n, m; // n x m matrix
	cin >> n >> m;
	VVI v(n, VI(m, 0));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> v[i][j];
		}
	}
	// Print the matrix in spiral order
	printSpiral(v);
	return 0;
}

/*
6 6
1 2 3 4 5 6
7 8 9 10 11 12
13 14 15 16 17 18
19 20 21 22 23 24
25 26 27 28 29 30
31 32 33 34 35 36
*/
