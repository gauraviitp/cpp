// Rare order

#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;
typedef vector<int> VI;
typedef vector<vector<int>> VVI;
typedef stack<int> SI;

// finds the first index of mismatch
int mismatch(string& a, string& b, int& achar, int& bchar){
	const char firstChar = 'A';
	for(int i = 0; i < (int)a.size() && i < (int)b.size(); ++i){
		if(a[i] != b[i]){
			achar = (int)(a[i] - firstChar);
			bchar = (int)(b[i] - firstChar);
			return i;
		}
	}
	return -1;
}

void depthFirstSearch(VVI& graph, int node, VI& seen, SI& order){
	for(int i = 0; i < (int)graph.size(); ++i){
		if(graph[node][i] && !seen[i]){
			seen[i] = 1;
			depthFirstSearch(graph, i, seen, order);
		}
	}
	order.push(node); // stack contains the visited nodes, contains topological ordering
}

void printGraph(const VVI& graph){
	for(int i = 0; i < (int)graph.size(); ++i){
		for(int j = 0; j < (int)graph[0].size(); ++j){
			cout << graph[i][j] << " ";
		}
		cout << "\n";
	}
}

int main(){
	// read the input and create the graph
	const int size = 26;
	const char firstChar = 'A';
	VVI graph(size, VI(size, 0));
	string prev, cur;
	cin >> prev;
	if(prev == "#"){
		return 0;
	}
	int startChar = prev[0] - firstChar;
	while(cin >> cur){
		if(cur == "#"){
			break;
		}
		int prevChar, curChar;
		int mi = mismatch(prev, cur, prevChar, curChar);
		if(mi != -1){
			graph[prevChar][curChar] = 1;
		}
		prev = cur;
	}
	//printGraph(graph);
	VI seen(graph.size(), 0);
	SI order;
	depthFirstSearch(graph, startChar,seen, order);
	// convert the internal mapping back to characters
  // Effectively, order contains the topological ordering.
  // In the worst case, an extra check might have been required to 
  // check if the ordering is partial or absolute.
	while(!order.empty()){
		int e = order.top(); order.pop();
		cout << (char)(e + 'A');
	}
	cout << endl;
	return 0;
}
