// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "NAME"
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

const ll MOD = 998244353;

ll powmod(ll b, ll e) {
    ll res = 1;
    while (e) {
        if (e & 1) res = res * b % MOD;
        b = b * b % MOD;
        e >>= 1;
    }
    return res;
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, ll>>> vec(m + 1);
    ll pref = 1;

    for (int i = 0; i < n; i++) {
        int l, r, p, q;
        cin >> l >> r >> p >> q;

        ll diff = (q - p + MOD) % MOD;
        ll tmp = (ll)p * powmod(diff, MOD - 2) % MOD;

        vec[r].emplace_back(l, tmp);
        pref = pref * diff % MOD * powmod(q, MOD - 2) % MOD;
    }

    vector<ll> dp(m + 1, 0);
    dp[0] = 1;

    for (int j = 1; j <= m; j++) {
        for (auto [x, y] : vec[j]) {
            int prev = x - 1;

            if (prev >= 0)
                dp[j] = (dp[j] + dp[prev] * y % MOD) % MOD;
        }
    }

    ll res = dp[m] * pref % MOD;
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