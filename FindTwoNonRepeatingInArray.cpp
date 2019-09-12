// Find two non-repeating elements in array of repeating elements

#include <cassert>
#include <vector>

using namespace std;
typedef vector<int> VI;

// Steps
// xorall <= xor of all the elements
// i <= rightmost set bit in xorall
// a <= xor all elements having i bit set
// b <= xor all elements not having i bit set

void findTwoNonRepeating(const VI& v, int& a, int& b){
	int xorall = 0;
	a = 0;
	b = 0;
	for(const auto& e : v){
		xorall ^= e;
	}
	int i = xorall & ~(xorall - 1);
	for(const auto& e : v){
		if(e & i){
			a ^= e;
		}
		else {
			b ^= e;
		}
	}
}

void testFindTwoNonRepeating();

int main(){
	testFindTwoNonRepeating();
}

void testFindTwoNonRepeating(){
	VI v = {2, 3, 7, 9, 11, 2, 3, 11};
	int a, b;
	findTwoNonRepeating(v, a, b);
	assert((a == 7 && b == 9) || (a == 9 && b == 7));
}
