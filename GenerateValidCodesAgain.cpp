// Generate all the possible decodings

#define DEBUG
#include <cassert>
#include <iostream>
#include <string>

using namespace std;

void generateDecodings(string &s, int pos, string &t, int &decodingsCount){
	// Base case
	if(pos >= (int)s.size()){
		#ifdef DEBUG
		cout << t << " ";
		#endif
		++decodingsCount;
		return;
	}
	
	// consider one char
	t.push_back('a' + s[pos] - '1');
	generateDecodings(s, pos + 1, t, decodingsCount);
	t.pop_back();
	
	// consider two chars
	if(pos + 1 < (int)s.size()){
		int val = stoi(s.substr(pos, 2));
		if(val >= 1 && val <= 26){
			t.push_back(val - 1 + 'a');
			generateDecodings(s, pos + 2, t, decodingsCount);
			t.pop_back();
		}
	}
}

int generateDecodings(string s){
	#ifdef DEBUG
	cout << s << ": ";
	#endif
	string t;
	int decodingsCount = 0;
	generateDecodings(s, 0, t, decodingsCount);
	#ifdef DEBUG
	cout << endl;
	#endif
	return decodingsCount;
}

int main(){
	assert(generateDecodings("121") == 3);
	assert(generateDecodings("1234") == 3);
}
