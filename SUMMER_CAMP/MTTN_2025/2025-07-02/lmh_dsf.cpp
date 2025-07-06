// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "lmh_dsf"
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

vector<int> parent;

int find_set(int u) {
    if (u == parent[u]) {
        return u;
    }
    return parent[u] = find_set(parent[u]);
}

void unite_sets(int u, int v) {
    int root_u = find_set(u);
    int root_v = find_set(v);
    if (root_u != root_v) {
        parent[root_u] = root_v;
    }
}

void solve() {
    int n, m;
    cin >> n >> m;

    parent.resize(n + 1);
    iota(parent.begin(), parent.end(), 0);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;

        int root_u = find_set(u);
        int root_v = find_set(v);

        if (root_u != root_v) {
            cout << "Y" << ln;
            parent[root_u] = root_v; 
        } else {
            cout << "N" << ln;
        }
    }
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