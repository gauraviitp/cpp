// Regular expression matching
// '.' Matches any single character.
// '*' Matches zero or more of the preceding element .

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
	else if(lens < (int)s.size() && 
			(s[lens] == p[lenp] || p[lenp] == '.') &&
			(lenp + 1 >= (int)p.size() || (lenp + 1 < (int)p.size() && p[lenp + 1] != '*'))){
		match = isMatch(s, p, lens + 1, lenp + 1, dp);
	}
	
	// case 2
	else if (lenp + 1 < (int)p.size() && 
	         p[lenp + 1] == '*'){
		if(lens < (int)s.size() && 
		   (p[lenp] == s[lens] || p[lenp] == '.')){
			// consume a letter in s and dont consume '*' in p
			match = isMatch(s, p, lens + 1, lenp, dp); 
			// don't consume a letter in s and consume '*' in p
			match = match || isMatch(s, p, lens, lenp + 2, dp);
		}
		else {
			match = isMatch(s, p, lens, lenp + 2, dp); // dont consume in s as not a match
		}
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
	assert(isMatch("s", "g*s"));
	assert(isMatch("gaurav", "g*v") == false);
	assert(isMatch("gauravchoudhary", "g*") == false);
	assert(isMatch("s", "g*s"));
	assert(isMatch("gggav", "g*a*v*"));
	assert(isMatch("", "g*"));
}
