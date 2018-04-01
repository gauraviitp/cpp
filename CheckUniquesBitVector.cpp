#include <cassert>
#include <string>
#include <vector>

using namespace std;
typedef vector<bool> VB;

bool checkUniques(string s){
	if (s.size() == 0) return true;
	if (s.size() > 256) return false;
	VB mask(255, false);
	for (unsigned int i = 1; i < s.size(); ++i){
		int val = s[i];
		if (mask[val]) return false;
		mask[val] = true;
	}
	return true;
}

int main(){
	assert(checkUniques("Gaurav") == false); // duplicates, so false
	assert(checkUniques("Megha") == true); // no duplicates, so true
	assert(checkUniques("") == true); // no duplicates, so true
}
