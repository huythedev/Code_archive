// Author: huythedev
// Problem Link: https://codeforces.com/contest/2109/problem/D
#include <bits/stdc++.h>
using namespace std;

#define NAME "D"
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

vector<int> bfs(int n, const vector<vector<int>>& adj) {
    vector<int> dist(n, -1);
    queue<int> q;
    q.push(0);
    dist[0] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return dist;
}

pair<bool, vector<int>> is_bipartite(int n, const vector<vector<int>>& adj) {
    vector<int> color(n, -1);
    queue<int> q;
    q.push(0);
    color[0] = 0;
    bool bipartite = true;
    while (!q.empty() && bipartite) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (color[v] == -1) {
                color[v] = color[u] ^ 1;
                q.push(v);
            } else if (color[v] == color[u]) {
                bipartite = false;
                break;
            }
        }
    }
    return {bipartite, color};
}

void solve() {
    int n, m, l;
    cin >> n >> m >> l;
    vector<int> A(l);
    for (int& a : A) cin >> a;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    auto [bipartite, color] = is_bipartite(n, adj);
    vector<int> dist = bfs(n, adj);
    bool has_odd = false;
    for (int a : A) {
        if (a % 2) {
            has_odd = true;
            break;
        }
    }
    string res(n, '0');
    if (bipartite) {
        for (int i = 0; i < n; ++i) {
            if (color[i] == 0) {
                res[i] = '1';
            } else {
                res[i] = has_odd ? '1' : '0';
            }
        }
    } else {
        if (l == 0) {
            res[0] = '1';
        } else {
            fill(res.begin(), res.end(), '1');
        }
    }
    cout << res << ln;
}

signed main() {
    fastio();
    docfile();

    int t; cin >> t;
    while (t--) {
        solve();
    }

    time();
    return 0;
}