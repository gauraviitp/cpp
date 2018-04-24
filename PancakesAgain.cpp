#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using  namespace std;
typedef vector<int> VI;

void minNumberOfOperations(VI& v, int flips, int ops, int& minOps){
	if(flips == 0){
		return;
	}
	int i;
	for(i = 1; i < v.size(); ++i){
		if(v[i - 1] > v[i]){
			break;
		}
	}
	if(i == v.size()){
		if(ops < minOps){
			minOps = ops;
			return;
		}
	}
	for(int i = 1; i <= v.size(); ++i){
	    if(ops + 1 < minOps){
		    // flip v
		    reverse(v.begin(), v.begin() + i);
		    minNumberOfOperations(v, flips - 1, ops + 1, minOps);
		    // flip back
		    reverse(v.begin(), v.begin() + i);
	    }
	}
}

int getUpperBound(VI v){
	int index = v.size() - 1;
	int count = 0;
	while(index > 0){
		if(index + 1 != v[index]){
			// find i containing the element equal to index
			int i;
			for(i = 0; i <= index; ++i){
				if(v[i] == index + 1) {
					break;
				}
			}
			if(i == 0){
				reverse(v.begin(), v.begin() + index + 1);
				++count;
			}
			else {
				reverse(v.begin(), v.begin() + i + 1);
				reverse(v.begin(), v.begin() + index + 1);
				count += 2;
			}
		}
		--index;
	}
	return count;
}

int numberOfOperations(VI& v){
	int upperBound = getUpperBound(v);
	int res = upperBound;
	minNumberOfOperations(v, upperBound, 0, res);
	return res;
}

int main(){
	
	/*int n;
    cin >> n;
	VI v(n);
	for(int i = 0; i < n; ++i){
	    cin >> v[i];
	}
	int res = numberOfOperations(v);
	cout << res << endl;*/
	
	VI v = {3, 1, 2};
	int res = numberOfOperations(v);
	assert(res == 2);
	
	VI v9 = {5, 2, 3, 4, 1};
	int res9 = numberOfOperations(v9);
	//cout << res9 << endl;
	assert(res9 == 4);
	
	VI v3 = {2, 1};
	int res3 = numberOfOperations(v3);
	//cout << res3 << endl;
	assert(res3 == 1);
	
	VI v1 = {1, 2};
	int res1 = numberOfOperations(v1);
	assert(res1 == 0);
	
	VI v2 = {2};
	int res2 = numberOfOperations(v2);
	assert(res2 == 0);
	
	VI v4 = {3, 2, 1, 4};
	int res4 = numberOfOperations(v4);
	assert(res4 == 1);
	
	VI v5 = {2, 3, 1, 4};
	int res5 = numberOfOperations(v5);
	assert(res5 == 2);
	
	VI v6 = {2, 3, 4, 1};
	int res6 = numberOfOperations(v6);
	assert(res6 == 2);
	
	VI v7 = {2, 1, 3, 4};
	int res7 = numberOfOperations(v7);
	assert(res7 == 1);
	
	VI v8 = {5, 3, 1, 4, 2};
	int res8 = numberOfOperations(v8);
	assert(res8 == 5);
}
