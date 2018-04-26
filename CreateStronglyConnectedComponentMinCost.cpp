#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;
typedef long long LL;
typedef vector<LL> VL;
typedef vector<bool> VB;

LL findPathMaxLength(VL& s, VL& w, int startNode, int node, VB& seen, VL& lv){
	if(seen[node]){
		return lv[node];
	}
	seen[node] = true;
	if(!seen[s[node]]){
		lv[node] = w[node] + findPathMaxLength(s, w, startNode, s[node], seen, lv);
	}
	else if(s[node] == startNode){
		bool allNotSeen = false;
		for(int i = 0; i < (int)seen.size(); ++i){
			if(!seen[i]){
				allNotSeen = true;
				break;
			}
		}
		if(!allNotSeen){
			lv[node] += w[node]; 
		}
	}
	return lv[node];
}

LL makeSccMinCost(VL& s, VL& w){
	// adjust s
	for(int i = 0; i < (int)s.size(); ++i){
		--s[i];
	}
	// sum all weights
	LL sw = 0;
	for(int i = 0; i < (int)w.size(); ++i){
		sw += w[i];
	}
	LL maxPath = -1;
	for(int i = 0; i < (int)s.size(); ++i){
		VB seen(s.size(), false);
		VL lv(s.size(), 0);
		LL tmax = findPathMaxLength(s, w, i, i, seen, lv);
		maxPath = max(maxPath, tmax);
	}
	return sw - maxPath;
}

void test(){
	VL s = {2, 1, 1, 1};
	VL w = {3, 1, 1, 3};
	int res = makeSccMinCost(s, w);
	cout << res << endl;
	assert(res == 2);
}

void test2(){
	VL s = {2, 5, 4, 6, 4, 4};
	VL w = {10, 12, 18, 15, 20, 30};
	int res = makeSccMinCost(s, w);
	cout << res << endl;
	assert(res == 48);
}

void test3(){
	VL s = {2, 1, 2, 2};
	VL w = {10, 100, 15, 20};
	int res = makeSccMinCost(s, w);
	cout << res << endl;
	assert(res == 25);
}

void test4(){
	VL s = {2, 3, 1, 2};
	VL w = {10000, 1500, 1600, 20};
	int res = makeSccMinCost(s, w);
	cout << res << endl;
	assert(res == 1520);
}

void test5(){
	VL s = {2, 1};
	VL w = {10, 20};
	int res = makeSccMinCost(s, w);
	cout << res << endl;
	assert(res == 0);
}

void test6(){
	VL s = {1, 2};
	VL w = {10, 20};
	int res = makeSccMinCost(s, w);
	cout << res << endl;
	assert(res == 30);
}

void test7(){
	VL s = {2, 3, 4, 2};
	VL w = {10000, 50, 100, 20000};
	int res = makeSccMinCost(s, w);
	cout << res << endl;
	assert(res == 10050);
}

void test8(){
	VL s = {2, 3, 4, 1};
	VL w = {10000, 50, 100, 20000};
	int res = makeSccMinCost(s, w);
	cout << res << endl;
	assert(res == 0);
}

void test9(){
	VL s = {1};
	VL w = {10000};
	int res = makeSccMinCost(s, w);
	cout << res << endl;
	assert(res == 0);
}

void run(){
	int n;
	cin >> n;
	VL s(n);
	VL w(n);
	for(int i = 0; i < n; ++i){
		cin >> s[i];
	}
	for(int i = 0; i < n; ++i){
		cin >> w[i];
	}
	LL res = makeSccMinCost(s, w);
	cout << res << endl;
}

int main(){
	test();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();
	test8();
	test9();
	//run();
}
