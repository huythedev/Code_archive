// Author: huythedev
// Problem Link: https://codeforces.com/contest/2120/problem/F
#include <bits/stdc++.h>
using namespace std;

#define NAME "F"
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

vector<vector<int>> vec, vec2;
vector<bool> vis, val;
vector<int> ord, comp;

void dfs1(int v) {
    vis[v] = true;
    for (int u : vec[v]) {
        if (!vis[u]) 
            dfs1(u);
    }
    ord.push_back(v);
}

void dfs2(int v, int c) {
    comp[v] = c;
    for (int u : vec2[v]) {
        if (comp[u] == -1) 
            dfs2(u, c);
    }
}

bool twosat(int n) {
    int V = 2 * n;
    vis.assign(V, false);
    ord.clear();

    for (int i = 0; i < V; ++i) 
        if (!vis[i]) 
            dfs1(i);
    
    comp.assign(V, -1);
    vec2.assign(V, vector<int>());

    for (int v = 0; v < V; ++v) {
        for (int u : vec[v]) 
            vec2[u].push_back(v);
    }

    int c = 0;
    for (int i = V - 1; i >= 0; --i) {
        int v = ord[i];
        if (comp[v] == -1) 
            dfs2(v, c++);
    }

    val.assign(n, false);
    for (int v = 0; v < n; ++v) {
        int iv = 2 * v;
        int cv = 2 * v + 1;
        if (comp[iv] == comp[cv]) return false;
    }

    return true;
}

void add(int x, bool vx, int y, bool vy, int n) {
    int u = x * 2 + (vx ? 0 : 1);
    int v = y * 2 + (vy ? 0 : 1);
    int nu = x * 2 + (vx ? 1 : 0);
    int nv = y * 2 + (vy ? 1 : 0);
    vec[nu].push_back(v);
    vec[nv].push_back(u);
}

void solve() {
    int n, k; cin >> n >> k;
    vector<int> vec3(k);
    vec.assign(2 * n, vector<int>());
    for (int i = 0; i < k; ++i) {
        int m; cin >> m;
        vec3[i] = m;
        for (int j = 0; j < m; ++j) {
            int u, v; cin >> u >> v;
        }
    }

    for (int v = 0; v < n; ++v) 
        add(v, true, v, false, n);
    
    for (int i = 0; i < k; ++i) {
        if (vec3[i] == 0) {
            for (int v = 0; v < n; ++v) 
                vec[2 * v].push_back(2 * v + 1);
        } 
        else if (vec3[i] ==  n * (n - 1) / 2) {
            for (int v = 0; v < n; ++v) 
                vec[2 * v + 1].push_back(2 * v);
        }
    }

    cout << (twosat(n) ? "Yes" : "No") << ln;
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