// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

typedef vector<string> VS;
typedef map<string, VS> MSVS;
typedef unordered_set<string> US;

bool compare(const string& a, const string& b) {
	if (a.length() != b.length()) return false;
	int diffs = 0;
	for (int i = 0; i < a.length(); ++i) {
		if (a[i] != b[i]) {
			diffs++;
			if (diffs > 1) {
				return false;
			}
		}
	}
	if (diffs == 1) return true;
	else return false;
}

int dfs(MSVS& g, string& node, string& target, int level, US& us) {
	if (node == target) return level;
	int minLevel = INT_MAX;
	us.insert(node);
	VS& v = g[node];
	for (auto& e : v) {
		if (us.find(e) == us.end()) {
			minLevel = min(minLevel, dfs(g, e, target, level + 1, us));
		}
	}
	us.erase(node);
	return minLevel;
}

int main() {
	// Read the input
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w+", stdout);
	string start;
	string target;
	cin >> start >> target;
	int n;
	cin >> n;
	string word;
	VS dict;
	while (getline(cin, word)) {
		if (word.empty()) continue;
		dict.push_back(word);
	}
	// push target when target not in dict
	//dict.push_back(target);

	// Create the graph
	MSVS g;
	for (auto& ea : dict) {
		VS v;
		for (auto& eb : dict) {
			if (compare(ea, eb)) {
				v.push_back(eb);
			}
		}
		g[ea] = v;
	}
	US us;
	int minTransforms = dfs(g, start, target, 1, us);
	cout << minTransforms << "\n";
	return 0;
}
