// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "C"
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

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> dp(n, 0), pref(n, 0);
    int ovr = 0;
    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            dp[i] = 0;
        } else {
            int x = a[i] - 2;
            int j = upper_bound(a.begin(), a.begin() + i, x) - a.begin();
            int tmp = (j > 0) ? pref[j - 1] + 1 : INT_MIN;
            dp[i] = max(ovr, tmp);
        }
        pref[i] = (i > 0) ? max(pref[i - 1], dp[i]) : dp[i];
        ovr = max(ovr, dp[i]);
    }
    int max_dp = *max_element(dp.begin(), dp.end());
   
    cout << max_dp + 1 << ln;
}

signed main() {
    docfile();
    fastio();

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    time();
    return 0;
}