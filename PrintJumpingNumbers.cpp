// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

/*	Time begin - 10:51 AM
	Time end -  AM
	Desc: Print jumping numbers.
*/

#include "stdafx.h"
#include <iostream>
#include <queue>

using namespace std;

void bfs(int n, int i) {
	queue<int> q({i});
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		if (cur <= n) {
			cout << cur << " ";
			if (cur % 10 == 0) {
				q.push(cur * 10 + 1);
			}
			if (cur % 10 == 9) {
				q.push(cur * 10 + 8);
			}
			else {
				q.push(cur * 10 + cur - 1);
				q.push(cur * 10 + cur + 1);
			}
		}
	}
}

void printJumpingNumbers(int n) {
	for (int i = 1; i <= n && i <= 9; ++i) {
		bfs(n, i);
		cout << "\n";
	}
}

int main() {
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w+", stdout);
	int n; // Largest number
	cin >> n;
	printJumpingNumbers(n);
}
