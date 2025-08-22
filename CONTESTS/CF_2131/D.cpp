#include <bits/stdc++.h>
using namespace std;

#define NAME "NAME"
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

void solve() {
    int n; 
    cin >> n;
    vector<vector<int>> adj(n+1);
    vector<int> deg(n + 1, 0);
    for (int i = 0; i < n-1; ++i) {
        int u, v; 
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        ++deg[u]; 
        ++deg[v];
    }

    int L = 0;
    for (int i = 1; i <= n; ++i) 
        if (deg[i] == 1) 
            ++L;
    
    int best = 0;
    for (int u = 1; u <= n; ++u) {
        int leaf = 0;

        for (int v : adj[u]) 
            if (deg[v] == 1) 
                ++leaf;

        int candidate = leaf + (deg[u] == 1 ? 1 : 0);
        best = max(best, candidate);
    }

    int ans = max(0, L - best);
    cout << ans << ln;
}

signed main() {
    docfile();
    fastio();

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    time();
    return 0;
}