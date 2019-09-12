// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

/*	Time begin - 3:47 PM
	Time end -  PM
*/

#include "stdafx.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;
typedef vector<int> VI;

void buildTable(VI& t, const string& p) {
	t = VI(p.size());
	int k = -2; // set candidate as -1
	for (int i = 0; i < p.size(); ++i) {
		while (k >= -1 && p[i] != p[k + 1]) { // k + 1 is the candidate index, i is the pos
			k = (k == -1) ? -2 : t[k]; // since pos not equal to candiate, set candidate equal to -1 or t[candidate - 1]
		}
		t[i] = ++k;
	}
}

int main() {
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w+", stdout);
	string p, s;
	cin >> p >> s;
	VI t;
	buildTable(t, p);
	int k = -1; // set candidate as zero
	for (int i = 0; i < s.size(); ++i) {
		while (k >= -1 && p[k + 1] != s[i]) {
			k = (k == -1) ? -2 : t[k];
		}
		k++;
		if (k == p.size() - 1) { // if candidate is equal to p.size()
			cout << "Matched at index " << i - k << " : ";
			cout << s.substr(i - k, p.size()) << endl;
			k = (k == -1) ? -2 : t[k];
		}
	}
	return 0;
}
