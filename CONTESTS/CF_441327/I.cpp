// Author: huythedev
// Problem Link: https://codeforces.com/group/GmBcp47v69/contest/441327/problem/I
#include <bits/stdc++.h>
using namespace std;

#define NAME "I"
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

bool isPerfectSqrt(int n) {
    int sq = sqrt(n);
    return sq * sq == n;
}

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    vector<int> dp(n, 1);
    int res = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = max(0, i - 10); j < i; ++j) {
            int diff = abs(a[i] - a[j]);
            if (diff > 0 && isPerfectSqrt(diff)) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        res = max(res, dp[i]);
    }
    
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