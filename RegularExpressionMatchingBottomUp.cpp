// Regular expression matching
// '.' Matches any single character.
// '*' Matches zero or more of the preceding element .

#include <cassert>
#include <string>
#include <vector>

using namespace std;
typedef vector<int> VI;
typedef vector<VI> VVI;

    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1, false));
        // base case
        dp[0][0] = true;
        for(int i = 1; i < p.size(); ++i){
            if(p[i] == '*' && dp[0][i-1]){
                dp[0][i+1] = true;
            }
        }
        
        for(int i = 0; i < s.size(); ++i){
            for(int j = 0; j < p.size(); ++j){
                if(p[j] == s[i]){
                    dp[i+1][j+1] = dp[i][j];
                }
                else if(p[j] == '.'){
                    dp[i+1][j+1] = dp[i][j];
                }
                else if(p[j] == '*'){
                    if(p[j-1] != s[i] && p[j-1] != '.'){
                        dp[i+1][j+1] = dp[i+1][j-1]; // consume only in p
                    }
                    else {
                        dp[i+1][j+1] = dp[i][j+1] || // consume only in s
									   dp[i+1][j-1]; // consume only in p
                    }
                }
            }
        }
        /*for(int i = 0; i < dp.size(); ++i){
            for(int j = 0; j < dp[i].size(); ++j){
                cout << dp[i][j] << " ";
            }
            cout << '\n';
        }*/
        return dp[s.size()][p.size()];
    }

int main(){
	assert(isMatch("s", "ss"));
	assert(isMatch("s", "g*s"));
	assert(isMatch("gaurav", "g*v") == false);
	assert(isMatch("gauravchoudhary", "g*") == false);
	assert(isMatch("s", "g*s"));
	assert(isMatch("gggav", "g*a*v*"));
	assert(isMatch("", "g*"));
}
