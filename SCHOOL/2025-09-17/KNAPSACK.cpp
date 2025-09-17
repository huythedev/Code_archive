// Author: huythedev
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

void solve() {
    int n; cin >> n;
    vector<int> w(n), v(n);
    for (int i = 0; i < n; ++i) 
        cin >> w[i] >> v[i];
    
    int q; cin >> q;
    ll res = 0;
    while (q--) {   
        int l, r, t; cin >> l >> r >> t;
        l--; r--;

        // vector<int> w2(r - l + 1), v2(r - l + 1);
        // for (int i = l; i <= r; ++i) {
        //     w2[i - l] = w[i];
        //     v2[i - l] = v[i];
        // }

        int m = r - l + 1;
        vector<ll> dp(t + 1, 0);
        for (int i = 0; i < m; ++i) {
            for (int j = t; j >= w[l + i]; --j) {
                dp[j] = max(dp[j], dp[j - w[l + i]] + v[l + i]);
            }
        }

        res += dp[t];
    }

    cout << res << ln;
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