// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "harem"
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
    if (ifstream(NAME ".inp")) {
        freopen(NAME ".inp", "r", stdin);
        freopen(NAME ".out", "w", stdout);
    }
}

void time() {
    cerr << ln << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." 
         << ln;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> edges(m);
    vector<vector<int>> adj(n);
    vector<int> in_degree(n, 0);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        edges[i] = {x, y};
        adj[x].push_back(y);
        in_degree[y]++;
    }
    queue<int> q;
    vector<int> full_order;
    vector<int> in_degree_copy = in_degree;
    for (int i = 0; i < n; ++i) {
        if (in_degree_copy[i] == 0) q.push(i);
    }
    while (!q.empty()) {
        if (q.size() > 1) {
            cout << -1 << ln;
            return;
        }
        int u = q.front();
        q.pop();
        full_order.push_back(u);
        for (int v : adj[u]) {
            if (--in_degree_copy[v] == 0) q.push(v);
        }
    }
    if (full_order.size() < n) {
        cout << -1 << ln;
        return;
    }
    unordered_map<ll, int> edge_to_day;
    for (int i = 0; i < m; ++i) {
        auto [x, y] = edges[i];
        ll key = (static_cast<ll>(x) << 32) | y;
        if (!edge_to_day.count(key) || i < edge_to_day[key]) {
            edge_to_day[key] = i;
        }
    }
    int max_day = -1;
    for (int i = 0; i < n - 1; ++i) {
        int x = full_order[i];
        int y = full_order[i + 1];
        ll key = (static_cast<ll>(x) << 32) | y;
        if (!edge_to_day.count(key)) {
            cout << -1 << ln;
            return;
        }
        max_day = max(max_day, edge_to_day[key]);
    }
    cout << max_day + 1 << ln;
    for (int u : full_order) {
        cout << u + 1 << " ";
    }
    cout << ln;
}

signed main() {
    fastio();
    docfile();

    int t = 1;
    while (t--) {
        solve();
    }

    time();
    return 0;
}