// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "stalingrad"
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

const int MAXN = 400005;
const int LOG = 19;

int n, q, cnt;
vector<int> adj[MAXN];
int sta[MAXN], fin[MAXN], node[MAXN], high[MAXN], par[MAXN][LOG + 1];
int root[MAXN], curLCK[MAXN];
set<int> blockedNodes[MAXN];
int tmp2, ans1, tmp;

void dfs(int u, int p, int r) {
    root[u] = r;
    sta[u] = ++cnt;
    node[cnt] = u;
    for (int v : adj[u]) {
        if (v != p) {
            par[v][0] = u;
            high[v] = high[u] + 1;
            dfs(v, u, r);
        }
    }
    fin[u] = cnt;
}

void prepare() {
    cnt = 0;
    sta[1] = ++cnt;
    for (int v : adj[1]) {
        par[v][0] = 1;
        high[v] = 1;
        dfs(v, 1, v);
    }
    fin[1] = cnt;
    
    for (int j = 1; j <= LOG; j++)
        for (int i = 1; i <= n; i++)
            par[i][j] = par[par[i][j - 1]][j - 1];
}

int lca(int u, int v) {
    if (high[u] < high[v]) swap(u, v);
    for (int i = LOG; i >= 0; i--)
        if (high[par[u][i]] >= high[v])
            u = par[u][i];
    if (u == v) return u;
    for (int i = LOG; i >= 0; i--)
        if (par[u][i] != par[v][i]) {
            u = par[u][i];
            v = par[v][i];
        }
    return par[u][0];
}

int subtreeSize(int u) {
    return u ? fin[u] - sta[u] + 1 : 0;
}

void change(int u, char type) {
    tmp2 += (type == '+') ? 1 : -1;
    int r = root[u];
    bool hasBefore = !blockedNodes[r].empty();
    
    if (type == '+') blockedNodes[r].insert(sta[u]);
    else blockedNodes[r].erase(sta[u]);
    
    bool hasAfter = !blockedNodes[r].empty();
    
    if (!hasBefore && hasAfter) ans1++;
    if (hasBefore && !hasAfter) ans1--;
    
    int oldLCK = curLCK[r];
    if (!hasAfter) curLCK[r] = 0;
    else {
        int low = *blockedNodes[r].begin();
        int high = *blockedNodes[r].rbegin();
        curLCK[r] = lca(node[low], node[high]);
    }
    
    tmp += subtreeSize(curLCK[r]) - subtreeSize(oldLCK);
    cout << ans1 << " " << tmp - tmp2 << ln;
}

void solve() {
    int subtask;
    cin >> subtask >> n >> q;
    
    vector<int> vec(n + 1);
    bool isChain = true;
    for (int i = 2; i <= n; i++) {
        cin >> vec[i];
        if (vec[i] != i - 1) isChain = false;
        adj[vec[i]].push_back(i);
        adj[i].push_back(vec[i]);
    }
    
    if (isChain) {
        set<int> st;
        while (q--) {
            char type; int v;
            cin >> type >> v;
            if (type == '+') st.insert(v);
            else st.erase(v);
            
            if (st.empty()) cout << "0 0" << ln;
            else {
                int min_v = *st.begin();
                ll cost = (ll)n - min_v + 1 - st.size();
                cout << 1 << " " << cost << ln;
            }
        }
        return;
    }
    
    prepare();
    
    while (q--) {
        char type; int v;
        cin >> type >> v;
        change(v, type);
    }
}

signed main() {
    docfile();
    fastio();

    solve();
    
    time();
    return 0;
}