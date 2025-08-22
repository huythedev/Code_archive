// Author: huythedev
// Problem Link: 
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

const int INF = 1e9;

struct crying {
    ll total;
    ll waiting;
    int u;

    bool operator>(const crying& other) const {
        if (total != other.total) {
            return total > other.total;
        }
        return waiting > other.waiting;
    }
};

struct pair_hash {
    template <class T1, class T2>
    size_t operator () (const pair<T1,T2> &p) const {
        auto h1 = hash<T1>{}(p.first);
        auto h2 = hash<T2>{}(p.second);
        return h1 ^ (h2 + 0x9e3779b9 + (h1 << 6) + (h1 >> 2));
    }
};

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    vector<int> deg(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; ++i) {
        deg[i] = adj[i].size();
    }
    
    if (n == 1) {
        cout << "0 0" << ln;
        return;
    }
    
    vector<int> vec(n + 1, INF);
    vec[1] = 0;

    int i = 0;
    while (true) {
        vector<int> vec2(n + 1, INF);
        for (int u = 1; u <= n; ++u) {
            if (vec[u] == INF) continue;
            
            vec2[u] = min(vec2[u], vec[u] + 1);
            
            if (deg[u] > 0) {
                int idx = i % deg[u];
                int v = adj[u][idx];
                vec2[v] = min(vec2[v], vec[u]);
            }
        }

        vec = move(vec2);

        if (vec[n] < INF) {
            cout << (i + 1) << " " << vec[n] << ln;
            return;
        }
        
        ++i;
    }
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