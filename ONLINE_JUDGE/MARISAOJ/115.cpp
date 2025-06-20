// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "115"
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

vector<vector<int>> vec(MAXN);
vector<bool> vis(MAXN);
int n, m;

void dfs(int i) {
    vis[i] = true;
    for (int x : vec[i]) {
        if (!vis[x]) dfs(x);
    }
}

void solve() {
    cin >> n >> m;
    vec.resize(n);
    for (int i = 0; i < m; ++i) {
        int x, y; cin >> x >> y;
        vec[x].push_back(y);
        vec[y].push_back(x);
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            ++ans;
            dfs(i);
        }
    }

    cout << ans << ln;
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