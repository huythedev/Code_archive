// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "stalingrad"
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

int n;
vector<vector<int>> adj;
vector<int> treeSize;
vector<int> parent;
vector<bool> is_occupied;
vector<int> vec;

void dfs_precompute(int u, int p) {
    parent[u] = p;
    treeSize[u] = 1;
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs_precompute(v, u);
        treeSize[u] += treeSize[v];
    }
}

pair<ll, ll> recursive(int u) {
    vec[u] = is_occupied[u];

    ll cuts = 0, cost = 0;

    for (int v : adj[u]) {
        if (v == parent[u]) 
            continue;

        pair<ll, ll> child_res = recursive(v);
        vec[u] += vec[v];
        cuts += child_res.first;
        cost += child_res.second;
    }

    if (vec[u] == 0)
        return {0, 0};

    ll cuts2 = 1;
    ll cost2 = (ll)treeSize[u] - vec[u];

    if (is_occupied[u])
        return {cuts2, cost2};

    if (cuts2 < cuts)
        return {cuts2, cost2};
    
    if (cuts < cuts2)
        return {cuts, cost};
    
    if (cost2 < cost)
        return {cuts2, cost2};
    else
        return {cuts, cost};
}

void solve() {
    int subtask; cin >> subtask;
    int q;
    cin >> n >> q;

    adj.resize(n + 1);
    treeSize.resize(n + 1);
    parent.resize(n + 1);
    is_occupied.assign(n + 1, false);
    vec.resize(n + 1);

    for (int i = 2; i <= n; ++i) {
        int p;
        cin >> p;
        adj[p].push_back(i);
        adj[i].push_back(p);
    }

    dfs_precompute(1, 0);

    for (int k = 0; k < q; ++k) {
        char type;
        int v;
        cin >> type >> v;

        if (type == '+')
            is_occupied[v] = true;
        else
            is_occupied[v] = false;
        
        ll cuts = 0, cost = 0;
        for (int i : adj[1]) {
            if (i == parent[1]) 
                continue;

            pair<ll, ll> res = recursive(i);
            cuts += res.first;
            cost += res.second;
        }

        cout << cuts << " " << cost << ln;
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