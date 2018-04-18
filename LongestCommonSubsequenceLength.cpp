// Longest common subsequence
// 00:53

#include <algorithm>
#include <cassert>
#include <string>
#include <vector>

using namespace std;
typedef vector<int> VI;
typedef vector<VI> VVI;

int lowestCommonSubsequence(const string& a, const string& b){
	int sza = (int)a.length();
	int szb = (int)b.length();
	VVI table(sza + 1, VI(szb + 1, 0));
	for(int i = 0; i <= sza; ++i){
		for(int j = 0; j <= szb; ++j){
			if(i == 0 || j == 0){
				table[i][j] = 0;
			}
			else if(a[i - 1] == b[j - 1]){
				table[i][j] = table[i - 1][j - 1] + 1;
			}
			else {
				table[i][j] = max(table[i][j - 1], table[i - 1][j]);
			}
		}
	}
	return table[sza][szb];
}

int main(){
	string a = "Gaurav";
	string b = "arv";
	assert(lowestCommonSubsequence(a, b) == 3);
	
	string a1 = "";
	string b1 = "arv";
	assert(lowestCommonSubsequence(a1, b1) == 0);
	
	string a2 = "Gaurav";
	string b2 = "";
	assert(lowestCommonSubsequence(a2, b2) == 0);
	
	string a3 = "Gaurav";
	string b3 = "Gaurav";
	assert(lowestCommonSubsequence(a3, b3) == 6);
	
	string a4 = "Gaurav";
	string b4 = "aurav";
	assert(lowestCommonSubsequence(a4, b4) == 5);
	
	string a5 = "Gaura";
	string b5 = "Gaurav";
	assert(lowestCommonSubsequence(a5, b5) == 5);
}

