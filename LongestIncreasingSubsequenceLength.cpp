#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;
typedef vector<int> VI;

int longestIncreasingSubsequenceLength(VI& v){
	VI table(v.size(), 1);
	for(int i = 0; i < (int) v.size(); ++i){
		for(int j = i - 1; j >= 0; --j){
			if(v[j] <= v[i]){
				table[i] = max(table[i], table[j] + 1);
			}
		}
	}
	return table[v.size() - 1];
}

int main(){
	VI v = {10, 22, 9, 33, 21, 50, 41, 60, 80};
	int res = longestIncreasingSubsequenceLength(v);
	assert(res == 6);
}
