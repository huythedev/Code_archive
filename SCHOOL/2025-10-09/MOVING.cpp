// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "MOVING"
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

static const ll INF = (ll)9e18;

vector<ll> dijkstra(int s, const vector<vector<pair<int, ll>>>& adj) {
    int N = (int)adj.size() - 1; // 1-indexed; we’ll have nodes 1..n and S = n+1
    vector<ll> dist(adj.size(), INF);
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
    dist[s] = 0;
    pq.push({0, s});
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d != dist[u]) continue;
        for (auto [v, w] : adj[u]) {
            ll nd = d + w;
            if (nd < dist[v]) {
                dist[v] = nd;
                pq.push({nd, v});
            }
        }
    }
    return dist;
}

void solve() {
    int n, m;
    cin >> n >> m;

    // Original and reverse graphs (1-indexed). We’ll also add S = n+1.
    vector<vector<pair<int, ll>>> g(n + 2), grev(n + 2);

    for (int i = 0; i < m; ++i) {
        int u, v; ll w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        grev[v].push_back({u, w}); // reversed edge
    }

    // 1) Dijkstra from 1 on original graph: D[x] = dist(1, x)
    vector<ll> D = dijkstra(1, g);

    // 2) Add super-source S with edges S->x (weight D[x]) on the REVERSED graph
    int S = n + 1;
    for (int x = 1; x <= n; ++x) {
        if (D[x] < INF / 2) {
            grev[S].push_back({x, D[x]});
        }
    }

    // 3) Dijkstra from S on reversed graph gives answers for all p
    vector<ll> Ans = dijkstra(S, grev);

    // Output answers for p = 2..n (print -1 if unreachable)
    for (int p = 2; p <= n; ++p) {
        if (Ans[p] >= INF / 2) cout << -1;
        else cout << Ans[p];
        if (p < n) cout << ' ';
    }
    cout << '\n';
}

signed main() {
    fastIO();
    fileIO();

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    time();
    return 0;
}