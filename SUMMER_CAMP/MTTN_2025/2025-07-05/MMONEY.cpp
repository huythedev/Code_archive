// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "MMONEY"
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
const int MAX_S = 6005;

int dp[MAX_S];
int tmp[MAX_S];

void solve() {
    int n, S; cin >> n >> S;

    memset(dp, 0, sizeof(dp));
    dp[0] = 1;

    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;

        memcpy(tmp, dp, sizeof(int) * (S + 1));

        for (int j = b; j <= S; j++) {
            tmp[j] = (tmp[j] + tmp[j - b]) % MOD;
        }

        for (int j = S; j >= 0; j--) {
            ll tmp2 = (ll)j - (ll)(a + 1) * b;

            if (tmp2 >= 0) {
                dp[j] = (tmp[j] - tmp[tmp2] + MOD) % MOD;
            } 
            else {
                dp[j] = tmp[j];
            }
        }
    }

    cout << dp[S] << ln;
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
