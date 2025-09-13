// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "LTHI"
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

const int MOD = 1e9 + 7;

ll powMod(ll a, ll e) {
    ll r = 1 % MOD;
    a %= MOD;
    while (e) {
        if (e & 1) r = (r * a) % MOD;
        a = (a * a) % MOD;
        e >>= 1;
    }
    return r;
}

vector<ll> fact, invfact;

ll nCk(ll N, ll K) {
    if (K < 0 || K > N) return 0LL;
    return (((fact[N] * invfact[K]) % MOD) * invfact[N - K]) % MOD;
}

void solve() {
    ll n, k;
    cin >> n >> k;

    fact.assign(n + 1, 1);
    invfact.assign(n + 1, 1);
    for (ll i = 1; i <= n; ++i) 
        fact[i] = (fact[i - 1] * (i % MOD)) % MOD;

    invfact[n] = powMod(fact[n], MOD - 2);
    for (ll i = n; i >= 1; --i) 
        invfact[i - 1] = (invfact[i] * (i % MOD)) % MOD;

    vector<ll> D(n + 1, 0);
    D[0] = 1;
    if (n >= 1) 
        D[1] = 0;

    for (ll i = 2; i <= n; ++i) {
        ll s = D[i - 1] + D[i - 2];

        if (s >= MOD) 
            s -= MOD;

        D[i] = (( (i - 1) % MOD ) * s) % MOD;
    }

    ll ans = (nCk(n, k) * D[n - k]) % MOD;
    
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