// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "mcdon"
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


vector<pair<int, int>> lr;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n), prefix_xor(n + 1, 0);
    for (int i = 0; i < n; ++i) 
        cin >> a[i];

    for (int i = 0; i < k; ++i) {
        int l, r; cin >> l >> r;
        lr.emplace_back(l, r);
    }

    for (int i = 1; i <= n; ++i)
        prefix_xor[i] = prefix_xor[i - 1] ^ a[i - 1];

    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
            for (int p = j - 1; p < i; ++p) {
                int val = prefix_xor[i] ^ prefix_xor[p];

                if (val >= lr[j - 1].first && val <= lr[j - 1].second)
                    dp[i][j] = (dp[i][j] + dp[p][j - 1]) % MOD;
            }
        }
    }

    cout << dp[n][k] << ln;
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