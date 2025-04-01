// Author: Perry (https://perrythedev.com)
// Problem Link: https://coder.husc.edu.vn/problem/olpicpc043c10e
// davul
#include <bits/stdc++.h>
using namespace std;

#define NAME "olpicpc043c10e"
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

void mem() {
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);
    ld mem_used = usage.ru_maxrss;
    if (mem_used < 1024.0) {
        cerr << ln << "Memory used: " << mem_used << " KB." << ln;
    }
    else if (mem_used >= (ld)1024.0 && mem_used < (1024.0 * 1024.0)) {
        cerr << ln << "Memory used: " << mem_used / 1024.0 << " MB." << ln;
    }
    else {
        cerr << "Memory used: " << (mem_used / 1024.0) / 1024.0 << " GB." << ln << "----------" << ln;
    }
}

const int MAXN = 1e5 + 10;
const int LOGN = 18;

vector<int> adj[MAXN];
int parent[MAXN][LOGN], level[MAXN];
bool visited[MAXN];
vector<pair<int, int> > nonTreeEdges;
vector<vector<int> > dist; 
unordered_map<int, int> node_to_idx;

void bfs(int start, vector<int>& d) {
    queue<int> q;
    d.assign(MAXN, -1);
    d[start] = 0;
    q.push(start);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (d[v] == -1) {
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }
}

void buildSpanningTree(int start) {
    queue<int> q;
    fill(visited, visited + MAXN, false);
    q.push(start);
    visited[start] = true;
    level[start] = 0;
    parent[start][0] = start;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                level[v] = level[u] + 1;
                parent[v][0] = u;
                q.push(v);
            } else if (v != parent[u][0]) {
                nonTreeEdges.emplace_back(u, v);
            }
        }
    }
}

void preprocessLCA(int n) {
    for (int k = 1; k < LOGN; k++) {
        for (int i = 1; i <= n; i++) {
            if (parent[i][k-1] != -1)
                parent[i][k] = parent[parent[i][k-1]][k-1];
            else
                parent[i][k] = -1;
        }
    }
}

int getLCA(int u, int v) {
    if (level[u] > level[v]) swap(u, v);
    int diff = level[v] - level[u];
    for (int k = 0; k < LOGN; k++)
        if (diff & (1 << k))
            v = parent[v][k];
    if (u == v) return u;
    for (int k = LOGN - 1; k >= 0; k--)
        if (parent[u][k] != parent[v][k]) {
            u = parent[u][k];
            v = parent[v][k];
        }
    return parent[u][0];
}

int distTree(int u, int v) {
    int lca = getLCA(u, v);
    return level[u] + level[v] - 2 * level[lca];
}

int main() {
    fastio();
    docfile();

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    buildSpanningTree(1);
    preprocessLCA(n);

    set<int> endpoints;
    for (pair<int, int> tmp : nonTreeEdges) {
        int a = tmp.first, b = tmp.second;
        endpoints.insert(a);
        endpoints.insert(b);
    }
    vector<int> endpoints_list(endpoints.begin(), endpoints.end());
    dist.resize(endpoints_list.size());
    for (int i = 0; i < (int)endpoints_list.size(); i++) {
        node_to_idx[endpoints_list[i]] = i;
        dist[i].resize(n + 1);
        bfs(endpoints_list[i], dist[i]);
    }

    int q;
    cin >> q;
    while (q--) {
        int u, v;
        cin >> u >> v;
        int min_dist = distTree(u, v);
        for (pair<int, int> tmp : nonTreeEdges) {
            int a = tmp.first, b = tmp.second;
            int idx_a = node_to_idx[a], idx_b = node_to_idx[b];
            int cand1 = dist[idx_a][u] + 1 + dist[idx_b][v];
            int cand2 = dist[idx_b][u] + 1 + dist[idx_a][v];
            // min_dist = min({min_dist, cand1, cand2});
            min_dist = min(min(min_dist, cand1), cand2);
        }
        cout << min_dist << ln;
    }

    time();
    mem();
    return 0;
}