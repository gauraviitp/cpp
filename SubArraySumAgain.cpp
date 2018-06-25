// Subarray with given sum

#include <cassert>
#include <vector>

using namespace std;

bool findSubarray(vector<int> &v, int sum){
	if(v.empty()) return false;
	
	int tail = 0, head = 0;
	int curSum = 0;
	
	while(head < (int)v.size() && tail < (int)v.size()){
		// Add element to current sum
		curSum += v[head];
		
		while(curSum > sum && tail < head){
			curSum -= v[tail++];
		}
		
		if(curSum == sum) return true;
		++head;
	}
	return false;
}

int main(){
	vector<int> v = {1, 2, 5};
	assert(!findSubarray(v, 0));
	assert(findSubarray(v, 7));
	assert(findSubarray(v, 1));
	assert(findSubarray(v, 2));
	assert(findSubarray(v, 5));
	assert(findSubarray(v, 8));
	assert(!findSubarray(v, 6));
}
