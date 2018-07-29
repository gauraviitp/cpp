// UVa 10397 - Connect the campus

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> VI;

class Point {
public:
	int x, y;
	Point(int px, int py) : x(px), y(py) {}
	double dist(Point other); // square of the distance between two points
};

double Point::dist(Point other){
	int xDiff = (x - other.x), yDiff = (y - other.y);
	return xDiff * xDiff + yDiff * yDiff;
}

typedef vector<Point> VP;

class Edge {
public:
	int u, v, w;
	Edge(int pu, int pv, int pw) : u(pu), v(pv), w(pw) {}
	bool operator < (const Edge& other){
		return w < other.w;
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

	int find(int i){
		if(set[i] == -1) return i;
		else {
			return (set[i] = find(set[i])); // assign absolute root as parent
		}
	}
	
	bool sameSet(int i, int j){
		return find(i) == find(j);
	}
	void unionSet(int i, int j){
		set[find(i)] = find(j);
	}
};

// compute the partial minimum spanning tree

double compute(VE& edges, int n, VE& connectedEdges){
	double cost = 0;
	Set set(n + 1); // vertices are numbered from 1
	for(auto& e : connectedEdges){
		set.unionSet(e.u, e.v);
	}
	sort(edges.begin(), edges.end());
	for(auto& e : edges){
		if(!set.sameSet(e.u, e.v)){
			cost += sqrt(e.w);
			set.unionSet(e.u, e.v);
		}
	}
	return cost;
}

void read(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w+", stdout);
	while(true){
		int n;
		cin >> n;
		if(cin.eof()) break;
		VP points;
		points.push_back(Point(0, 0)); // a dummy point
		for(int i = 1; i <= n; ++i){
			int x, y;
			cin >> x >> y;
			points.push_back(Point(x, y));
		}
		VE edges;
		for(int i = 1; i <= n; ++i){
			for(int j = i + 1; j <= n; ++j){
				edges.push_back(Edge(i, j, points[i].dist(points[j])));
			}
		}
		int m;
		cin >> m;
		VE connectedEdges;
		for(int i = 0; i < m; ++i){
			int u, v;
			cin >> u >> v;
			connectedEdges.push_back(Edge(u, v, points[u].dist(points[v])));
		}
		double cost = compute(edges, n, connectedEdges);
		cout.setf(ios::fixed);
		cout << setprecision(2);
		cout << cost << "\n";
	}
}

int main(){
	read();
}
