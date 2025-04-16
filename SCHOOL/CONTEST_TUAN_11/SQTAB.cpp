// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "SQTAB"
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

ll n, k;

ll cnt(ll x) {
    ll ans = 0;
    for (ll i = 1; i <= n; i++) {
        if (x - i * i <= 0) 
            break;
        ans += min((ll)sqrt(x - i * i), n);
    }
    return ans;
}

ll solve(ll l, ll r) {
    ll ans = 0;
    while (l <= r) {
        ll m = (l + r) >> 1;
        if (cnt(m) >= k) {
            ans = m;
            r = m - 1;
        }
        else 
            l = m + 1;
    }
    return ans;
}

signed main() {
    fastio();
    docfile();

    cin >> n >> k;

    cout << solve(2, 2 * n * n);

    time();
    return 0;
}