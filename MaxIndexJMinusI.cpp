// Maximum index 
// j - i such that a[i] <= a[j]

#include <algorithm>
#include <cassert>
#include <climits>
#include <vector>

using namespace std;
typedef vector<int> VI;


int findMaxIndex(VI& v){
	// Create the table of running minimum from the left
	VI lMin(v.size());
	for(int i = 0, cMin = v[i]; i < (int)v.size(); ++i){
		if(v[i] < cMin){
			cMin = v[i]; 
		}
		lMin[i] = cMin;
	}
	
	// Create the table of the running maximum from the right
	VI rMax(v.size());
	for(int i = v.size() - 1, cMax = v[i]; i >= 0; --i){
		if(v[i] > cMax){
			cMax = v[i];
		}
		rMax[i] = cMax;
	}
	
	// Find the max difference between corresponding elements of lMin and rMax
	int lIndex = 0, rIndex = 0, maxDiff = 0;
	while(lIndex < (int)v.size() && rIndex < (int)v.size()){
		if(lMin[lIndex] <= rMax[rIndex]){
			if(rIndex > lIndex) {
				maxDiff = max(maxDiff, rIndex - lIndex);
			}
			++rIndex;
		}
		if(rIndex < (int)v.size() && lMin[lIndex] > rMax[rIndex]){
			++lIndex;
		}
	}
	return maxDiff;
}

void testFindMaxIndex();

int main(){
	testFindMaxIndex();
}

void testFindMaxIndex(){
	VI v = {3, 5, 4, 2};
	assert(findMaxIndex(v) == 2);
	VI v1 = {6, 5, 4, 2, 3, 6, 7, 2, 1, 5};
	assert(findMaxIndex(v1) == 8);
}
