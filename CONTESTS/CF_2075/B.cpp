// Author: huythedev (https://huythedev.com)
// Problem Link: https://codeforces.com/contest/2075/problem/B

#include <bits/stdc++.h>
using namespace std;

#define NAME "B"
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

const ll INF = LLONG_MIN;

void solve(int n, int k, vector<ll> a) {
    vector<vector<ll>> dp(n + 1);
    dp[0].resize(1, 0);
    for (int i = 1; i <= n; i++) {
        int tmp = min(i, k);
        dp[i].resize(tmp + 1, INF);
        int prev = dp[i - 1].size();

        for (int j = 0; j < prev; j++)
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);

        for (int j = 1; j <= tmp; j++) {
            if (j - 1 < dp[i - 1].size() && dp[i - 1][j - 1] != INF) 
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + a[i - 1]);
        }
    } 

    vector<vector<ll>> dp2(n + 1);
    dp2[n].resize(1, 0);
    for (int i = n - 1; i >= 0; i--) {
        int tmp = min(n - i, k);
        dp2[i].resize(tmp + 1, INF);
        int tmp2 = dp2[i + 1].size();

        for (int j = 0; j < tmp2; j++) 
            dp2[i][j] = max(dp2[i][j], dp2[i + 1][j]);

        for (int j = 1; j <= tmp; j++) 
            if (j - 1 < dp2[i + 1].size() && dp2[i + 1][j - 1] != INF) 
                dp2[i][j] = max(dp2[i][j], dp2[i + 1][j - 1] + a[i]);
    }

    ll res = 0;
    for (int i = 0; i < n; i++) {
        ll tmp = INF;
        if (i == 0) 
            tmp = a[0] + dp2[1][k];
        else if (i == n - 1) 
            tmp = a[n - 1] + dp[n - 1][k];
        else {
            int l = i, r = n - i - 1;

            for (int j = 1; j <= min(k - 1, l); j++) {
                int tmp2 = k - j;

                if (tmp2 < 1 || tmp2 > r) continue;

                if (j < dp[i].size() && tmp2 < dp2[i + 1].size()) {
                    if (dp[i][j] == INF || dp2[i + 1][tmp2] == INF) continue;
                    tmp = max(tmp, a[i] + dp[i][j] + dp2[i + 1][tmp2]);
                }
            }
        }
        res = max(res, tmp);
    }

    cout << res << ln;
}

signed main() {
    fastio();
    docfile();

    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        solve(n, k, a);
    }

    time();
    return 0;
}