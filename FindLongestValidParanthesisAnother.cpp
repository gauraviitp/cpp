// Find the length of the longest valid paranthesis

#include <algorithm>
#include <cassert>
#include <stack>
#include <string>

using namespace std;

// curMax holds the maxlength of the current valid paranthesis string
// maxLen holds the max of all curMax
// curMax is reset whenever no matching leftParan is found for the current rightParan.

int findLongestValidParanthesis(const string& str){
	stack<char> s;
	const char lParan = '(';
	int maxLen = 0, curMax = 0;
	for(int i = 0; i < (int)str.length(); ++i){
		if(str[i] == lParan){
			s.push(str[i]);
		}
		else {
			if(!s.empty()){
				s.pop();
				curMax += 2;
				maxLen = max(maxLen, curMax);
			}
			else {
				curMax = 0; // reset current maximum
			}
		}
	}
	return maxLen;
}

void test();

int main(){
	test();
}

void test(){
	string str = "";
	assert(findLongestValidParanthesis(str) == 0);
	
	string str1 = ")(()";
	assert(findLongestValidParanthesis(str1) == 2);
	
	string str2 = ")()())";
	assert(findLongestValidParanthesis(str2) == 4);
	
	string str3 = "()(()))))";
	assert(findLongestValidParanthesis(str3) == 6);
}
