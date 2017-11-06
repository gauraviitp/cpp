// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

/*	Time begin - 4:40 PM
	Time end -  PM
	Desc: Compute modular exponentiation.
*/

#include "stdafx.h"
#include <iostream>

using namespace std;

int modularExp(int x, int y, int p) {
	int exp = 1;
	while (y > 0) {
		if (y & 1) {
			exp = (exp * x) % p;
		}
		x = (x * x) % p;
		y = y >> 1; 
	}
	return exp;
}

int main() {
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w+", stdout);
	int x, y, p;
	cin >> x >> y >> p;
	int res = modularExp(x, y, p);
	cout << res << "\n";
}
