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

const int INF = 1e9;

void solve() {
    string l, r; cin >> l >> r;
    
    int n = l.size();
    vector<vector<vector<int>>> dp(10, vector<vector<int>>(2, vector<int>(2, INF)));
    dp[0][1][1] = 0;
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                if(dp[i][j][k] >= INF) 
                    continue;

                int lo = j ? l[i] - '0' : 0;
                int hi = k ? r[i] - '0' : 9;
                for (int x = lo; x <= hi; ++x) {
                    int contrib = (l[i] - '0' == x) + (x == r[i] - '0');
                    int tmp = j && (x == l[i] - '0'), tmp2 = k && (x == r[i] - '0');
                    dp[i + 1][tmp][tmp2] = min(dp[i + 1][tmp][tmp2], dp[i][j][k] + contrib);
                }
            }
        }
    }
    
    int ans = INF;
    for(int i = 0; i < 2; ++i) {
        for(int j = 0; j < 2; ++j) {
            ans = min(ans, dp[n][i][j]);
        }
    }
    
    cout << ans << ln;
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