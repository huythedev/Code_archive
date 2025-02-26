// Author: Perry (https://perrythedev.com)
// Problem Link: https://coder.husc.edu.vn/problem/olpicpc043c10e
// davul
#include <bits/stdc++.h>
using namespace std;

#define NAME "olpicpc043c10e"
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

vector<vector<int>> adj;
vector<pair<int, int>> extra_edges;
vector<int> dist;

void bfs(int start) {
    dist.assign(adj.size(), -1);
    queue<int> q;
    q.push(start);
    dist[start] = 0;

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
}

int main() {
    fastio();
    docfile();

    int n, m;
    cin >> n >> m;
    adj.resize(n + 1);
    vector<bool> used(n + 1, false);
    int edges_in_tree = 0;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        
        if (!used[u] || !used[v]) {
            adj[u].push_back(v);
            adj[v].push_back(u);
            used[u] = used[v] = true;
            edges_in_tree++;
        } else {
            extra_edges.push_back({u, v});
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int u, v;
        cin >> u >> v;
        
        bfs(u);
        int ans = dist[v];
        
        // Try paths through extra edges
        for (auto& e : extra_edges) {
            int x = e.first, y = e.second;
            if (dist[x] != -1 && dist[y] != -1) {
                bfs(y);
                if (dist[v] != -1) {
                    ans = min(ans, dist[v] + 1 + dist[x]);
                }
            }
        }
        
        cout << ans << ln;
    }

    time();
    return 0;
}