// Author: Perry (https://perrythedev.com)
// Problem Link: https://coder.husc.edu.vn/problem/olpicpc078c17e
// davul
#include <bits/stdc++.h>
using namespace std;

#define NAME "olpicpc078c17e"
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
vector<bool> visited;
int n, m;

void dfs(int v, int len, int start, ll& paths) {
    if (len > 0) paths++;
    
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u]) {
            dfs(u, len + 1, start, paths);
        }
    }
    visited[v] = false;
}

ll solve() {
    ll total = 0;
    visited.resize(n + 1);
    
    for (int i = 1; i <= n; i++) {
        fill(visited.begin(), visited.end(), false);
        dfs(i, 0, i, total);
    }
    
    return total;
}

int main() {
    fastio();
    docfile();
    
    cin >> n >> m;
    adj.resize(n + 1);
    
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    cout << solve() << ln;
    
    time();
    return 0;
}