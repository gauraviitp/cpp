// Wild card matching
// '.' Matches any single character.
// '*' Matches zero or more of any character.

#include <cassert>
#include <string>
#include <vector>

using namespace std;
typedef vector<int> VI;
typedef vector<VI> VVI;

bool isMatch(string &s, string &p, int lens, int lenp, VVI &dp){
	bool match = false;
	if(lens == (int)s.size() &&
	   lenp == (int)p.size()){
		return (dp[lens][lenp] = true);
	}
	else if(lens > (int)s.size() ||
	   lenp > (int)p.size()){
		return false;
	}
	else if(dp[lens][lenp] != -1){
		return dp[lens][lenp];
	}
	// case 1
	else if(lens < (int)s.size() && (s[lens] == p[lenp] || p[lenp] == '.')){
		match = isMatch(s, p, lens + 1, lenp + 1, dp);
	}
	
	// case 2
	else if (lenp < (int)p.size() && p[lenp] == '*'){
		// consume a letter in s and dont consume '*' in p
		match = isMatch(s, p, lens + 1, lenp, dp); 
		// don't consume a letter in s and consume '*' in p
		match = match || isMatch(s, p, lens, lenp + 1, dp);   
	}
	return (dp[lens][lenp] = match);
}

bool isMatch(string s, string p){
	int lens = 0, 
		lenp = 0;
	VVI dp(s.size() + 1, VI(p.size() + 1, -1));
	return isMatch(s, p, lens, lenp, dp);
}

int main(){
	assert(isMatch("g", ".*"));
}
