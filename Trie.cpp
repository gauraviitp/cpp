#include "stdafx.h"
#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <string>

using namespace std;
const int min_weight = INT_MIN;
const int min_best = INT_MIN;

class TrieNode {
public:
	bool leaf = false;
	int weight = min_weight;
	int max_weight = min_weight;
	map<char, TrieNode *> mch;
};

typedef map<char, TrieNode *> MapCh;

class Trie {
private:
	TrieNode * root = new TrieNode();
	void searchAllSubTrees(TrieNode* cur_node, string word, string& best_word, int& best);
public:
	void addWord(string& word, int weight);
	void searchWord(string& word, string& best_word, int& best);
};

void Trie::addWord(string& word, int weight) {
	TrieNode * pcur_node = root;
	int cur_pos = 0;
	while (cur_pos < word.size()) {
		auto& mch = pcur_node->mch;
		if (mch.find(word[cur_pos]) != mch.end()) {
			pcur_node = mch[word[cur_pos]];
		}
		else {
			// Create a new char to trie node mapping
			mch[word[cur_pos]] = new TrieNode();
			// Advance to the new cur node
			pcur_node = mch[word[cur_pos]];
		}
		++cur_pos;
		pcur_node->max_weight = max(pcur_node->max_weight, weight);
	}
	pcur_node->leaf = true;
	pcur_node->weight = weight;
}

void Trie::searchWord(string& word, string& best_word, int& best) {
	best = min_best;
	best_word = "";
	// Try to reach a valid node using the word
	TrieNode * pcur_node = root;
	int cur_pos = 0;
	while (cur_pos < word.size()) {
		auto& mch = pcur_node->mch;
		if (mch.find(word[cur_pos]) != mch.end()) {
			pcur_node = mch[word[cur_pos]];
		}
		else {
			return;
		}
		++cur_pos;
	}
	//searchAllSubTrees(pcur_node, word, best_word, best);
	best = max(best, pcur_node->max_weight);
}

void Trie::searchAllSubTrees(TrieNode * cur_node, string word, string& best_word, int& best) {
	auto& mch = cur_node->mch;
	if (cur_node->leaf) {
		if (cur_node->weight > best) {
			best = cur_node->weight;
			best_word = word;
		}
	}
	for (MapCh::iterator it = mch.begin(); it != mch.end(); ++it) {
		searchAllSubTrees(it->second, word + it->first, best_word, best);
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w+", stdout);
	int n, q;
	cin >> n >> q;
	Trie trie;
	for (int entryno = 1; entryno <= n; ++entryno) {
		string s;
		int w;
		cin >> s >> w;
		trie.addWord(s, w);
	}
	for (int squeryno = 1; squeryno <= q; ++squeryno) {
		string s;
		cin >> s;
		string result;
		int best;
		trie.searchWord(s, result, best);
		if (best == min_best) {
			cout << -1 << "\n";
		}
		else {
			cout << best << "\n";
		}
	}
}
