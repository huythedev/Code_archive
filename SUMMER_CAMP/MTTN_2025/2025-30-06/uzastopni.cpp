// Author: huythedev
// Problem link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "uzastopni"
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
    if (ifstream(NAME ".inp")) {
        freopen(NAME ".inp", "r", stdin);
        freopen(NAME ".out", "w", stdout);
    }
}

void time() {
    cerr << ln << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." 
         << ln;
}

const int MAXN = 70005;
const int MAXM = 2005;

vector<int> adj[MAXN];
int v[MAXN];
bool eligible[MAXN];
int task_count[MAXM];
int n, m;

vector<pair<int, int>> dp_work[MAXN];
vector<pair<int, int>> dp_pass[MAXN];

void pre_dfs(int u, int p) {
    if (task_count[v[u]] == 0) {
        eligible[u] = true;
    } else {
        eligible[u] = false;
    }
    task_count[v[u]]++;
    for (int c : adj[u]) {
        if (c != p) {
            pre_dfs(c, u);
        }
    }
    task_count[v[u]]--;
}

void dfs(int u, int p) {
    for (int c : adj[u]) {
        if (c != p) {
            dfs(c, u);
        }
    }

    dp_pass[u].clear();
    for (int c : adj[u]) {
        if (c != p) {
            dp_pass[u].insert(dp_pass[u].end(), dp_work[c].begin(), dp_work[c].end());
            dp_pass[u].insert(dp_pass[u].end(), dp_pass[c].begin(), dp_pass[c].end());
        }
    }
    if (!dp_pass[u].empty()){
        sort(dp_pass[u].begin(), dp_pass[u].end());
        dp_pass[u].erase(unique(dp_pass[u].begin(), dp_pass[u].end()), dp_pass[u].end());
    }

    dp_work[u].clear();
    if (!eligible[u]) {
        return;
    }

    bitset<MAXM> possible_L, possible_R;
    possible_L[v[u]] = 1;
    possible_R[v[u]] = 1;

    for (int c : adj[u]) {
        if (c == p) continue;
        
        vector<pair<int, int>> child_offers = dp_work[c];
        child_offers.insert(child_offers.end(), dp_pass[c].begin(), dp_pass[c].end());
        if (child_offers.empty()) continue;
        
        sort(child_offers.begin(), child_offers.end());
        child_offers.erase(unique(child_offers.begin(), child_offers.end()), child_offers.end());
        
        bitset<MAXM> next_L = possible_L;
        bitset<MAXM> next_R = possible_R;

        for (const auto& offer : child_offers) {
            int cl = offer.first;
            int cr = offer.second;
            if (cr < v[u]) {
                if (cr + 1 > 0 && cr + 1 < MAXM && possible_L[cr + 1]) {
                    next_L[cl] = 1;
                }
            } else if (cl > v[u]) {
                if (cl - 1 > 0 && cl - 1 < MAXM && possible_R[cl - 1]) {
                    next_R[cr] = 1;
                }
            }
        }
        possible_L = next_L;
        possible_R = next_R;
    }

    for (int i = 1; i <= m; i++) {
        if (possible_L[i]) {
            for (int j = 1; j <= m; j++) {
                if (possible_R[j]) {
                    dp_work[u].push_back({i, j});
                }
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    
    for (int i = 1; i <= n; ++i) {
        adj[i].clear();
    }

    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    fill(task_count, task_count + m + 1, 0);
    pre_dfs(1, 0);
    dfs(1, 0);
    
    cout << dp_work[1].size() << ln;
}

int main() {
    fastio();
    docfile();

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    time();
    return 0;
}