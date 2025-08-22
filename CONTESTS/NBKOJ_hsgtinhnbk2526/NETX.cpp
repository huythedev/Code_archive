// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "NETX"
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

vector<vector<int>> adj;
vector<bool> vis;
vector<int> vec, low, parent;
set<pair<int, int>> bridges;
int t;

void bridge(int u) {
    vis[u] = true;
    vec[u] = low[u] = ++t;

    for (int v : adj[u]) {
        if (!vis[v]) {
            parent[v] = u;
            bridge(v);
            low[u] = min(low[u], low[v]);

            if (low[v] > vec[u]) 
                bridges.insert({min(u, v), max(u, v)});
        } 
        else if (v != parent[u]) {
            low[u] = min(low[u], vec[v]);
        }
    }
}

void dfs(int u, vector<vector<int>>& g) {
    vis[u] = true;
    for (int v : g[u]) 
        if (!vis[v]) dfs(v, g);
}

void solve() {
    int n, m;
    cin >> n >> m;
    
    adj.assign(n + 1, vector<int>());
    vis.assign(n + 1, false);
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    int comp = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i, adj);
            comp++;
        }
    }
    
    if (comp > 1) {
        cout << comp << ln;
        return;
    }
    
    vis.assign(n + 1, false);
    vec.assign(n + 1, 0);
    low.assign(n + 1, 0);
    parent.assign(n + 1, -1);
    t = 0;
    bridges.clear();
    
    bridge(1);
    
    if (bridges.empty()) {
        cout << 0 << ln;
        return;
    }
    
    vector<vector<int>> adj2(n + 1);
    for (int u = 1; u <= n; u++) {
        for (int v : adj[u]) {
            if (u < v && !bridges.count({u, v})) {
                adj2[u].push_back(v);
                adj2[v].push_back(u);
            }
        }
    }
    
    vis.assign(n + 1, false);
    int comp2 = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i, adj2);
            comp2++;
        }
    }
    
    cout << (comp2 + 1) / 2 << ln;
}

signed main() {
    docfile();
    fastio();

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    time();
    return 0;
}