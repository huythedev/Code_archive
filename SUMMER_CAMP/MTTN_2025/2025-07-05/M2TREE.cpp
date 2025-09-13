// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "M2TREE"
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

const int maxn = 100000;
int parent[maxn+5], siz[maxn+5];
int diffv[maxn+5], addv[maxn+5];
bool active[maxn+5];
vector<int> adj[maxn+5];
int a[maxn+5];
int ans[maxn+5];

int findp(int x) {
    if (parent[x] == x) return x;
    int p = parent[x];
    int r = findp(p);
    diffv[x] += diffv[p];
    return parent[x] = r;
}

void unite(int u, int v, int w) {
    int ru = findp(u);
    int rv = findp(v);
    if (ru == rv) return;
    long long su = siz[ru];
    long long sv = siz[rv];
    addv[ru] += w * sv;
    addv[rv] += w * su;
    if (siz[ru] < siz[rv]) {
        parent[ru] = rv;
        diffv[ru] = addv[ru] - addv[rv];
        siz[rv] += siz[ru];
    } else {
        parent[rv] = ru;
        diffv[rv] = addv[rv] - addv[ru];
        siz[ru] += siz[rv];
    }
}

void solve() {
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        adj[i].push_back(p);
        adj[p].push_back(i);
    }
    for (int i = 1; i <= n; i++) cin >> a[i];
    
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        siz[i] = 1;
        diffv[i] = 0;
        addv[i] = 0;
        active[i] = false;
    }
    
    vector<pair<int, int>> ord;
    ord.reserve(n);
    for (int i = 1; i <= n; i++) ord.emplace_back(a[i], i);
    sort(ord.rbegin(), ord.rend());
    
    for (auto &pr : ord) {
        int w = pr.first;
        int u = pr.second;
        active[u] = true;
        for (int v : adj[u]) {
            if (active[v]) {
                unite(u, v, w);
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        int r = findp(i);
        ans[i] = addv[r] + diffv[i] + a[i];
    }
    
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
}

signed main() {
    docfile();
    fastio();

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    time();
    return 0;
}
