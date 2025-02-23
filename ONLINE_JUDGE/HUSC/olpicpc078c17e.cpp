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
int n, m;

ll countPaths(int start) {
    vector<int> dist(n + 1, -1);
    vector<ll> count(n + 1, 0);
    queue<int> q;
    
    dist[start] = 0;
    count[start] = 1;
    q.push(start);
    ll paths = 0;
    
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        
        if(dist[v] > 0) {
            paths += count[v];
        }
        
        for(int u : adj[v]) {
            if(dist[u] == -1) {
                dist[u] = dist[v] + 1;
                count[u] = count[v];
                q.push(u);
            } else if(dist[u] == dist[v] + 1) {
                count[u] += count[v];
            }
        }
    }
    
    return paths;
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
    
    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        ans += countPaths(i);
    }
    
    cout << ans << ln;
    
    time();
    return 0;
}