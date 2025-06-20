// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "E"
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

const int MAXN = 200010;
vector<int> adj[MAXN];
ll a[MAXN], threat[MAXN], min_val[MAXN];

void dfs(int u, int p) {
    if (p == -1) {
        threat[u] = a[u];
        min_val[u] = a[u];
    } else {
        threat[u] = max(a[u], a[u] - min_val[p]);
        min_val[u] = min(a[u], a[u] - threat[p]);
    }
    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u);
        }
    }
}

void solve() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        adj[i].clear();
    }

    for (int i = 0; i < n - 1; i++) {
        int v, u; cin >> v >> u;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }

    dfs(1, -1);
    for (int i = 1; i <= n; i++) {
        cout << threat[i] << " ";
    }
    cout << ln;
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