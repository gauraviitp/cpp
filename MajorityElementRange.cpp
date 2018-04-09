#include <cassert>
#include <vector>

using namespace std;

bool binarySearch(vector<int>& v, int searchKey, int& index){
	int low = 0, high = v.size() - 1;
	while(low < high){
		int mid = (low + high) / 2;
		if(v[mid] == searchKey){
			index = mid;
			return true;
		}
		else if(v[mid] < searchKey){
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	index = low;
	return v[index] == searchKey;
}

void majorityElementRange(vector<int>& v, int& start, int& end){
	int me = v[v.size()/2];
	int index;
	bool res = binarySearch(v, me - 1, index);
	if(res) start = index + 1;
	else start = index;
	res = binarySearch(v, me + 1, index);
	if(res) end = index - 1;
	else end = index;
}

void testMajorityElementRange();

int main(){
	testMajorityElementRange();
}

void testMajorityElementRange(){
	vector<int> v = {1, 2, 3, 4, 4, 4, 4, 5};
	int start, end;
	majorityElementRange(v, start, end);
	assert(start == 3);
	assert(end == 6);
	
	vector<int> v2 = {4, 4, 4, 4, 4, 4};
	int start2, end2;
	majorityElementRange(v2, start2, end2);
	assert(start2 == 0);
	assert(end2 == 5);
}
