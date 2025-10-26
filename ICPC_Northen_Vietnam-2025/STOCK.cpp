// Author: NBK.VaiLatXucXich
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "NAME"
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

ll multi(ll a, ll b, ll m) {
    return ((a % m) * (b % m)) % m;
}

ll modpow(ll a, ll e, ll m) {
    if (m == 1) return 0;
    a %= m;
    ll res = 1 % m;
    while (e > 0) {
        if (e & 1) res = multi(res, a, m);
        a = multi(a, a, m);
        e >>= 1;
    }
    return res;
}

void solve() {
    ll n, k, m, p; 
    cin >> n >> k >> m >> p;

    if (p == 1) { 
        cout << 0 << ln;
        return;
    }

    if (k == 1) {
        cout << (n % p) << ln;
        return;
    }

    ll gaps = k - 1;

    ll mm1 = modpow(m % p, gaps - 1, p);
    ll mm2 = multi(mm1, m % p, p);

    ll term1 = multi(n % p, mm2, p);

    ll sum = ((m * (m + 1)) / 2) % p;
    ll term2 = multi((gaps % p), mm1, p);
    term2 = multi(term2, sum, p);

    ll ans = term1 - term2;
    if (ans < 0) 
        ans += p;

    cout << ans % p << ln;
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