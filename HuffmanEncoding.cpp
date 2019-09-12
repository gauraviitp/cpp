// Huffman encoding

#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Node {
public:
	char c;
	unsigned freq;
	Node *left = nullptr, *right = nullptr;
	Node(int pfreq, Node * pleft, Node *pright) : 
		freq(pfreq), left(pleft), right(pright){}
	Node(char pc, int pfreq) : c(pc), freq(pfreq) {} 
};

class NodeCompare{
public:
	int operator() (Node * a, Node * b){
		if(a->freq > b->freq){
			return 1;
		}
		return 0;
	}
};

typedef priority_queue<Node *, vector<Node *>, NodeCompare> PQ;

Node * huffmanTree(vector<Node *> leaves){
	PQ pq;
	for(auto leaf : leaves){
		pq.push(leaf);
	}
	
	Node *topmost = nullptr;
	while(!pq.empty()){
		topmost = pq.top(); pq.pop();
		if(!pq.empty()){
			Node *secondNode = pq.top(); pq.pop();
			Node *internalNode = new Node(topmost->freq + secondNode->freq, topmost, secondNode);
			pq.push(internalNode);
		}
	}
	
	return topmost;
}

void finalCodes(Node *tree, vector<pair<char, string>> &codes, string& code){
	if(!tree){
		return;
	}
	if(tree->left == nullptr && tree->right == nullptr){
		codes.push_back(make_pair(tree->c, code));
	}
	if(tree->left){
		code = code + "0";
		finalCodes(tree->left, codes, code);
		code.pop_back();
	}
	if(tree->right){
		code = code + "1";
		finalCodes(tree->right, codes, code);
		code.pop_back();
	}
}

vector<pair<char, string>> encode(vector<Node *> leaves){
	Node *tree = huffmanTree(leaves);
	vector<pair<char, string>> codes;
	string code = "";
	finalCodes(tree, codes, code);
	return codes;
}

int main(){
	// Test case is same as from geeksfromgeeks
	vector<Node *> leaves = 
	{
		new Node('a', 5),
		new Node('b', 9),
		new Node('c', 12),
		new Node('d', 13),
		new Node('e', 16),
		new Node('f', 45)
	};
	vector<pair<char, string>> codes = encode(leaves);
	assert(codes[0].first == 'f' && codes[0].second == "0");
	assert(codes[1].first == 'c' && codes[1].second == "100");
	assert(codes[2].first == 'd' && codes[2].second == "101");
	assert(codes[3].first == 'a' && codes[3].second == "1100");
	assert(codes[4].first == 'b' && codes[4].second == "1101");
	assert(codes[5].first == 'e' && codes[5].second == "111");
	cout << "All test cases passed :)" << endl;
}
