// Author: huythedev (https://huythedev.com)
// Problem Link: https://oj.vnoi.info/problem/qbmax

#include <bits/stdc++.h>
using namespace std;

#define NAME "qbmax"
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

int main() {
    fastio();
    docfile();

    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    vector<vector<int>> dp(n, vector<int>(m, INT_MIN));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        dp[i][0] = a[i][0];
    }

    for (int j = 1; j < m; ++j) {
        for (int i = 0; i < n; ++i) {
            dp[i][j] = dp[i][j-1] + a[i][j];
            if (i > 0) dp[i][j] = max(dp[i][j], dp[i-1][j-1] + a[i][j]);
            if (i < n-1) dp[i][j] = max(dp[i][j], dp[i+1][j-1] + a[i][j]);
        }
    }

    int max_sum = INT_MIN;
    for (int i = 0; i < n; ++i) {
        max_sum = max(max_sum, dp[i][m-1]);
    }

    cout << max_sum << ln;

    time();
    return 0;
}