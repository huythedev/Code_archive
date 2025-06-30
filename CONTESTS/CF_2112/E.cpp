// Author: huythedev
// Problem Link: 
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

const int MAXM = 5e5 + 5;
const int INF = 1e9 + 7;

int dp[MAXM];

void precompute() {
    fill(dp, dp + MAXM, INF);
    dp[1] = 0;

    for (int x = 3; x < MAXM; ++x) {
        int p = x - 2;
        if (dp[p] == INF) 
            continue;

        int s = 1 + dp[p];
        
        for (int i = 1; (ll)i * x < MAXM; ++i) {
            if (dp[i] != INF) 
                dp[i * x] = min(dp[i * x], dp[i] + s);
        }
    }
}

void solve() {
    int m; cin >> m;
    if (dp[m] == INF) cout << "-1" << ln;
    else cout << dp[m] + 1 << ln;
}

signed main() {
    docfile();
    fastio();
    precompute();

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    time();
    return 0;
}