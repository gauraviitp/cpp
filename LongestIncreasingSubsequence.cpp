#include <cassert>
#include <vector>

using namespace std;
typedef vector<int> VI;

int longestIncreasingSubsequence(VI& v, VI& prevTable){
	VI lenTable(v.size(), 1);
	for(int i = 0; i < (int) v.size(); ++i){
		for(int j = i - 1; j >= 0; --j){
			if(v[j] <= v[i]){
				if(lenTable[j] + 1 >= lenTable[i]){
					lenTable[i] = lenTable[j] + 1;
					prevTable[i] = j;
				}
			}
		}
	}
	return lenTable[v.size() - 1];
}

int main(){
	VI v = {10, 22, 9, 33, 21, 50, 41, 60, 80};
	VI prevTable = VI(v.size(), -1);
	int res = longestIncreasingSubsequence(v, prevTable);
	assert(res == 6);
	assert(prevTable[0] == -1);
	assert(prevTable[1] == 0);
	assert(prevTable[3] == 1);
	assert(prevTable[5] == 3);
	assert(prevTable[7] == 5);
	assert(prevTable[8] == 7);
}
