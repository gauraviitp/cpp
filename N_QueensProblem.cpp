// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

/*	Time begin - 10:17 AM
	Time end -  AM
	Desc:	n queens problem.
*/

#include "stdafx.h"

#include <cassert>
#include  <iostream>
#include <vector>

using namespace std;
typedef vector<int> VI;
typedef vector<vector<int>> VVI;

bool CheckSafe(int rowno, int colno, VVI& board, int n) {
	int dx[] = {-1, -1, -1};
	int dy[] = {0, -1, 1};
	for (int i = 0; i < 3; ++i) {
		int x = rowno, y = colno;
		while (x < n && x >= 0           // make sure that the position lies on the board
			&& y < n && y >= 0) {
			if (board[x][y] == 1) {
				return false;
			}
			x += dx[i];
			y += dy[i];
		}
	}
	return true;
}

void PrintBoard(VVI& board, int n) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

void SolveNqueens(int rowno, VVI& board, int n, int& count) {
	if (rowno == n) { // all the queens have been placed safely
		PrintBoard(board, n);
		count++;
		return;
	}
	for (int colno = 0; colno < n; ++colno) {
		if (CheckSafe(rowno, colno, board, n)) {
			board[rowno][colno] = 1;
			SolveNqueens(rowno + 1, board, n, count);
			board[rowno][colno] = 0;
		}
	}
}

void TestCheckSafe() {
	VVI board(8, VI(8, 0));
	bool isSafe = CheckSafe(4, 4, board, 8);
	assert(isSafe == true);
	
	board[0][0] = 1;
	isSafe = CheckSafe(4, 4, board, 8);
	assert(isSafe == false);
	board[0][0] = 0;

	board[1][7] = 1;
	isSafe = CheckSafe(4, 4, board, 8);
	assert(isSafe == false);
	board[1][7] = 0;

	board[1][6] = 1;
	isSafe = CheckSafe(4, 4, board, 8);
	assert(isSafe == true);
	board[1][6] = 0;
}

int main() {
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w+", stdout);
	int n; // board will be nxn
	cin >> n;
	VVI board(n, VI(n, 0));
	TestCheckSafe();
	int count = 0;
	SolveNqueens(0, board, n, count);
	cout << "Different arrangements possible are: " << count << "\n";
}
