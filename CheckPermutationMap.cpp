#include <cassert>
#include <map>
using namespace std;

/*
 * Checks if two strings are permutations without using
 * any data structure or extra space.
 */
bool checkPermutation(string& a, string& b){
	map<char, int> m;
	for(auto& c : a){
		m[c]++;
	}
	for(auto& c : b){
		m[c]--;
	}
	for(map<char, int>::iterator it = m.begin(); it != m.end(); ++it){
		if(it->second != 0) return false;
	}
	return true;
}

int main(){
	string a = "Gaurav", b = "Garuav";
	assert(checkPermutation(a, b));
	
	a = "Gaurav", b = "Gauuav"; 
	assert(checkPermutation(a, b) == false);
	
	a = "Gaurav", b = "Gaurav Choudhary";
	assert(checkPermutation(a, b) == false);
}
