// Print a given matrix in a spiral form

#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> VI;
typedef vector<VI> VVI;

void printSpiral(VVI& m){
	int size = (int)m.size();
	for(int layer = 0; layer < size; ++layer){
		int first = layer;
		int last = size - 1 - layer;
		for(int i = first; i <= last; ++i){
			cout << m[first][i] << " ";
		}
		for(int i = first + 1; i <= last; ++i){
			cout << m[i][last] << " ";
		}
		for(int i = last - 1; i >= first; --i){
			cout << m[last][i] << " ";
		}
		for(int i = last - 1; i > first; --i){
			cout << m[i][first] << " ";
		}
	}
	cout << endl;
}

int main(){
	VVI a = 
	{
		{1,	2,  3,  4},
		{5,	6,  7,  8},
		{9, 10, 11, 12},
		{13,14, 15, 16}
	};
	printSpiral(a);
}
