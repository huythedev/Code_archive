// Author: huythedev
// Problem Link: https://codeforces.com/contest/2113/problem/A
#include <bits/stdc++.h>
using namespace std;

#define NAME "A"
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

void solve() {
    ll k, a, b, x, y; cin >> k >> a >> b >> x >> y;

    ll total = 0;
    if (x <= y) {
        ll n1 = (k >= a) ? ((k - a) / x + 1) : 0;
        ll tmp = k - n1 * x;
        ll n2 = (tmp >= b) ? ((tmp - b) / y + 1) : 0;
        total = n1 + n2;
    } else {
        ll n2 = (k >= b) ? ((k - b) / y + 1) : 0;
        ll tmp = k - n2 * y;
        ll n1 = (tmp >= a) ? ((tmp - a) / x + 1) : 0;
        total = n2 + n1;
    }

    cout << total << ln;
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