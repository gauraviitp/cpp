// priority queue

#include <cassert>
#include <queue>

using namespace std;

class Compare
{
public:
    bool operator() (int const a, int const b)
    {
        return a > b;
    }
};

// you can use greater<int> as well instead of Compare

typedef priority_queue<int, vector<int>, Compare> PQI;

int main(){
	PQI pq;
	pq.push(20);
	pq.push(10);
	pq.push(5);
	pq.push(25);
	assert(pq.size() == 4);
	int top1 = pq.top(); pq.pop();
	assert(top1 == 5);
	int top2 = pq.top(); pq.pop();
	assert(top2 == 10);
	int top3 = pq.top(); pq.pop();
	assert(top3 == 20);
	int top4 = pq.top(); pq.pop();
	assert(top4 == 25);
}
