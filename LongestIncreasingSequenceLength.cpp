#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;
typedef vector<int> VI;
typedef vector<VI> VVI;

int longestIncreasingSequenceLength(string& a, string& b){
	VVI table = VVI(a.size(), VI(b.size(), 0));
	for(int i = 0; i < (int)a.size(); ++i){
		for(int j = 0; j < (int)b.size(); ++j){
			if(a[i] == b[j]){
				if(i == 0 || j == 0){
					table[i][j]++;
				}
				else {
					table[i][j] = table[i - 1][j - 1] + 1;
				}
			}
			else {
				if(i >= 1){
					table[i][j] = max(table[i - 1][j], table[i][j]);
				}
				if(j >= 1){
					table[i][j] = max(table[i][j - 1], table[i][j]);
				}
			}
		}
	}
	return table[a.size() - 1][b.size() - 1];
}


int main(){
	string a = "Gaurav", b = "arv";
	assert(longestIncreasingSequenceLength(a, b) == 3);
	a = "Gaurav", b = "Garav";
	assert(longestIncreasingSequenceLength(a, b) == 5);
	a = "Gaurav", b = "Gaurav";
	assert(longestIncreasingSequenceLength(a, b) == 6);
}
