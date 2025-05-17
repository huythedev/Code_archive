// Author: huythedev
// Problem Link: https://codeforces.com/contest/2109/problem/B
#include <bits/stdc++.h>
using namespace std;

#define NAME "B"
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

ll calc(ll k) {
    if (k <= 1) return 0;
    return (sizeof(long long) * 8) - __builtin_clzll(k - 1);
}

void solve() {
    ll n, m, a, b;
    cin >> n >> m >> a >> b;

    if (n == 1 && m == 1) {
        cout << 0 << ln;
        return;
    }

    if (n == 1) {
        cout << calc(m) << ln;
        return;
    }

    if (m == 1) {
        cout << calc(n) << ln;
        return;
    }

    ll afterH_dim = min(a, n - a + 1);
    int costH = 1 + calc(afterH_dim) + calc(m);

    ll afterV_dim = min(b, m - b + 1);
    int costV = 1 + calc(n) + calc(afterV_dim);
    
    cout << min(costH, costV) << ln;
}

signed main() {
    fastio();
    docfile();

    int t; cin >> t;
    while (t--) {
        solve();
    }

    time();
    return 0;
}