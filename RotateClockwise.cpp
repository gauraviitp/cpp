// Rotate a matrix clockwise

#include <cassert>
#include <vector>

using namespace std;
typedef vector<vector<int>> VVI;

void rotateClockwise(VVI& m){
	int sz = (int)m.size();
	for(int layer = 0; layer < sz/2; ++layer){
		int first = layer, last = sz - 1 - layer;
		// rotate the top row
		int cur = m[first][first];
		for(int i = first; i < last; ++i){
			int t = m[first][i + 1];
			m[first][i + 1] = cur;
			cur = t;
		}
		// rotate the right column
		for(int i = first; i < last; ++i){
			int t = m[i + 1][last];
			m[i + 1][last] = cur;
			cur = t;
		}
		// rotate the bottom row
		for(int i = last; i > first; --i){
			int t = m[last][i - 1];
			m[last][i - 1] = cur;
			cur = t;
		}
		// rotate the left column
		for(int i = last; i > first; --i){
			int t = m[i - 1][first];
			m[i - 1][first] = cur;
			cur = t;
		}
	}
} 

int main(){
	VVI a = 
	{
		{1,	2,  3,  4},
		{5,	6,  7,  8},
		{9, 10, 11, 12},
		{13,14, 15, 16}
	};
	VVI rotated = 
	{
		{5,	1, 	2, 	3},
		{9,	10, 6,	4},
		{13,11, 7, 	8},
		{14,15, 16, 12}
	};
	rotateClockwise(a);
	for(int i = 0; i < (int)a.size(); ++i){
		for(int j = 0; j < (int)a[i].size(); ++j){
			assert(a[i][j] == rotated[i][j]);
		}
	}
}
