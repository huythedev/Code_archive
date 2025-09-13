// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "WEATHER"
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

int N, M;
vector<vector<pair<int,int>>> adj;
vector<int> tin, low, sub, par;
vector<char> vis;
int timer = 0;
ll ans = 0;

void dfs(int u, int peid = -1) {
    vis[u] = 1;
    tin[u] = low[u] = ++timer;
    sub[u] = 1;

    for (auto [v, id] : adj[u]) {
        if (id == peid) 
            continue;

        if (!vis[v]) {
            par[v] = u;
            dfs(v, id);
            sub[u] += sub[v];
            low[u] = min(low[u], low[v]);

            if (low[v] > tin[u]) {
                ans += 1LL * sub[v] * (N - sub[v]);
            }
        } 
        else {
            low[u] = min(low[u], tin[v]);
        }
    }
}

void solve() {
    cin >> N >> M;
    adj.assign(N + 1, {});
    tin.assign(N + 1, 0);
    low.assign(N + 1, 0);
    sub.assign(N + 1, 0);
    par.assign(N + 1, -1);
    vis.assign(N + 1, 0);
    timer = 0;
    ans = 0;

    for (int i = 0; i < M; ++i) {
        int u, v; cin >> u >> v;
        
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }

    for (int i = 1; i <= N; ++i) {
        if (!vis[i]) 
            dfs(i, -1);
    }

    cout << ans << ln;
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
