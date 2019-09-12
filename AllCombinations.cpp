#include <cassert>
#include <string>
#include <vector>

using namespace std;

vector<string> getAllCombinations(int n){
	vector<string> res;
	for(int i = 0; i < 1 << n; ++i){
		string s;
		for(int j = 0; j < n; ++j){
			if(i & 1 << j){
				s += to_string(j+1);
			}
		}
		res.push_back(s);
	}
	return res;
}

void testGetAllCombinations();

int main(){
	testGetAllCombinations();
}

void testGetAllCombinations(){
	vector<string> res = getAllCombinations(3);
	assert(res[0] == "");
	assert(res[1] == "1");
	assert(res[2] == "2");
	assert(res[3] == "12");
	assert(res[4] == "3");
	assert(res[5] == "13");
	assert(res[6] == "23");
	assert(res[7] == "123");
}
