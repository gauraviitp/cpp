// Stock buy sell to maximize profit
#include <cassert>
#include <vector>

using namespace std;
typedef vector<int> VI;
typedef unsigned int uint;

class Interval{
public:
	uint start;
	uint end;
	Interval(uint s, uint e = 0) : start(s), end(e){}
};

typedef vector<Interval *> VR;

VR buySellStock(const VI& v){
	uint pos = 0;
	VR res;
	int min = v[pos++];
	Interval *curInterval = new Interval(0);
	while(pos < v.size()){
		if(v[pos] < min){
			min = v[pos];
			if(pos - 1 > curInterval->start){
				curInterval->end = pos - 1;
				res.push_back(curInterval);
				curInterval = new Interval(pos);
			}
			else {
				curInterval->start = pos;
			}
		}
		++pos;
	}
	if(v[v.size() - 1] > min){
		curInterval->end = v.size() - 1;
		res.push_back(curInterval);
	}
	return res;
}

void testBuySellStock();

int main(){
	testBuySellStock();
}

void testBuySellStock(){
	VI v = {100, 180, 260, 310, 40, 535, 695};
	VR res = buySellStock(v);
	assert(res.size() == 2);
	assert(res[0]->start == 0);
	assert(res[0]->end == 3);
	assert(res[1]->start == 4);
	assert(res[1]->end == 6);
	
	VI v2 = {100, 80, 70, 60, 50, 40};
	VR res2 = buySellStock(v2);
	assert(res2.size() == 0);
	
	VI v3 = {100, 80, 70, 60, 50, 60};
	VR res3 = buySellStock(v3);
	assert(res3.size() == 1);
	assert(res3[0]->start == 4);
	assert(res3[0]->end == 5);
}
