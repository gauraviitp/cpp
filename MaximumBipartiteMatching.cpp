// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> VI;
typedef vector<VI> VVI;

bool FindMatch(int applicantno, const VVI& g, VI& maj, VI& mja, VI& seen) {
	for (int jobno = 1; jobno < g[applicantno].size(); ++jobno) {
		if (g[applicantno][jobno] != -1 && seen[jobno] == 0) {
			seen[jobno] = 1; // mark this jobno as seen so that in next call, it wont get reassigned to same applicant
			if (mja[jobno] == -1 || FindMatch(mja[jobno], g, maj, mja, seen)) {
				mja[jobno] = applicantno;
				maj[applicantno] = jobno;
				return true;
			}
		}
	}
	return false;
}

// g is graph
// maj is matching applicant to job
// mja is matching job to applicant
int bipartiteMatching(const VVI& g, VI& maj, VI& mja) {
	maj = VI(g.size() + 1, -1);
	mja = VI(g[0].size() + 1, -1);
	int mcount = 0; // matching count
	for (int ano = 1; ano < g.size(); ++ano) { // ano is applicant number
		VI seen(g[0].size(), 0);
		if (FindMatch(ano, g, maj, mja, seen)) ++mcount;
	}
	return mcount;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w+", stdout);
	// read the bipartite graph
	int n, m;
	cin >> n >> m;
	VVI g(n + 1, VI(n + 1, -1));
	for (int i = 0; i < m; ++i) {
		int startnode, endnode;
		cin >> startnode >> endnode;
		g[startnode][endnode] = 1;
	}
	VI maj, mja;
	int mcount = bipartiteMatching(g, maj, mja);
	cout << mcount << "\n";
	return 0;
}
