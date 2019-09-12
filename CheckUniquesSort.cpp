#include <algorithm>
#include <cassert>
#include <string>

using namespace std;

bool checkUniques(string s){
	if (s.size() == 0) return true;
	if (s.size() > 256) return false;
	sort(s.begin(), s.end());
	char prev = s[0];
	for (unsigned int i = 1; i < s.size(); ++i){
		if (s[i] == prev) return false;
		prev = s[i];
	}
	return true;
}

int main(){
	assert(checkUniques("Gaurav") == false); // duplicates, so false
	assert(checkUniques("Megha") == true); // no duplicates, so true
	assert(checkUniques("") == true); // no duplicates, so true
}
