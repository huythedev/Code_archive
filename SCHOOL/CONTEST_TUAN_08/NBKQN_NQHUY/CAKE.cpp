// Author: huythedev (https://huythedev.com)
// Problem Link: 

#include <bits/stdc++.h>
using namespace std;

#define NAME "CAKE"
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

const int maxn = 1e3 + 5, maxk = 2e3 + 5, maxp = 1e9 + 5;

int n, k, p;
vector<int> a(maxn), b(maxk);

bool isPossible(int T) {
    vector<vector<int>> graph(n);
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            int timeTaken = abs(a[i] - b[j]) + abs(b[j] - p);
            if (timeTaken <= T) {
                graph[i].push_back(j);
            }
        }
    }
    
    vector<int> match(k, -1);
    vector<bool> vis;
    
    function<bool(int)> dfs = [&](int u) -> bool {
        for (int v : graph[u]) {
            if (vis[v]) continue;
            vis[v] = true;
            if (match[v] == -1 || dfs(match[v])) {
                match[v] = u;
                return true;
            }
        }
        return false;
    };
    
    int matching = 0;
    for (int i = 0; i < n; ++i) {
        vis.assign(k, false);
        if (dfs(i)) matching++;
    }
    
    return matching == n;
}

signed main() {
    fastio();
    docfile();

    cin >> n >> k >> p;
    a.resize(n); b.resize(k);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < k; ++i) cin >> b[i];

    int l = 0, r = 2 * maxp; 
    while (l < r) {
        int mid = (l + r) / 2;
        if (isPossible(mid)) {
            r = mid;
        } 
        else {
            l = mid + 1;
        }
    }
    
    cout << l << ln;

    time();
    return 0;
}