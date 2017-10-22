#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Node {
    /*vertex number of the pushing node i.e. previous node*/
    int u;
    /*vertex number*/
    int v;
    /*weight*/
    int w;
    Node(int prevNo, int vertexNo, int weight) : u(prevNo), v(vertexNo), w(weight) {} 
};
class Compare {
  public:
    bool operator() (Node a, Node b) {
      return a.w < b.w;
    }  
};
typedef vector<int> VN;
typedef vector<vector<int>> VVN;
typedef priority_queue<Node, vector<Node>, Compare> PQ;
vector<int> findShortestPath(VVN& g, int start, int end){
    VN prev(g.size(), -1);
    PQ pq;
    pq.push(Node(-1, start, 0));
    while(!pq.empty()){
        const Node node = pq.top();
        pq.pop();
        prev[node.v] = node.u;
        if(node.v == end) break;
        for(int v = 1; v < g.size(); ++v){
            if(g[node.v][v] != 0){
                pq.push(Node(node.v, v, node.w + g[node.v][v]));
            }
        }
    }
    VN path;
    path.push_back(end);
    for(int curNode = end; curNode != start;curNode = prev[curNode]){
        path.push_back(prev[curNode]);
    }
    return path;
}
void printGraph(VVN& g){
    for(int i = 1; i < g.size(); ++i){
	    for(int j = 1; j < g[i].size(); ++j){
	        cout << g[i][j] << " ";
	    }
	    cout << "\n";
	}
}
int main() {
	/* Read the graph */
	int n, edges; // n : number of the vertices in the graph
	          // e: number of lines that follow, each line depicts one edge
	cin >> n >> edges;
	VVN g(n + 1, VN(n + 1, 0));
	for(int edgeno = 0; edgeno < edges; ++edgeno){
	    int s, e, w; // s: start node, e: end node, w: weight
	    cin >> s >> e >> w;
	    g[s][e] = w;
	}
	int start, end; // start node and end node for shortest path
	cin >> start >> end;
	printGraph(g);
	VN path = findShortestPath(g, start, end);
	for(const auto& e : path){
	    cout << e << " ";
	}
	cout << "\n";
	return 0;
}
