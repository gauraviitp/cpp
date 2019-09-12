#include <algorithm>
#include <cassert>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

typedef vector<int> VI;

template <typename Comparator>
int lis(const VI& v, VI& prevTable, int& maxIndex, Comparator comparator){
	VI lenTable(v.size(), 1);
	maxIndex = -1;
	int maxLen = numeric_limits<int>::min();
	for(int i = 0; i < (int)v.size(); ++i){
		for(int j = i - 1; j >= 0; --j){
			if(comparator(v[j], v[i])){
				if(lenTable[i] < lenTable[j] + 1){
					lenTable[i] = lenTable[j] + 1;
					prevTable[i] = j;
					if(lenTable[i] > maxLen){
						maxLen = lenTable[i];
						maxIndex = i;
					}
				}
			}
		}
	}
	return maxLen;
}

int lis(const VI& v, VI& seq){
	VI prevTable(v.size(), -1);
	int maxIndex = -1;
	int maxLen = lis(v, prevTable, maxIndex, std::less_equal<int>());
	for(int i = maxIndex; i >= 0; i = prevTable[i]){
		seq.push_back(v[i]);
	}
	reverse(seq.begin(), seq.end());
	return maxLen;
}

int main(){
	VI v = {10, 22, 9, 33, 21, 50, 41, 60, 80};
	VI seq;
	int res = lis(v, seq);
	assert(res == 6);
	assert(seq[0] == 10);
	assert(seq[1] == 22);
	assert(seq[2] == 33);
	assert(seq[3] == 41);
	assert(seq[4] == 60);
	assert(seq[5] == 80);
}
