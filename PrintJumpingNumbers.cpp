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
				q.push(cur * 10 + (cur % 10) - 1);
				q.push(cur * 10 + (cur % 10) + 1);
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
	int n; // Largest number
	cin >> n;
	printJumpingNumbers(n);
}
