// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "binary"
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

bool cnt(ll n, int k) {
    if (k == 0) 
        return true;

    if (n == 0 && k > 0) 
        return false;

    int res = 0;
    for (int i = 0; i < 64; ++i) {
        if ((n >> i) & 1)
            res++;
        else 
            res = 0;
        
        if (res >= k)
            return true;
    }
    return false;
}

void solve() {
    ll n, res = LLONG_MAX;
    int k; cin >> n >> k;

    if (cnt(n, k)) {
        cout << n << ln;
        return;
    }

    for (int i = 0; i <= 63 - k; ++i) {
        ll mask = ((1LL << k) - 1) << i;
        ll tmp = (i + k >= 63) ? 0 : ~((1LL << (i + k)) - 1);
        ll tmp2 = n & tmp;
        ll candidate1 = tmp2 | mask;

        if (candidate1 >= n)
            res = min(res, candidate1);
        else {
            if (i + k < 64) {
                ll candidate2 = (tmp2 + (1LL << (i + k))) | mask;
                res = min(res, candidate2);
            }
        }
    }

    cout << res << ln;
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