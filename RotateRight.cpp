#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;
typedef vector<int> VI;
typedef vector<VI> VVI;

void rotateRight(VVI& a){
	// get the transpose
	for(unsigned int i = 0; i < a.size(); ++i){
		for(unsigned int j = 0; j < i; ++j){
			swap(a[i][j], a[j][i]);
		}
	}
	// reverse the rows
	unsigned int sz = a.size();
	for(unsigned int i = 0; i < a.size(); ++i){
		for(unsigned int j = 0; j < sz / 2; ++j){
			swap(a[i][j], a[i][sz - 1 - j]);
		}
	}
}

int main(){
	VVI a = {{ 1, 	 2,  3,  4},
			 { 5, 	 6,  7,  8},
			 { 9, 	10, 11, 12},
			 {13, 	14, 15, 16}
			};
	VVI rotated = {{13,  9,  5, 1},
				   {14, 10,  6, 2},
				   {15, 11,  7, 3},
				   {16, 12,  8, 4}
				  };
	rotateRight(a);
	for(unsigned int i = 0; i < a.size(); ++i){
		for(unsigned int j = 0; j < a[i].size(); ++j){
			assert(a[i][j] == rotated[i][j]);
		}
	}
}
