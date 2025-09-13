// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "TUPLE"
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

ll power(ll base, ll exp, ll mod) {
    ll res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

ll modInverse(ll n, ll mod) {
    return power(n, mod - 2, mod);
}

void solve() {
    int n; ll k;
    cin >> n >> k;

    ll M = 9 * k;

    vector<ll> vec(n + 1);
    for (int i = 1; i <= n; ++i) {
        vec[i] = (i * (power(10, n - i + 1, M) - 1 + M) % M) % M;
    }

    vector<ll> dp(M, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; ++i) {
        vector<ll> dp2(M, 0);
        int start = (i == 1) ? 1 : 0;
        int end = 7;
        
        for (ll j = 0; j < M; ++j) {
            if (dp[j] == 0) continue;
            for (int d = start; d <= end; ++d) {
                ll curr = (j + (ll)d * vec[i]) % M;
                dp2[curr] = (dp2[curr] + dp[j]) % MOD;
            }
        }
        dp = dp2;
    }

    vector<ll>& C = dp;

    ll totalA = 0;
    for (int i = 0; i < M; ++i) {
        if (C[i] == 0) continue;
        for (int j = 0; j < M; ++j) {
            if (C[j] == 0) continue;
            ll l = (M - (i + j) % M) % M;
            totalA = (totalA + (C[i] * C[j]) % MOD * C[l]) % MOD;
        }
    }
    
    ll cntC = 0;
    for (int r = 0; r < M; ++r) {
        if ((3LL * r) % M == 0) {
            cntC = (cntC + C[r]) % MOD;
        }
    }

    ll cntB = 0;
    for (int r = 0; r < M; ++r) {
        if (C[r] == 0) continue;
        ll target_r = (M - (2LL * r) % M) % M;
        cntB = (cntB + C[r] * C[target_r]) % MOD;
    }

    ll tmp = (totalA - (3 * cntB) % MOD + MOD) % MOD;
    tmp = (tmp + (2 * cntC) % MOD) % MOD;
    
    ll res = (tmp * modInverse(6, MOD)) % MOD;

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
