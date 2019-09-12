// Copy set bits

#include <cassert>

using namespace std;


// Copies the set bits from y to x
void copySetBits(int& x, int y, int l, int r){
	const int sz = sizeof(x) * 8;
	for (int i = l - 1; i >= 0 && i < sz && i < r; ++i){
		if(y & 1<<i){
			x |= (1 << i);
		}
	}
}

int main(){
	int x = 10;
	int y = 13;
	copySetBits(x, y, 2, 3);
	assert(x == 14);
}
