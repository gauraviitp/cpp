// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

/*	Time begin - 10:17 AM
	Time end -  AM
	Desc:	Generate the power set.
*/

#include "stdafx.h"
#include <iostream>

using namespace std;

void PrintAllCombinations(int n) {
	for (int i = 0; i < (1 << n); ++i) {
		for (int j = 0; j < n; ++j) {
			if (i & (1<<j)) {
				cout << j << " ";
			}
		}
		cout << "\n";
	}
}

int main() {
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w+", stdout);
	int n;
	cin >> n;
	PrintAllCombinations(n);
}
