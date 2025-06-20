#include <bits/stdc++.h>
using namespace std;

#define NAME "E"
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

ll power(ll a, ll b, ll mod) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

void solve() {
    int n, k;
    cin >> n >> k;
    assert(k == 1);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int m = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 1) m++;
    }
    
    vector<ll> fact(n + 1), invfact(n + 1);
    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }
    invfact[n] = power(fact[n], MOD - 2, MOD);
    for (int i = n - 1; i >= 0; i--) {
        invfact[i] = invfact[i + 1] * (i + 1) % MOD;
    }
    
    auto C = [&](int a, int b) -> ll {
        if (b < 0 || b > a) return 0;
        return fact[a] * invfact[b] % MOD * invfact[a - b] % MOD;
    };
    
    ll res = 0;
    for (int j = 1; j <= min(n, m); j++) {
        ll ways = C(m, j) * fact[j] % MOD * fact[n - j] % MOD;
        res = (res + ways) % MOD;
    }
    
    cout << res << ln;
}

signed main() {
    docfile();
    fastio();
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    time();
    return 0;
}