// Author: huythedev (https://huythedev.com)
// Problem Link: https://codeforces.com/contest/2075/problem/D
// davul
#include <bits/stdc++.h>
using namespace std;

#define NAME "D"
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

const int maxn = 60;
const ll INF = LLONG_MAX;
vector<tuple<int, int, ll>> vec;

void pre_process() {
    vector<vector<ll>> dp(maxn + 1, vector<ll>(maxn + 1, INF));
    dp[0][0] = 0;

    for (int i = 1; i <= maxn; i++) {
        vector<vector<ll>> dp2 = dp;
        for (int j = 0; j <= maxn; j++) {
            for (int k = 0; k <= maxn; k++) {
                if (dp[j][k] == INF) continue;
                if (j + i <= maxn) dp2[j + i][k] = min(dp2[j + i][k], dp[j][k] + static_cast<ll>(1ULL << i));
                if (k + i <= maxn) dp2[j][k + i] = min(dp2[j][k + i], dp[j][k] + static_cast<ll>(1ULL << i));
            }
        }
        dp = move(dp2);
    }

    for (int i = 0; i <= maxn; i++) {
        for (int j = 0; j <= maxn; j++) {
            if (dp[i][j] != INF) {
                vec.emplace_back(i, j, dp[i][j]);
            }
        }
    }
}

signed main() {
    fastio();
    docfile();
    pre_process();

    int T;
    cin >> T;
    while (T--) {
        ll x, y;
        cin >> x >> y;

        if (x == y) {
            cout << 0 << ln;
        }
        else {
            ll res = INF;
            for (tuple<int, int, ll> i : vec) {
                ll tmp1 = get<0>(i), tmp2 = get<1>(i), tmp3 = get<2>(i);
                ll X = x >> tmp1, Y = y >> tmp2;
                if (X == Y) {
                    res = min(res, tmp3);
                }
            }
        
            cout << res << ln;
        }
    }

    time();
    return 0;
}