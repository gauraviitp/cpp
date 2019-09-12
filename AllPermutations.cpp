#include <cassert>
#include <string>
#include <vector>

using namespace std;
typedef unsigned int uint;
typedef vector<string> VS;


void getAllPermutations(string& s, uint index, VS& res){
	if(index == s.length() - 1){
		res.push_back(s);
		return;
	}
	for(uint i = index; i < s.length(); ++i){
		swap(s[index], s[i]);
		getAllPermutations(s, index + 1, res);
		swap(s[index], s[i]);
	}
} 

void getAllPermutations(string& s, VS& res){
	getAllPermutations(s, 0, res);
}

void testGetAllPermutations();

int main(){
	testGetAllPermutations();
}

void testGetAllPermutations(){
	VS res;
	string inputString = "abc";
	getAllPermutations(inputString, res);
	assert(res[0] == "abc");
	assert(res[1] == "acb");
	assert(res[2] == "bac");
	assert(res[3] == "bca");
	assert(res[4] == "cba");
	assert(res[5] == "cab");
}
