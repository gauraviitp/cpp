// Subarray with given sum

#include <cassert>
#include <vector>

using namespace std;

bool findSubarray(vector<int> &v, int sum){
	if(v.empty()) return false;
	int tail = 0;
	int head = 1;
	int cur_sum = v[tail];
	if(cur_sum == sum) return true;
	while(head < (int)v.size() && tail < (int)v.size()){
		cur_sum += v[head];
		while(cur_sum > sum && tail < head){
			cur_sum -= v[tail++];
		}
		if(cur_sum == sum) return true;
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
