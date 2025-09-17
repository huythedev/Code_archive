// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "PENGU"
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
    cerr << ln << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." 
         << ln;
}

class Fenwick {
    vector<ll> tree;
    int n;
public:
    Fenwick(int _n) {
        n = _n;
        tree.assign(n + 1, 0);
    }
    void update(int idx, ll val) {
        while (idx <= n) {
            tree[idx] += val;
            idx += idx & -idx;
        }
    }
    ll query(int idx) {
        ll sum = 0;
        while (idx > 0) {
            sum += tree[idx];
            idx -= idx & -idx;
        }
        return sum;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<ll> H(n);
    for (auto &x : H) cin >> x;

    vector<ll> vals = H;
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());

    int m = vals.size();
    vector<int> rank(n);
    for (int i = 0; i < n; i++)
        rank[i] = lower_bound(vals.begin(), vals.end(), H[i]) - vals.begin() + 1;
    
    vector<ll> lCnt(n, 0);
    Fenwick left(m + 1);
    for (int i = 0; i < n; i++) {
        if (i > 0)
            lCnt[i] = left.query(rank[i] - 1);
        left.update(rank[i], 1);
    }

    vector<ll> rCnt(n, 0);
    Fenwick right(m + 1);
    for (int i = n - 1; i >= 0; i--) {
        if (i < n - 1)
            rCnt[i] = right.query(rank[i] - 1);
        right.update(rank[i], 1);
    }
    
    ll res = 0;
    for (int y = 1; y < n - 1; y++)
        res += lCnt[y] * rCnt[y];
    
    cout << res << ln;
}

signed main() {
    fastIO();
    fileIO();

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    time();
    return 0;
}