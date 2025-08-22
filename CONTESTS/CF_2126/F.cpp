// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "NAME"
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

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    vector<vector<pair<int, ll>>> adj(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v; ll c;
        cin >> u >> v >> c;
        adj[u].emplace_back(v, c);
        adj[v].emplace_back(u, c);
    }

    vector<bool> vec(n + 1, false);
    for (int i = 1; i <= n; ++i) {
        if ((int)adj[i].size() >= 450) {
            vec[i] = true;
        }
    }
    
    vector<map<int, ll>> vec2(n + 1);
    for (int i = 1; i <= n; ++i) {
        if (vec[i]) {
            for (auto [j, k] : adj[i]) {
                vec2[i][a[j]] += k;
            }
        }
    }
    
    vector<vector<pair<int, ll>>> vec3(n + 1);
    for (int i = 1; i <= n; ++i) {
        if (vec[i]) {
            for (auto [j, k] : adj[i]) {
                if (vec[j]) {
                    vec3[i].emplace_back(j, k);
                }
            }
        }
    }
    
    ll res = 0;
    for (int i = 1; i <= n; ++i) {
        for (auto [j, k] : adj[i]) {
            if (i < j && a[i] != a[j]) {
                res += k;
            }
        }
    }
    
    for (int i = 0; i < q; ++i) {
        int v, x;
        cin >> v >> x;

        int tmp = a[v];
        if (tmp == x) {
            cout << res << ln;
            continue;
        }

        ll delta = 0;
        
        if (vec[v]) {
            ll tmp2 = vec2[v][tmp];
            ll tmp3 = vec2[v][x];
            delta = tmp2 - tmp3;
        }
        else {
            ll tmp2 = 0, tmp3 = 0;

            for (auto [j, k] : adj[v]) {
                int cu = a[j];
                if (cu == tmp) tmp2 += k;
                if (cu == x) tmp3 += k;
            }

            delta = tmp2 - tmp3;
        }

        res += delta;
        cout << res << ln;

        a[v] = x;
        if (vec[v]) {
            for (auto [j, k] : vec3[v]) {
                vec2[j][tmp] -= k;
                vec2[j][x] += k;
            }
        } 
        else {
            for (auto [j, k] : adj[v]) {
                if (vec[j]) {
                    vec2[j][tmp] -= k;
                    vec2[j][x] += k;
                }
            }
        }
    }
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