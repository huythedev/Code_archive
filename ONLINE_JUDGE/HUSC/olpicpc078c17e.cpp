// Author: Perry (https://perrythedev.com)
// Problem Link: https://coder.husc.edu.vn/problem/olpicpc078c17e
// davul
#include <bits/stdc++.h>
using namespace std;

#define NAME "olpicpc078c17e"
#define ln "\n"

typedef long long ll;

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
    cerr << ln << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." << ln;
}

vector<vector<int>> adj;
int n, m;

ll solve() {
    ll total = 0;
    vector<int> degree(n + 1, 0);

    // Calculate degree for each vertex
    for (int v = 1; v <= n; v++) {
        degree[v] = adj[v].size();
    }

    // Count paths of length 2 and 3
    for (int v = 1; v <= n; v++) {
        for (int u : adj[v]) {
            if (u > v) {
                total += (degree[v] - 1); // Count paths of length 2
            }
            for (int w : adj[u]) {
                if (w != v && w > u) {
                    total += (degree[w] - 1); // Count paths of length 3
                }
            }
        }
    }

    return total;
}

int main() {
    fastio();
    docfile();
    
    cin >> n >> m;
    adj.resize(n + 1);
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    cout << solve() << ln;
    
    time();
    return 0;
}