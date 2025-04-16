// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "NOTES"
#define ln "\n"
#define sz size()

typedef long long ll;
typedef long double ld;

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void docfile() {
    if (ifstream(NAME ".INP")) {
        freopen(NAME ".INP", "r", stdin);
        freopen(NAME ".OUT", "w", stdout);
    }
}

void time() {
    cerr << ln << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." 
         << ln;
}

signed main() {
    fastio();
    docfile();
    
    int n; cin >> n;
    
    vector<vector<int>> cost(n+1, vector<int>(n+1));
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> cost[i][j];
        }
    }
    
    vector<int> deliver_cost(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> deliver_cost[i];
    }
    
    vector<bool> visited(n+1, false);
    vector<int> min_cost(n+1, INT_MAX);
    
    min_cost[0] = 0;
    int total_cost = 0;
    
    for (int i = 0; i <= n; i++) {
        int next_node = -1;
        
        for (int j = 0; j <= n; j++) {
            if (!visited[j] && (next_node == -1 || min_cost[j] < min_cost[next_node])) {
                next_node = j;
            }
        }
        
        if (next_node == -1) break;
        
        visited[next_node] = true;
        total_cost += min_cost[next_node];
        
        for (int j = 1; j <= n; j++) {
            if (!visited[j]) {
                int edge_cost = (next_node == 0) ? deliver_cost[j] : cost[next_node][j];
                min_cost[j] = min(min_cost[j], edge_cost);
            }
        }
        
        if (!visited[0]) {
            for (int j = 1; j <= n; j++) {
                if (visited[j]) {
                    min_cost[0] = min(min_cost[0], deliver_cost[j]);
                }
            }
        }
    }
    
    cout << total_cost << ln;

    time();
    return 0;
}