// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "CONNECT"
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

const int N = 1e6 + 10;
vector<int> adj[N];
bool vis[N];
ll x[N];
int n, m;

void dfs(int u, vector<int>& component) {
    vis[u] = true;
    component.push_back(u);
    for (int v : adj[u]) {
        if (!vis[v]) {
            dfs(v, component);
        }
    }
}

signed main() {
    fastio();
    docfile();

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<vector<int>> components;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            vector<int> component;
            dfs(i, component);
            components.push_back(component);
        }
    }
    
    int k = components.size();
    if (k == 1) {
        cout << 0 << ln;
        return 0;
    }
    
    vector<ll> min_costs;
    for (auto& component : components) {
        ll min_x = LLONG_MAX;
        for (int u : component) {
            min_x = min(min_x, x[u]);
        }
        min_costs.push_back(min_x);
    }
    
    sort(min_costs.begin(), min_costs.end());
    
    ll total_cost = 0;
    for (int i = 1; i < k; i++) {
        total_cost += min_costs[0] + min_costs[i];
    }
    
    cout << total_cost << ln;

    time();
    return 0;
}
