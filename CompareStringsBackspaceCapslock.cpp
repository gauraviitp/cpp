// Compare two strings if they are the same
// Use O(1) extra space only
// Runs in O(n) time. Does single scan on the string to search.

#include <cassert>
#include <cctype>
#include <string>

using namespace std;

bool areSame(string &toSearch, string &pattern){
	int pos = toSearch.size() - 1, 
		deletedCount = 0, 
		tpos = pattern.size() - 1;
	bool same = true;
	while(pos >= 0){
		if(toSearch[pos] == 'b' &&
		   pos - 1 >= 0 && 
		   toSearch[pos - 1] == '\\'){
			++deletedCount;
			pos -= 2;
		}
		else if(toSearch[pos] == 'c' &&
		   pos - 1 >= 0 && 
		   toSearch[pos - 1] == '\\'){
			pos -= 2;
		}
		else {
			if(deletedCount > 0){
				--deletedCount;
			}
			else {
				char toCompare;
				if(toSearch[pos - 1] == 'c' &&
				   pos - 2 >= 0 && 
		           toSearch[pos - 2] == '\\'){
					toCompare = toupper(toSearch[pos]);
				   }
				else {
					toCompare = toSearch[pos];
				}
				if(toCompare != pattern[tpos--]){
					same = false;
					break;
				}
			}
			--pos;
		}
	}
	return same;
}

int main(){
	string  s = "", p = "";
	assert(areSame(s, p));
	
	string  s1 = "a", p1 = "a";
	assert(areSame(s1, p1));
	
	string  s2 = "b", p2 = "b";
	assert(areSame(s2, p2));
	
	string  s3 = "\\b", p3 = "";
	assert(areSame(s3, p3));
	
	string  s4 = "a\\c\\ba\\b", p4 = "a";
	assert(areSame(s4, p4));
	
	string  s5 = "a\\cb\\bb\\ccde\\b\\bde\\cf", p5 = "abCdeF";
	assert(areSame(s5, p5));
}
