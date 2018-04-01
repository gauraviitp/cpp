#include <iostream>
#include <string>
#include <vector>

using namespace std;
typedef vector<string> VS;

string joinWords(VS& words){
	string sentence;
	for(auto& word : words){
		sentence += word + ' '; // you can append string as well as characters
	}
	sentence.pop_back(); // delete the last character
	sentence.erase(13, 5); // erase "play " from the sentence
	return sentence;
}

int main(){
	VS words = {"Ryan", "goes", "to", "play", "school"};
	string sentence = joinWords(words);
	cout << sentence << endl;
}
