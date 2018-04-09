#include <algorithm>
#include <cassert>
#include <string>
#include <sstream>

using namespace std;

string reverseWords(const string& sentence){
	string rsentence;
	stringstream ss(sentence);
	string word;
	while(ss >> word){
		reverse(word.begin(), word.end());
		rsentence += word + " ";
	}
	rsentence.pop_back();
	return rsentence;
}

void testReverseWords();

int main(){
	testReverseWords();
}

void testReverseWords(){
	string sentence = "Bob is a good boy";
	string expected = "boB si a doog yob";
	assert(reverseWords(sentence) == expected);
}
