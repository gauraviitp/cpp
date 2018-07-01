// Uva 11450

#include <cassert>
#include <iostream>
#include <vector>
#include <limits>

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;

// minimize moneyAvailable
// maximize M - moneyAvailable

int minRemaining(int moneyAvailable, int garmentNo, VVI& garments, VVI& dp) {
	
	if (moneyAvailable < 0) {
		return numeric_limits<int>::max();
	}
	
	if(garmentNo == (int)garments.size()){
		return moneyAvailable;
	}
	
	if(dp[moneyAvailable][garmentNo] != -1){
		return dp[moneyAvailable][garmentNo];
	}
	
	int minPossibleMoney = numeric_limits<int>::max();
	
	for(auto priceOfModel : garments[garmentNo]){
		int tMin = minRemaining(moneyAvailable - priceOfModel, garmentNo + 1, garments, dp);
		if(tMin < minPossibleMoney){
			minPossibleMoney = tMin;
		}
	}
	
	return (dp[moneyAvailable][garmentNo] = minPossibleMoney);
}

int minRemaining(int moneyAvailable, int garmentNo, VVI& garments){
	VVI dp(201, VI(21, -1));
	return minRemaining(moneyAvailable, garmentNo, garments, dp);
}

void actual(){
	int testcases;
	cin >> testcases;
	for(int i = 0; i < testcases; ++i){
		int m, c;
		cin >> m >> c;
		VVI garments;
		for(int j = 0; j < c; ++j){
			int k;
			cin >> k;
			VI models(k);
			for(int jj = 0; jj < k; ++jj){
				cin >> models[jj];
			}
			garments.push_back(models);
		}
		int minMoney = minRemaining(m, 0, garments);
		if(minMoney == numeric_limits<int>::max()){
			cout << "no solution\n";
		}
		else {
			cout << m - minMoney << "\n";
		}
	}
}

void testOne(){
	int m = 100;
	VVI garments = 
	{
		{8, 6, 4},
		{5, 10},
		{1, 3, 3, 7},
		{50, 14, 23, 8}
	};
	int minMoney = minRemaining(m, 0, garments);
	assert(m - minMoney == 75);
}


void testTwo(){
	int m = 20;
	VVI garments = 
	{
		{4, 6, 8},
		{5, 10},
		{1, 3, 5, 5}
	};
	int minMoney = minRemaining(m, 0, garments);
	assert(m - minMoney == 19);
}

void testThree(){
	int m = 5;
	VVI garments = 
	{
		{6, 4, 8},
		{10, 6},
		{7, 3, 1, 7}
	};
	int minMoney = minRemaining(m, 0, garments);
	assert(minMoney == numeric_limits<int>::max());
}

int main(){
	actual();
}
