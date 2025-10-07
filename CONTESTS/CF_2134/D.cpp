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

pair<int, vector<int>> bfs(int start, vector<vector<int>> adj) {
    int n = (int)adj.size() - 1;

    vector<int> dist(n + 1, -1), parent(n + 1, -1);
    queue<int> q;

    dist[start] = 0;
    q.push(start);
    int far = start;

    while (!q.empty()) {
        int u = q.front(); 
        q.pop();

        if (dist[u] > dist[far]) 
            far = u;
        
        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                parent[v] = u;
                q.push(v);
            }
        }
    }

    return {far, parent};
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    vector<int> degree(n + 1, 0);
    for (int i = 0; i < n - 1; ++i) {
        int u, v; 
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        ++degree[u];
        ++degree[v];
    }

    if (n <= 2) {
        cout << "-1" << ln;
        return;
    }

    bool isPath = true;
    for (int i = 1; i <= n; ++i) {
        if (degree[i] > 2) {
            isPath = false;
            break;
        }
    }

    if (isPath) {
        cout << "-1" << ln;
        return;
    }

    int s = bfs(1, adj).first;
    auto [t, parent] = bfs(s, adj);

    vector<int> path;
    for (int curr = t; curr != -1; curr = parent[curr]) 
        path.push_back(curr);

    reverse(path.begin(), path.end());

    vector<char> vec(n + 1, 0);
    for (int v : path) 
        vec[v] = 1;

    int a = -1, b = -1, c = -1;
    int m = (int)path.size();
    for (int i = 0; i < m; ++i) {
        int u = path[i];

        for (int v : adj[u])  {
            if (!vec[v]) {
                b = u; c = v;

                if (i > 0) 
                    a = path[i - 1];
                else 
                    a = path[i + 1];
                
                break;
            }
        }

        if (b != -1)
            break;
    }

    if (b == -1) 
        cout << -1 << ln;
    else 
        cout << a << " " << b << " " << c << ln;
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