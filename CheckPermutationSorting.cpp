#include <algorithm>
#include <cassert>
#include <string>

using namespace std;

/*
 * Checks if two strings are permutations without using
 * any data structure or extra space.
 */
bool checkPermutation(string& a, string& b){
	if(a.length() != b.length()) return false;
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	return (a.compare(b) == 0);
}

int main(){
	string a = "Gaurav", b = "Garuav";
	assert(checkPermutation(a, b));
	
	a = "Gaurav", b = "Gauuav"; 
	assert(checkPermutation(a, b) == false);
}
