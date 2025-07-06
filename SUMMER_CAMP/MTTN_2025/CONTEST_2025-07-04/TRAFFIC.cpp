// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "TRAFFIC"
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

vector<vector<pair<int, int>>> adj;
vector<int> dist;

void dfs(int u, int target, vector<bool>& vis) {
    vis[u] = true;
    
    for (auto& edge : adj[u]) {
        int v = edge.first;
        int cost = edge.second;
        
        if (!vis[v]) {
            dist[v] = dist[u] + cost;
            dfs(v, target, vis);
        }
    }
}

int calc(int n, int a, int b) {
    dist.assign(n + 1, INT_MAX);
    
    int res = 0;
    
    for (int i = 1; i <= n; i++) {
        if (i == a || i == b) 
            continue;
        
        dist.assign(n + 1, INT_MAX);
        vector<bool> vis(n + 1, false);
        dist[i] = 0;
        dfs(i, a, vis);
        int distA = dist[a];
        
        dist.assign(n + 1, INT_MAX);
        vis.assign(n + 1, false);
        dist[i] = 0;
        dfs(i, b, vis);
        int distB = dist[b];
        
        if (distA == INT_MAX && distB == INT_MAX)
            return INT_MAX;
        
        if (distA == INT_MAX)
            res += distB;
        else if (distB == INT_MAX)
            res += distA;
        else
            res += min(distA, distB);
    }
    
    return res;
}

void solve() {
    int n; cin >> n;
    
    adj.assign(n + 1, vector<pair<int, int>>());
    
    for (int i = 0; i < n - 1; i++) {
        int x, y; cin >> x >> y;
        adj[x].push_back({y, 0});
        adj[y].push_back({x, 1});
    }
    
    int res = INT_MAX;
    
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++)
            res = min(res, calc(n, i, j));
    }
    
    cout << res << ln;
}

signed main() {
    docfile();
    fastio();

    int t = 1;
    cin >> t;
    while (t--) {
        string tmp; 
        getline(cin, tmp);
        solve();
    }

    time();
    return 0;
}