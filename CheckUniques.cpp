#include <cassert>
#include <string>
#include <unordered_set>

using namespace std;

bool checkUniques(string s){
	unordered_set<char> us;
	for (auto& c : s){
		if(us.find(c) != us.end()){
			return false;
		}
		us.insert(c);
	}
	return true;
}

int main(){
	assert(checkUniques("Gaurav") == false); // duplicates, so false
	assert(checkUniques("Megha") == true); // no duplicates, so true
	assert(checkUniques("") == true); // no duplicates, so true
}
