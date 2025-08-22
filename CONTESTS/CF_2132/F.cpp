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
    cerr << ln << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." << ln;
}

struct State {
    int d, eid, v;
    bool operator<(const State& o) const {
        if (d != o.d) return d > o.d;
        return eid > o.eid;
    }
};

vector<int> et, lt;
vector<bool> isBridge;
int cnt;

void dfs(int u, int parent, const vector<vector<pair<int, int>>>& adj) {
    ++cnt;
    et[u] = lt[u] = cnt;
    for (auto [v, id] : adj[u]) {
        if (id == parent) 
            continue;

        if (et[v]) {
            lt[u] = min(lt[u], et[v]);
        }
        else {
            dfs(v, id, adj);
            lt[u] = min(lt[u], lt[v]);

            if (lt[v] > et[u]) 
                isBridge[id] = true;
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> edges(m + 1);
    vector<vector<pair<int, int>>> adj(n + 1);

    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;

        edges[i] = {u, v};
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }

    int q; cin >> q;
    vector<int> days(q);
    for (int i = 0; i < q; ++i) 
        cin >> days[i];

    et.assign(n + 1, 0);
    lt.assign(n + 1, 0);
    isBridge.assign(m + 1, false);
    cnt = 0;

    dfs(1, -1, adj);

    for (int i = 1; i <= n; ++i)
        if (!et[i]) 
            dfs(i, -1, adj);

    vector<int> vec(n + 1, 0);
    cnt = 0;
    for (int i = 1; i <= n; ++i) {
        if (vec[i]) 
            continue;
        ++cnt;

        stack<int> st;
        st.push(i);

        vec[i] = cnt;
        while (!st.empty()) {
            int u = st.top();
            st.pop();
            for (auto [v, id] : adj[u]) {
                if (vec[v] == 0 && !isBridge[id]) {
                    vec[v] = cnt;
                    st.push(v);
                }
            }
        }
    }

    vector<vector<pair<int, int>>> tree(cnt + 1);
    for (int i = 1; i <= m; ++i) {
        if (isBridge[i]) {
            int u = vec[edges[i].first], v = vec[edges[i].second];
            tree[u].push_back({v, i});
            tree[v].push_back({u, i});
        }
    }

    if (vec[1] == vec[n]) {
        for (int i = 0; i < q; ++i) {
            cout << -1 << ' ';
        }
        cout << ln;
        return;
    }

    vector<int> parent(cnt + 1, -1), btp(cnt + 1, -1);
    queue<int> qu;
    qu.push(vec[1]);
    parent[vec[1]] = 0;

    while (!qu.empty()) {
        int u = qu.front();
        qu.pop();
        
        if (u == vec[n]) 
            break;

        for (auto [v, id] : tree[u]) {
            if (parent[v] == -1) {
                parent[v] = u;
                btp[v] = id;
                qu.push(v);
            }
        }
    }

    vector<char> vec2(m + 1, false);
    for (int v = vec[n]; v != vec[1]; v = parent[v]) {
        vec2[btp[v]] = true;
    }

    vector<int> dist(n + 1, 1e9), best(n + 1, INT_MAX);
    priority_queue<State> pq;

    for (int id = 1; id <= m; ++id) {
        if (vec2[id]) {
            auto [u, v] = edges[id];
            pq.push({0, id, u});
            pq.push({0, id, v});
        }
    }

    while (!pq.empty()) {
        auto curr = pq.top();
        pq.pop();

        int d = curr.d, eid = curr.eid, u = curr.v;

        if (d > dist[u])
            continue;
        if (d == dist[u] && eid >= best[u])
            continue;

        dist[u] = d;
        best[u] = eid;

        for (auto [to, id] : adj[u])
            pq.push({d + 1, eid, to});
    }

    for (int i = 0; i < q; ++i) {
        if (best[days[i]] == INT_MAX)
            cout << -1 << ' ';
        else
            cout << best[days[i]] << ' ';
    }

    cout << ln;
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