// Author: huythedev
// Problem Link: 

#include <bits/stdc++.h>
using namespace std;

#define NAME "TCC"
#define ln "\n"
#define sz size()

typedef long long ll;
typedef long double ld;

const int MAXN = 1e5 + 5;
vector<int> adj[MAXN];
ll sub_sz[MAXN];
ll dp[MAXN];
ll ans[MAXN];
int n;

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

void dfs1(int u, int p) {
    sub_sz[u] = 1;
    dp[u] = 0;
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs1(v, u);
        sub_sz[u] += sub_sz[v];
        dp[u] += dp[v] + sub_sz[v];
    }
}

void dfs2(int u, int p) {
    for (int v : adj[u]) {
        if (v == p) continue;
        ans[v] = ans[u] - sub_sz[v] + (n - sub_sz[v]);
        dfs2(v, u);
    }
}


signed main() {
    fastio();
    docfile();

    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs1(1, 0);

    ans[1] = dp[1];

    dfs2(1, 0);

    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << ln;
    }

    time();
    return 0;
}