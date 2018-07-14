// UVa 186 - Trip routing

#include <cstdio>
#include <iostream>
#include <limits>
#include <map>
#include <string>
#include <vector>

#define REP(i, a, b) for(int i = (a); i <= (b); ++i)
	
using namespace std;
typedef vector<int> VI;
typedef vector<VI> VVI;
const int NaN = numeric_limits<int>::max() / 4;

void getShortestPath(VVI& adjMatrix, VVI& next){
	int n = next.size();
	REP(i, 0, n - 1){
		REP(j, 0, n - 1){
			if(adjMatrix[i][j] != NaN) next[i][j] = j;
		}
	}
	REP(k, 0, n - 1){
		REP(i, 0, n - 1){
			REP(j, 0, n - 1){
				if(adjMatrix[i][j] > adjMatrix[i][k] + adjMatrix[k][j]){
					adjMatrix[i][j] = adjMatrix[i][k] + adjMatrix[k][j];
					next[i][j] = next[i][k];
				}
			}
		}
	}
}

string format(string str, int len){
	return str + string(len - str.size(), ' ');
}

int main(){
	int dist;
	map<string, int> m;
	map<int, string> mr;
	VVI adjMatrix(100, VI(100, NaN));
	vector<vector<string>> routes(100, vector<string>(100));
	int cityno = 0;
	for(string line; getline(cin, line);){
		if(line == "") break;
		char source[20], dest[20], route[10];
		sscanf(line.c_str(), "%[a-z A-Z0-9-_],%[a-z A-Z0-9-_],%[a-z A-Z0-9-_],%d", source, dest, route, &dist);
		if(m.find(source) == m.end()) { m[source] = cityno; mr[cityno] = source; cityno++; }
		if(m.find(dest) == m.end()) { m[dest] = cityno; mr[cityno] = dest; cityno++; }
		// add both ways
		if(dist < adjMatrix[m[source]][m[dest]]){
			adjMatrix[m[source]][m[dest]] = dist;
			adjMatrix[m[dest]][m[source]] = dist;
			routes[m[source]][m[dest]] = route;
			routes[m[dest]][m[source]] = route;
		}
	}
	VVI next(cityno, VI(cityno, -1));
	getShortestPath(adjMatrix, next);
	
	for(string line; getline(cin, line);){
		if(line == "") break;
		char source[20], dest[20];
		sscanf(line.c_str(), "%[a-z A-Z0-9-_],%[a-z A-Z0-9-_]", source, dest);
		cout << "\n\n"; // two extra lines as specified in reqs
		cout << format("From", 20) << " " 
			 << format("To", 20) << " " 
			 << format("Route", 10) << " " 
			 << format("Miles", 5) << "\n";
		cout << string(20, '-') << " " 
			 << string(20, '-') << " " 
			 << string(10, '-') << " " 
			 << string(5, '-') << "\n";
		int sourceCity = m[source];
		int nextCity = next[m[source]][m[dest]];
		while(sourceCity != m[dest]){
			cout << format(mr[sourceCity], 20) << " " 
				 << format(mr[nextCity], 20) << " " 
				 << format(routes[sourceCity][nextCity], 10) << " " 
				 << format(to_string(adjMatrix[sourceCity][nextCity]), 5) << "\n" ;
			sourceCity = nextCity;
			nextCity = next[nextCity][m[dest]];
		}
		cout << string(53, ' ') 
			 << string(5, '-') << "\n";
		cout << string(42, ' ') 
			 << format("Total", 10) << " "
			 << format(to_string(adjMatrix[m[source]][m[dest]]), 5);
	}
}
