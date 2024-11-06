#include <bits/stdc++.h>
using namespace std;

#define NAME "cwdrel"
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
    cerr << ln << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." << ln;
}

const int maxn = 2e5 + 5;
vector<vector<pair<int, pair<int, int>>>> adj(maxn);
vector<bool> visited(maxn, false);
vector<bool> reachable(maxn, false);
vector<ll> x(maxn, 0), y(maxn, 0);

void dfs(int u) {
    visited[u] = true;
    reachable[u] = true;
    
    for(auto& e : adj[u]) {
        int v = e.first;
        int dx = e.second.first;
        int dy = e.second.second;
        
        if(!visited[v]) {
            x[v] = x[u] + dx;
            y[v] = y[u] + dy;
            dfs(v);
        }
    }
}

int main() {
    fastio();
    docfile();
    
    int n, m;
    cin >> n >> m;
    
    for(int i = 0; i < m; ++i) {
        int a, b, dx, dy;
        cin >> a >> b >> dx >> dy;
        adj[a].push_back({b, {dx, dy}});
        adj[b].push_back({a, {-dx, -dy}});
    }
    
    dfs(1);
    
    for(int i = 1; i <= n; ++i) {
        if(reachable[i]) {
            cout << x[i] << " " << y[i] << ln;
        }
        else {
            cout << "NA" << ln;
        }
    }
    
    time();
    return 0;
}