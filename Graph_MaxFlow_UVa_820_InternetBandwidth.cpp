// UVa 820 Internet Bandwidth

#include <algorithm>
#include <cassert>
#include <iostream>
#include <limits>
#include <queue>
#include <unordered_set>

using namespace std;

typedef long long ll;
typedef vector<ll> VI;
typedef vector<VI> VVI;

ll getAugmentedFlow(VVI& capMatrix, VVI& flowMatrix, int source, int sink, VI& parent){
	queue<int> q({source});
	unordered_set<int> visited({source});
	while(!q.empty()){
		int cur = q.front(); q.pop();
		if(cur == sink) break;
		for(int next = 1; next < (int)capMatrix.size(); ++next){
			if(capMatrix[cur][next] - flowMatrix[cur][next] > 0 && visited.find(next) == visited.end()){
				q.push(next);
				visited.insert(next);
				parent[next] = cur; 
			}
		}
	}
	ll flow = numeric_limits<ll>::max();
	int cur = sink;
	while(true){
		int par = parent[cur];
		if(par == -1) break;
		flow = min(flow, capMatrix[par][cur] - flowMatrix[par][cur]);
		cur = par;
	}
	return flow == numeric_limits<ll>::max() ? 0 : flow;
}

ll maxFlow(VVI& capMatrix, int source, int sink){
	ll flow = 0;
	VVI flowMatrix(capMatrix.size(), VI(capMatrix.size(), 0));
	while(true){
		VI parent(capMatrix.size(), -1);
		ll augFlow = getAugmentedFlow(capMatrix, flowMatrix, source, sink, parent);
		if(augFlow == 0) break;
		flow += augFlow;
		int cur = sink;
		while(true){
			int par = parent[cur];
			if(par == -1) break;
			flowMatrix[par][cur] += augFlow;
			flowMatrix[cur][par] -= augFlow;
			cur = par;
		}
	}
	return flow;
}

void test(){
	VVI capMatrix = 
	{
		{0,   200,  100,   0},
		{200,   0,  100, 100},
		{100, 100,    0, 200},
		{0,   100,  200,   0}
	};
	ll flow = maxFlow(capMatrix, 0, 3);
	cout << flow << endl;
	assert(flow == 300);
}

void testActual(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w+", stdout);
	int testcaseno = 1;
	while(true){
		int n;
		cin >> n;
		if(n == 0) break;
		int s, t, c;
		cin >> s >> t >> c;
		VVI capMatrix(n + 1, VI(n + 1, 0));
		for(int i = 0; i < c; ++i){
			int src, dest, cap;
			cin >> src >> dest >> cap;
			capMatrix[src][dest] += cap;
			capMatrix[dest][src] += cap;
		}
		ll flow = maxFlow(capMatrix, s, t);
		cout << "Network " << testcaseno << "\n";
		cout << "The bandwidth is " << flow << ".\n\n";
		testcaseno++;
	}
}

int main(){
	testActual();
	//test();
}
