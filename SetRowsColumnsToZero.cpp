#include <cassert>
#include <vector>

using namespace std;
typedef unsigned int uint;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<bool> VB;

void setZeros(VVI& m){
	VB rows = VB(m.size(), false);
	VB cols = VB(m[0].size(), false);
	for(uint i = 0; i < m.size(); ++i){
		for(uint j = 0; j < m[0].size(); ++j){
			if(m[i][j] == 0){
				rows[i] = true;
				cols[j] = true;
			}
		}
	}
	
	for(uint i = 0; i < m.size(); ++i){
		for(uint j = 0; j < m[0].size(); ++j){
			if(rows[i] || cols[j]){
				m[i][j] = 0;
			}
		}
	}
}

int main(){
	VVI m = 
	{
		{ 1,  2,  3,  4},
		{ 5,  6,  0,  8},
		{ 0, 10, 11, 12},
		{13, 14, 15, 16}
	};
	VVI res =
	{
		{ 0,  2,  0,  4},
		{ 0,  0,  0,  0},
		{ 0,  0,  0,  0},
		{ 0, 14,  0, 16}
	};
	
	setZeros(m);
	
	for(uint i = 0 ; i < m.size(); ++i){
		for(uint j = 0; j < m[0].size(); ++j){
			assert(m[i][j] == res[i][j]);
		}
	}
}
