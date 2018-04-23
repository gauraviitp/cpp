#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using  namespace std;
typedef vector<int> VI;

int numberOfOperations(VI& v){
	// handle base cases here
	
	int count = 0;
	while(true){
		int i = 0;
		// if increasing order
		while(i + 1 < (int)v.size() && v[i] < v[i + 1]) {
			++i;
		}
		if(i != 0){ // found a violation after increasing order
			if(i == (int)v.size()){
				break; // break the while true loop
			}
			// check whether to reverse prefix beforehand or not
			int j = 0;
			// below loop to be replaced by binary search
			while(j < i && v[i + 1] > v[j]) ++j; // breaks when v[j] greater than v[i + 1]
			if(j > (i - j)){ // closer to the bigger number in right half
				reverse(v.begin(), v.begin() + i + 2); // reverse v[0, i + 1]
				++count;
			}
			else {
				reverse(v.begin(), v.begin() + i + 1);
				reverse(v.begin(), v.begin() + i + 2);
				count += 2;
			}
		}
		else { // decreasing order
			while(i + 1 < (int)v.size() && v[i] > v[i + 1]) {
				++i;
			}
			if(i == (int)v.size()){
				++count;
				break;
			}
			// check whether to reverse prefix beforehand or not
			int j = 0;
			// below loop to be replaced by binary search
			while(j < i && v[i + 1] < v[j]) ++j; // breaks when v[j] lesser than v[i + 1]
			if(j > (i - j)){ // closer to the smaller number in right half
				reverse(v.begin(), v.begin() + i + 2); // reverse v[0, i + 1]
				++count;
			}
			else {
				reverse(v.begin(), v.begin() + i + 1);
				reverse(v.begin(), v.begin() + i + 2);
				count += 2;
			}
		}
	}
	return count;
}

int main(){
	VI v = {4, 5, 2, 7, 8, 1, 3, 6};
	int res = numberOfOperations(v);
	cout << res << endl;
	assert(res == 0);
}
