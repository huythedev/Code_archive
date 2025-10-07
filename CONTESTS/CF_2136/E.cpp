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


const ll MOD = 998244353;

ll powmod(ll a, ll e){
    ll r = 1 % MOD;
    a %= MOD;
    while (e) {
        if (e & 1) r = (r * a) % MOD;
        a = (a * a) % MOD;
        e >>= 1;
    }
    return r;
}

struct sus {
    int u, p, pe, it;
};

void solve() {
    int n, m, V;
    cin >> n >> m >> V;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) 
        cin >> a[i];

    vector<pair<int, int>> edges(m);
    vector<vector<pair<int,int>>> adj(n + 1);
    adj.reserve(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        edges[i] = {u, v};
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }

    vector<int> vec(n + 1, 0), low(n + 1, 0);
    vector<char> isBridge(m,false);
    ll tmp = 0;
    vector<sus> st;
    st.reserve(n);
    for (int s = 1; s <= n; s++) {
        if (vec[s]) 
            continue;

        st.push_back({s, -1, -1, 0});
        vec[s] = low[s] = ++tmp;

        while (!st.empty()) {
            sus &curr = st.back();
            int u = curr.u;
            
            if (curr.it < (int)adj[u].size()) {
                auto [v, eid] = adj[u][curr.it++];

                if (!vec[v]) {
                    st.push_back({v, u, eid, 0});
                    vec[v] = low[v] = ++tmp;
                }
                else if (eid != curr.pe) {
                    low[u] = min(low[u], vec[v]);
                }
            } 
            else {
                int p = curr.p;
                st.pop_back();

                if (p != -1) {
                    low[p] = min(low[p], low[u]);
                    if (low[u] > vec[p]) 
                        isBridge[curr.pe] = true;
                }
            }
        }
    }

    vector<vector<int>> adj2(n + 1);
    vector<bool> vec2(n + 1, false);
    for (int i = 0; i < m; i++) {
        if (!isBridge[i]) {
            int u = edges[i].first, v = edges[i].second;

            adj2[u].push_back(v);
            adj2[v].push_back(u);

            vec2[u] = vec2[v] = true;
        }
    }

    vector<int> color(n + 1, -1);
    ll ans = 1;
    bool ok = true;
    queue<int> q;
    for (int i = 1; i <= n && ok; i++) {
        if (!vec2[i] || color[i] != -1) 
            continue;

        bool bip = true;
        tmp = -1;
        bool fix = false;

        color[i] = 0;
        q.push(i);
        while (!q.empty() && ok) {
            int u = q.front(); q.pop();

            if (a[u] != -1) {
                if (!fix) {
                    fix = true;
                    tmp = a[u];
                } 
                else if (a[u] != tmp) {
                    ok = false;
                    break;
                }
            }

            for (int v : adj2[u]) {
                if (color[v] == -1) {
                    color[v] = color[u] ^ 1;
                    q.push(v);
                } 
                else if (color[v] == color[u]) {
                    bip = false;
                }
            }
        }

        if (!ok) 
            break;

        if (!bip) {
            if (fix && tmp != 0) {
                ok = false;
                break;
            }
        } 
        else {
            if (!fix) {
                ans = (ans * (V % MOD)) % MOD;
            }
        }
    }

    if (!ok){
        cout << 0 << ln;
        return;
    }

    tmp = 0;
    for (int i = 1; i <= n; i++)
        if (!vec2[i] && a[i] == -1) 
            tmp++;

    ans = (ans * powmod(V, tmp)) % MOD;

    cout << ans << ln;
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