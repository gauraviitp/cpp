// 16:10

#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <vector>

#define REP(i, a, b) for (int i = (a); i < (b); ++i)

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> VI;
typedef map<int, VI> MIV;
typedef map<pair<int, int>, bool> MP;

void dfs(MIV& adj, MP& inScc, int nodeno, VI& maxPath, int& curMax, int cur, VI& path){
    if(cur > curMax){
        curMax = cur;
        maxPath.assign(path.begin(), path.end());
    }

    int mcur = 0;
    REP(childno, 0, adj[nodeno].size()){
        if (inScc[make_pair(nodeno, adj[nodeno][childno])]){
            mcur = cur;
        }
        else{
            mcur = cur + 1;
        }
        path.push_back(adj[nodeno][childno]);
        dfs(adj, inScc, adj[nodeno][childno], maxPath, curMax, mcur, path);
        path.pop_back();
    }
}

int solve(MIV &adj, VI &roots, VI &leaves, MP &inScc){

    int count = 0;


    while(true) {
        VI maxPath;
        VI path;
        int curMax = 0;

        REP(nodeno, 0, roots.size()) {
            path.push_back(roots[nodeno]);
            dfs(adj, inScc, roots[nodeno], maxPath, curMax, 0, path);
            path.pop_back();
        }

        if(curMax == 0) break;

        REP(nodeno, 1, maxPath.size()) {
            inScc[make_pair(maxPath[nodeno - 1], maxPath[nodeno])] = true;
        }

        count++;
    }

    return count;
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w+", stdout);

    int t;
    cin >> t;

    REP(testno, 1, t + 1){
        int n;
        cin >> n;
        MIV adj;
        MP inScc;
        VI parents(n, 0);
        VI children(n, 0);
        REP(edge, 0, n - 1){
            int u, v;
            cin >> u >> v;
            if(adj.find(u) == adj.end()){
                adj[u] = VI({v});
            }
            else {
                adj[u].push_back(v);
            }
            inScc[make_pair(u, v)] = false;
            parents[v]++;
            children[u]++;
        }

        VI roots;
        VI leaves;
        REP(node, 0, n){
            if(parents[node] == 0) {
                roots.push_back(node);
            }
            else if (children[node] == 0){
                leaves.push_back(node);
            }
        }

        int count = solve(adj, roots, leaves, inScc);
        cout << "Case " << testno << ": " << count << "\n";
    }

}
