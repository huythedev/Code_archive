// Author: huythedev (https://huythedev.com)
// Problem Link: 

#include <bits/stdc++.h>
using namespace std;

#define NAME "ZONING"
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

const int MAXN = 1e5 + 5;
vector<int> adj[MAXN];
int n, m;

vector<int> core_decomposition() {
    vector<int> degree(n + 1);
    for (int u = 1; u <= n; ++u) {
        degree[u] = adj[u].size();
    }

    int max_degree = *max_element(degree.begin() + 1, degree.end());
    vector<list<int>> bins(max_degree + 1);
    vector<list<int>::iterator> ptr(n + 1);

    for (int u = 1; u <= n; ++u) {
        int d = degree[u];
        if (d > max_degree) continue;
        bins[d].push_front(u);
        ptr[u] = bins[d].begin();
    }

    vector<int> core(n + 1);
    vector<bool> processed(n + 1, false);

    for (int d = 0; d <= max_degree; ++d) {
        while (!bins[d].empty()) {
            int u = bins[d].front();
            bins[d].pop_front();
            if (processed[u]) continue;
            processed[u] = true;
            core[u] = d;

            for (int v : adj[u]) {
                if (!processed[v] && degree[v] > d) {
                    int current_degree = degree[v];
                    degree[v]--;
                    if (current_degree - 1 >= 0) {
                        bins[current_degree].erase(ptr[v]);
                        if (current_degree - 1 > max_degree) {
                            max_degree = current_degree - 1;
                            bins.resize(max_degree + 1);
                        }
                        bins[current_degree - 1].push_front(v);
                        ptr[v] = bins[current_degree - 1].begin();
                    }
                }
            }
        }
    }

    return core;
}

struct DSU {
    vector<int> parent, size;
    DSU(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 1; i <= n; ++i)
            parent[i] = i;
    }
    int find(int u) {
        if (parent[u] != u)
            parent[u] = find(parent[u]);
        return parent[u];
    }
    void unite(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return;
        if (size[u] < size[v]) swap(u, v);
        parent[v] = u;
        size[u] += size[v];
    }
    int get_size(int u) {
        return size[find(u)];
    }
};

int main() {
    fastio();
    docfile();

    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> core = core_decomposition();

    vector<int> order(n);
    iota(order.begin(), order.end(), 1);
    sort(order.begin(), order.end(), [&](int a, int b) {
        return core[a] > core[b];
    });

    DSU dsu(n);
    vector<bool> processed(n + 1, false);
    int res = 0;

    for (int u : order) {
        processed[u] = true;
        for (int v : adj[u]) {
            if (processed[v]) {
                dsu.unite(u, v);
            }
        }
        int current_core = core[u];
        int component_size = dsu.get_size(u);
        res = max(res, current_core * component_size);
    }

    cout << res;

    time();
    return 0;
}