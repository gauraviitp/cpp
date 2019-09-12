// Starting indices of all the substrings made by
// concatenating all the words from a list.
// Doesn't handle the scenario where duplicates matches might be there.

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> findIndices(string &s, vector<string> &v){
	unordered_set<string> set;
	vector<int> indices;
	for(string &str : v){
		if(set.find(str) == set.end()){
			set.insert(str);
		}
	}
	int k = 0;
	if(!v.empty()){
		k = v[0].size();
	}
	for(int i = 0; i < (int)s.size(); ++i){
		int substringCount = 0;
		for(int j = i, counter = 0; counter < (int)set.size() && (j + k - 1) < (int)s.size(); j += k, ++counter){
			string substr = s.substr(j, k);
			if(set.find(substr) != set.end()){
				++substringCount;
			}
			else {
				break;
			}
		}
		if(substringCount == (int)set.size()){
			indices.push_back(i);
		}
	}
	return indices;
} 

int main(){
	string s = "abcdababcd";
	vector<string> v = {"ab", "ab", "cd"};
	vector<int> indices = findIndices(s, v);
	for(auto index : indices){
		cout << index << endl;
	}
}
