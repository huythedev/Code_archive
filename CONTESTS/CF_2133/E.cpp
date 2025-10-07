// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "NAME"
#define ln "\n"
#define sz size()

typedef long long ll;
typedef long double ld;

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void fileIO() {
    if (ifstream(NAME ".INP")) {
        freopen(NAME ".INP", "r", stdin);
        freopen(NAME ".OUT", "w", stdout);
    }
}

void time() {
    cerr << ln << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." 
         << ln;
}

void dfsSize(int u, int pr, vector<vector<int>>& adj, vector<int>& vec) {
    vec[u] = 1;
    for (int v : adj[u]) {
        if (v != pr) {
            dfsSize(v, u, adj, vec);
            vec[u] += vec[v];
        }
    }
}

int findCentroid(int start, int par_start, int total, vector<vector<int>>& adj, vector<int>& vec) {
    int curr = start;
    int par = par_start;
    while (true) {
        int heavy = -1;
        int maxs = 0;
        for (int v : adj[curr]) {
            if (v != par) {
                int s = vec[v];

                if (s > maxs) {
                  maxs = s;
                  heavy = v;
                }
            }
        }

        if (maxs > total / 2) {
            par = curr;
            curr = heavy;
        } 
        else {
            break;
        }
    }

    return curr;
}

void getops(int root, int p, vector<vector<int>>& adj, vector<int>& vec, vector<pair<int,int>>& ops) {
    dfsSize(root, p, adj, vec);
    int total = vec[root];
    if (total == 1) {
        ops.emplace_back(1, root);
        return;
    }

    int cent = findCentroid(root, p, total, adj, vec);
    ops.emplace_back(1, cent);

    vector<int> vec2;

    int cnt = 0;
    for (int v : adj[cent]) {
        if (v == p) continue;
        vec2.push_back(v);
        cnt++;
    }

    bool tmp = (cnt >= 2);
    if (tmp) 
        ops.emplace_back(2, cent);
    
    for (int v : vec2) {
        getops(v, cent, adj, vec, ops);
    }
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    vector<int> vec(n + 1, 0);
    vector<pair<int,int>> ops;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    getops(1, -1, adj, vec, ops);

    cout << ops.size() << ln;
    for (auto[t, x] : ops) {
        cout << t << ' ' << x << ln;
    }
}

signed main() {
    fastIO();
    fileIO();

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    time();
    return 0;
}