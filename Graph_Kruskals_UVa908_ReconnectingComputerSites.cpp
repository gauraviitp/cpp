
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> VI;

class Edge {
public:
	int u;
	int v;
	long w;
	Edge(int pu, int pv, int pw) : u(pu), v(pv), w(pw) {}
	bool operator < (const Edge& e){
		return w < e.w;
	}
};

typedef vector<Edge> VE;

class Set {
public:
	VI set;
	Set(int n){
		for(int i = 0; i < n; ++i){
			set.push_back(-1);
		}
	}
	// can be improved by makind a function find
	// and updating the parent while finding the parent
	// its a todo
	bool sameSet(int i, int j){
		while(set[i] != -1) { i = set[i]; }
		while(set[j] != -1) { j = set[j]; }
		return i == j;
	}
	void unionSet(int i, int j){
		while(set[i] != -1) { i = set[i]; }
		while(set[j] != -1) { j = set[j]; }
		set[i] = j; // make j as parent of i
	}
};

// compute the min spanning tree cost

long compute(VE& edges, int vcount){
	long cost = 0;
	sort(edges.begin(), edges.end()); // sort in asc order
	Set set(vcount + 1); // v numbered from 1
	for(auto& e : edges){
		if(!set.sameSet(e.u, e.v)){
			cost += e.w;
			set.unionSet(e.u, e.v);
		}
	}
	return cost;
}

// read the input

void read(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w+", stdout);
	int tno = 1;
	while(true){
		int n;
		cin >> n;
		if(cin.eof()) break;
		if(tno != 1) cout << "\n"; // newline between test cases
		long tcost = 0; // original cost
		for(int i = 0; i < n - 1; ++i){
			long val;
			cin >> val >> val >> val;
			tcost += val;
		}
		int k; 
		cin >> k;
		VE edges;
		for(int i = 0; i < k; ++i){
			int u, v, w;
			cin >> u >> v >>  w;
			edges.push_back(Edge(u, v, w));
		}
		int m;
		cin >> m;
		for(int i = 0; i < m; ++i){
			int u, v, w;
			cin >> u >> v >>  w;
			edges.push_back(Edge(u, v, w));
		}
		long cost = compute(edges, n);
		cout << tcost << "\n";
		cout << cost << "\n";
		tno++;
	}
}

int main(){
	read();
}
