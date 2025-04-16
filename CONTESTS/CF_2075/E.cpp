// Author: huythedev (https://huythedev.com)
// Problem Link: https://codeforces.com/contest/2075/problem/E
// davul
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

const ll MOD = 998244353;

ll pow_mod(ll base, ll exp) {
    ll res = 1 % MOD;
    base %= MOD;
    while (exp > 0) {
        if (exp & 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return res;
}

ll calc(ll A, ll B) {
    int a = 0, b = 0;
    for (ll i = A; i > 0; i /= 2) a++;
    for (ll i = B; i > 0; i /= 2) b++;
    a = max(a, 1);
    b = max(b, 1);

    int tmp = max(a, b);
    vector<int> vec1(tmp, 0), vec2(tmp, 0);
    for (int i = 0; i < tmp; i++) {
        vec1[i] = (A >> (tmp - 1 - i)) & 1;
        vec2[i] = (B >> (tmp - 1 - i)) & 1;
    }

    vector<vector<ll>> dp(tmp + 1, vector<ll>(16, 0));
    dp[0][0] = 1;

    for (int i = 0; i < tmp; i++) {
        for (int j = 0; j < 16; j++) {
            ll ways = dp[i][j];
            if (!ways) continue;

            int tmp2 = vec1[i], tmp3 = vec2[i];

            for (int k = 0; k < 2; k++) {
                for (int l = 0; l < 2; l++) {
                    int val = k ^ l;
                    for (int m = 0; m < 2; m++) {
                        int d = m ^ val;

                        if (!((j >> 0) & 1) && k > tmp2) continue;
                        int n1 = (j >> 0) & 1 | (k < tmp2);

                        if (!((j >> 1) & 1) && l > tmp2) continue;
                        int n2 = (j >> 1) & 1 | (l < tmp2);

                        if (!((j >> 2) & 1) && m > tmp3) continue;
                        int n3 = (j >> 2) & 1 | (m < tmp3);

                        if (!((j >> 3) & 1) && d > tmp3) continue;
                        int n4 = (j >> 3) & 1 | (d < tmp3);

                        int tmp4 = (n1) | (n2 << 1) | (n3 << 2) | (n4 << 3);
                        dp[i + 1][tmp4] = (dp[i + 1][tmp4] + ways) % MOD;
                    }
                }
            }
        }
    }

    ll res = 0;
    for (int i = 0; i < 16; i++) {
        res = (res + dp[tmp][i]) % MOD;
    }

    return res;
}

signed main() {
    fastio(); 
    docfile();
    
    int t; cin >> t;
    while (t--) {
        ll n, m, A, B; cin >> n >> m >> A >> B;
        
        ll tmp = (A + 1) % MOD, tmp2 = (B + 1) % MOD;
        ll tmp3 = (pow_mod(2, n) - 2 + MOD) % MOD, tmp4 = (pow_mod(2, m) - 2 + MOD) % MOD;
        
        ll res = tmp * tmp2 % MOD;
        res = (res + tmp * ((B * (B + 1) % MOD * pow_mod(2, MOD - 2) % MOD) * tmp4 % MOD)) % MOD;
        res = (res + tmp2 * ((A * (A + 1) % MOD * pow_mod(2, MOD - 2) % MOD) * tmp3 % MOD)) % MOD;
        res = (res + tmp3 * tmp4 % MOD * ((calc(A, B) - tmp * tmp2 % MOD + MOD) % MOD * pow_mod(4, MOD - 2) % MOD)) % MOD;
        
        cout << res << ln;
    }
    
    time(); 
    return 0;
}