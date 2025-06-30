// Author: huythedev
// Problem Link: 
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

vector<pair<int, int>> ans;
vector<vector<int>> adj;

void bfs(int u, int w, int tmp) {
    queue<tuple<int, int, bool>> q;
    vector<bool> visited(adj.size(), false);
    
    q.push({u, 0, false});
    q.push({w, 0, true});
    visited[u] = true;
    visited[w] = true;
    visited[tmp] = true;
    
    while (!q.empty()) {
        auto [x, d, from_w] = q.front();
        q.pop();
        
        for (int i : adj[x]) {
            if (visited[i]) continue;
            
            if (from_w) {
                if (d % 2 == 0) 
                    ans.emplace_back(i, x);
                else
                    ans.emplace_back(x, i);
            } 
            else {
                if (d % 2 == 0) 
                    ans.emplace_back(x, i);
                else
                    ans.emplace_back(i, x);
            }
            
            visited[i] = true;
            q.push({i, d + 1, from_w});
        }
    }
}

void solve() {
    int n; cin >> n;
    adj.assign(n, vector<int>());
    for (int i = 0; i < n - 1; ++i) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (n == 2) {
        cout << "NO" << ln;
        return;
    }

    int tmp = -1;
    for (int i = 0; i < n; ++i) {
        if ((int)adj[i].size() == 2) {
            tmp = i;
            break;
        }
    }

    if (tmp == -1) {
        cout << "NO" << ln;
        return;
    }

    int u = adj[tmp][0];
    int w = adj[tmp][1];

    ans.clear();
    ans.emplace_back(u, tmp);
    ans.emplace_back(tmp, w);
    bfs(u, w, tmp);
    
    cout << "YES" << ln;
    for (auto i : ans) 
        cout << i.first + 1 << " " << i.second + 1 << ln;
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