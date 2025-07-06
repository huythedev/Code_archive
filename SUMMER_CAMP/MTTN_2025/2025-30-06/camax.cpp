// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "camax"
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

const int MOD = 998244353;

ll power(ll base, ll exp) {
    ll res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

void solve() {
    int sub; cin >> sub;

    int n, k; cin >> n >> k;

    vector<ll> a(n);
    ll sus = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] <= k) {
            sus++;
        }
    }

    ll cnt = 0, len = 0;

    for (int i = 0; i < n; ++i) {
        if (a[i] <= k)
            len++;
        else {
            if (len > 0) {
                ll tmp = (len * (len + 1) / 2) % MOD;
                cnt = (cnt + tmp) % MOD;
            }
            len = 0;
        }
    }

    if (len > 0) {
        ll tmp = (len * (len + 1) / 2) % MOD;
        cnt = (cnt + tmp) % MOD;
    }

    ll cnt2 = (power(2, sus) - 1 + MOD) % MOD;

    cout << cnt << " " << cnt2 << ln;
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
