// Author: huythedev (https://huythedev.com)
// Problem Link: https://marisaoj.com/problem/593

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

vector<bool> globalVisited;
queue<pair<int, int>> globalQueue;

void colorByDistance(vector<vector<int>>& graph, vector<int>& colors, int u, int d, int c) {
    if (d == 0) {
        colors[u] = c;
        return;
    }
    
    fill(globalVisited.begin(), globalVisited.end(), false);
    
    while (!globalQueue.empty()) globalQueue.pop();
    
    globalQueue.push({u, 0});
    globalVisited[u] = true;
    colors[u] = c;
    
    while (!globalQueue.empty()) {
        int vertex = globalQueue.front().first;
        int dist = globalQueue.front().second;
        globalQueue.pop();
        
        if (dist >= d) continue; 
        
        for (int neighbor : graph[vertex]) {
            if (!globalVisited[neighbor]) {
                globalVisited[neighbor] = true;
                colors[neighbor] = c;
                globalQueue.push({neighbor, dist + 1});
            }
        }
    }
}

signed main() {
    fastio();
    docfile();

    int n, m, q;
    cin >> n >> m;
    
    vector<vector<int>> graph(n + 1);
    vector<int> colors(n + 1, 0);
    
    globalVisited.resize(n + 1);
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    cin >> q;
    for (int i = 0; i < q; i++) {
        int u, d, c;
        cin >> u >> d >> c;
        colorByDistance(graph, colors, u, d, c);
    }
    
    for (int i = 1; i <= n; i++) {
        cout << colors[i] << ln;
    }

    time();
    return 0;
}