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

const ll MOD = 1e9 + 7;

void add(ll &a, ll b) {
    a = (a + (b % MOD)) % MOD;
}

ll bitlen(ll v) {
    if (v == 0) 
        return 0;
    return 64 - __builtin_clzll(v);
}

void solve() {
    ll n, k, x;
    cin >> n >> k >> x;

    ll S = 1LL * k * (k + 1) / 2;

    vector<ll> f(S + 1, 0);
    f[0] = 1;
    for (ll i = 1; i <= k; ++i) {
        for (ll j = S; j >= i; --j) {
            f[j] += f[j - i];
            if (f[j] >= MOD) 
                f[j] -= MOD;
        }
    }

    vector<ll> vec(S + 2, 0);
    for (ll i = 0; i <= S + 1; ++i) {
        ll val = 0;
        if (i <= S) 
            val += f[i];
        
        if (i - 1 >= 0 && i - 1 <= S) 
            val += f[i - 1];
        
        if (i == S) 
            val -= 1;
        
        if (i == S + 1) 
            val -= 1;
        
        val %= MOD;
        if (val < 0) 
            val += MOD;
        
        vec[i] = val;
    }

    vector<vector<vector<pair<ll,ll>>>> vec2(2, vector<vector<pair<ll,ll>>>(2));
    for (ll bit = 0; bit <= 1; ++bit) {
        for (ll i = 0; i <= 1; ++i) {
            auto &lst = vec2[bit][i];

            for (ll j = 0; j <= S + 1; ++j) {
                if ((j & 1) == (bit ^ i)) {
                    ll cnt = vec[j];

                    if (cnt == 0) 
                        continue;

                    ll delta = (j + i - bit) >> 1;
                    lst.push_back({delta, cnt});
                }
            }
        }
    }

    ll C = S + 1;
    vector<ll> dp(C + 1, 0), dp2(C + 1, 0);
    dp[0] = 1;

    for (ll bit = 0; bit < max(bitlen(n), bitlen(x)) + 20; ++bit) {
        ll xbit = ((x >> bit) & 1LL);
        ll nbit = ((n >> bit) & 1LL);

        fill(dp2.begin(), dp2.end(), 0);

        if (xbit == 1) {
            for (ll i = 0; i <= C; ++i) {
                if (dp[i] == 0) 
                    continue;
                
                ll r = (i & 1);
                ll q = (i >> 1);
                ll w = ((S & 1) == (nbit ^ r)) ? S : (S + 1);
                ll delta = (w + r - nbit) >> 1;
                ll c2 = q + delta;

                add(dp2[c2], dp[i]);
            }
        } 
        else {
            for (ll i = 0; i <= C; ++i) {
                ll val = dp[i];
                if (!val) 
                    continue;
                
                ll r = (i & 1);
                ll q = (i >> 1);
                
                auto &tmp = vec2[nbit][r];
                for (auto [delta, cnt] : tmp) {
                    ll c2 = q + delta;
                    add(dp2[c2], 1LL * val * cnt);
                }
            }
        }

        dp.swap(dp2);
    }

    cout << dp[0] % MOD << ln;
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