// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

/*	Time begin - 9:13 PM
	Time end -  PM
	Desc: Topological sort
*/

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> VI;
typedef vector<VI> VVI;
const int inf = INT_MAX;

class SortedResponse {
public:
	int IsValid;
	VI SortedVertices;
};

void CalculateInDegrees(VVI& g, VI& degree) {
	for (int dest = 1; dest < g[0].size(); ++dest) {
		int vdegree = 0;
		for (int source = 1; source < g.size(); ++source) {
			if (g[source][dest] == 1) { // There is incoming edge, add it to the degree
				++vdegree;
			}
		}
		degree[dest] = vdegree;
	}
}

int GetVertexWithDegreeZero(VI& degree, VI& seen) {
	for (int vertexno = 1; vertexno < degree.size(); ++vertexno) {
		if (!seen[vertexno] && degree[vertexno] == 0) {
			seen[vertexno] = 1;
			return vertexno;
		}
	}
	return -1;
}

SortedResponse TopologicalSort(VVI& g, VI& degree) {
	SortedResponse res;
	VI seen(degree.size(), 0);
	int seencount = 0;
	while (true) {
		int vertexno = GetVertexWithDegreeZero(degree, seen);
		if (vertexno == -1) {
			break;
		}
		seencount++;
		for (int dest = 1; dest < degree.size(); ++dest) {
			if (g[vertexno][dest] != inf) {
				--degree[dest];
			}
		}
		res.SortedVertices.push_back(vertexno);
	}
	if (seencount == degree.size() - 1) {
		res.IsValid = true;
	}
	else {
		res.IsValid = false;
		res.SortedVertices.clear();
	}
	return res;
}

int main() {
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w+", stdout);
	// Read and create graph
	int n, e;
	cin >> n >> e; // Vertices numbered from 1 to n, e edges in next e lines
	VVI g = VVI(n + 1, VI(n + 1, inf));
	for (int i = 0; i < e; ++i) {
		int source, dest;
		cin >> source >> dest;
		g[source][dest] = 1;
	}
	VI degree(n + 1, 0);
	CalculateInDegrees(g, degree);
	const auto& res = TopologicalSort(g, degree);
	if (res.IsValid) {
		for (int i = 0; i < res.SortedVertices.size(); ++i) {
			cout << res.SortedVertices[i] << " ";
		}
		cout << endl;
	}
	else {
		cout << "Topological sort is not possible.";
	}
	return 0;
}
