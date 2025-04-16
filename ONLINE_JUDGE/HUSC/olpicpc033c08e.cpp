// Author: huythedev (https://huythedev.com)
// Problem Link: https://coder.husc.edu.vn/problem/olpicpc033c08e
// davul
#include <bits/stdc++.h>
using namespace std;

#define NAME "olpicpc033c08e"
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

int main() {
    fastio();
    docfile();

    int N, M;
    cin >> N >> M;
    
    vector<vector<int>> adj(N + 1);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    int Q;
    cin >> Q;
    
    vector<tuple<int, int, int>> ops(Q);
    for (int i = 0; i < Q; i++) {
        int V, D, C;
        cin >> V >> D >> C;
        ops[i] = make_tuple(V, D, C);
    }
    
    vector<int> color(N + 1, 0);
    vector<int> last_update(N + 1, -1);
    int version = 0;
    
    for (int i = Q - 1; i >= 0; i--) {
        version++;
        int V, D, C;
        tie(V, D, C) = ops[i];
        
        queue<pair<int, int>> q;
        q.push({V, 0});
        vector<bool> visited(N + 1, false);
        visited[V] = true;
        
        while (!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            int u = p.first;
            int d = p.second;
            if (d > D) continue;
            if (last_update[u] < version) {
                last_update[u] = version;
                if (color[u] == 0) color[u] = C;
            }
            for (int v : adj[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    q.push({v, d + 1});
                }
            }
        }
    }
    
    for (int i = 1; i <= N; i++) {
        cout << color[i] << ln;
    }

    time();
    return 0;
}