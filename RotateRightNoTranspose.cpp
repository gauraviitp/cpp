#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;
typedef unsigned int uint;
typedef vector<int> VI;
typedef vector<VI> VVI;

void rotateRight(VVI& a){
	uint sz = a.size();
	for(uint layer = 0; layer < sz/2; ++layer){
		uint first = layer, last = sz - 1 - layer;
		for(uint i = first; i < last; ++i){
			// last - offset is the index calculated from back
			int offset = (i - first);
			// save the first element
			int temp = a[first][i];
			// replace top row with left column
			a[first][i] = a[last - offset][first];
			// replace left column with bottom row
			a[last - offset][first] = a[last][last - offset];
			// replace bottom row with right column
			a[last][last - offset] = a[i][last];
			// replace right column with top row
			a[i][last] = temp;
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
	for(uint i = 0; i < a.size(); ++i){
		for(uint j = 0; j < a[i].size(); ++j){
			assert(a[i][j] == rotated[i][j]);
		}
	}
}
