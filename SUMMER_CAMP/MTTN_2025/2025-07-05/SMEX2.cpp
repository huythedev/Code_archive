// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "SMEX2"
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

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

    for (int m = 0; m <= n + 1; ++m) {
        dp[n][m] = 1;
    }

    for (int i = n - 1; i >= 0; --i) {
        vector<ll> vec(n + 2, 0);
        
        vector<bool> seen(n + 1, false);
        int curr = 0;
        
        for (int j = i; j < n; ++j) {
            if (a[j] <= n) {
                seen[a[j]] = true;
            }
            while (seen[curr]) {
                curr++;
            }
            
            vec[curr] = (vec[curr] + dp[j + 1][curr]) % MOD;
        }

        for (int m = n; m >= 0; --m) {
            dp[i][m] = (dp[i][m + 1] + vec[m]) % MOD;
        }
    }

    cout << dp[0][0] << ln;
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