// Find the length of the longest valid paranthesis

#include <algorithm>
#include <cassert>
#include <stack>
#include <string>

using namespace std;

int findLongestValidParanthesis(const string& str){
	stack<int> s;
	s.push(-1);
	const char lParan = '(';
	int maxLen = 0;
	for(int i = 0; i < (int)str.length(); ++i){
		if(str[i] == lParan){
			s.push(i);
		}
		else {
			s.pop(); // pop the matching paranthesis
			if(!s.empty()){
				maxLen = max(maxLen, i - s.top());
			}
			else {
				s.push(i); // push the current index even if it is ')' if stack is empty
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
