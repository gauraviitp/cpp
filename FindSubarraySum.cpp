// Find subarray with given sum.

#include <cassert>
#include <vector>

using namespace std;
typedef vector<int> VI;

bool findSubarraySum(const VI& v, const int sum, int& start, int& end){
	start = 0;
	int curSum = v[start];
	end = 1;
	while(end < (int)v.size()){
		if(curSum == sum) {
			end -= 1; // adjust end
			return true;
		}
		curSum += v[end];
		while(curSum > sum && start < (int)v.size()) { // remember to put the other check 
			curSum -= v[start++]; // remove the value from start and inc it
		}
		++end;
	}
	start = -1;
	end = -1;
	return false;
}

void testFindSubarraySum();

int main(){
	testFindSubarraySum();
}

void testFindSubarraySum(){
	// Case 1
	VI v = {1, 4, 20, 3, 10, 5};
	int sum = 33;
	int start = -1, end = -1;
	assert(findSubarraySum(v, sum, start, end));
	assert(start == 2 && end == 4);
	
	VI v1 = {1, 4, 0, 0, 3, 10, 5};
	int sum1 = 7;
	int start1 = -1, end1 = -1;
	assert(findSubarraySum(v1, sum1, start1, end1));
	assert(start1 == 1 && end1 == 4);
	
	VI v2 = {1, 4};
	int sum2 = 0;
	int start2 = -1, end2 = -1;
	assert(!findSubarraySum(v2, sum2, start2, end2));
}
