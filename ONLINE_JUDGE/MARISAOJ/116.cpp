// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "116"
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

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n + 5);
    for (int i = 0; i < m; ++i) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<int> dist(n + 5, INF);
    dist[1] = 0;

    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < (int)adj[u].sz; ++i) {
            if (dist[adj[u][i]] == INF) {
                dist[adj[u][i]] = dist[u] + 1;
                q.push(adj[u][i]);
            }
        }   
    }

    for (int i = 2; i <= n; ++i) {
        if (dist[i] == INF) cout << -1;
        else cout << dist[i];
        cout << " ";
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