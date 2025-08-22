#include <bits/stdc++.h>
using namespace std;

#define NAME "E"
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

const int maxn = 2e5 + 10;
vector<int> adj[maxn];
int n, k;
ll w[maxn], c[maxn];
map<int, int> freq[maxn];
int choice[maxn];
ll min_cost[maxn];

void dfs(int u, int p) {
    freq[u].clear();
    
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        
        for (auto [col, tmp] : freq[v]) {
            freq[u][col] += tmp;
        }
    }
    
    if (c[u] != 0) {
        freq[u][c[u]]++;
        choice[u] = c[u];
        
        bool is_cutie = false;
        for (auto [col, tmp] : freq[u]) {
            if (col != c[u] && tmp >= 2) {
                is_cutie = true;
                break;
            }
        }
        min_cost[u] = is_cutie ? w[u] : 0;
    } 
    else {
        ll best_cost = LLONG_MAX;
        int best_color = 1;
        
        for (int col = 1; col <= k; col++) {
            map<int, int> freq2 = freq[u];
            freq2[col]++;
            
            bool is_cutie = false;
            for (auto [c, tmp] : freq2) {
                if (c != col && tmp >= 2) {
                    is_cutie = true;
                    break;
                }
            }

            ll cost = is_cutie ? w[u] : 0;
            
            if (cost < best_cost) {
                best_cost = cost;
                best_color = col;
            }
        }
        
        freq[u][best_color]++;
        choice[u] = best_color;
        min_cost[u] = best_cost;
    }
    
    for (int v : adj[u]) {
        if (v != p) {
            min_cost[u] += min_cost[v];
        }
    }
}

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        min_cost[i] = 0;
    }
    
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
    }
    
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    dfs(1, -1);
    
    cout << min_cost[1] << ln;
    
    for (int i = 1; i <= n; i++) {
        cout << choice[i] << ' ';
    }
    cout << ln;
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