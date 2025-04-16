// Author: huythedev (https://huythedev.com)
// Problem Link: https://codeforces.com/problemset/problem/189/A
// davul
#include <bits/stdc++.h>
using namespace std;

#define NAME "NAME"
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

signed main() {
    fastio();
    docfile();

    int n, a, b, c;
    cin >> n >> a >> b >> c;
    vector<int> dp(n + 1, -1);
    dp[0] = 0;

    for (int i = 0; i <= n; ++i) {
        if (dp[i] != -1) {
            if (i + a <= n) dp[i + a] = max(dp[i + a], dp[i] + 1);
            if (i + b <= n) dp[i + b] = max(dp[i + b], dp[i] + 1);
            if (i + c <= n) dp[i + c] = max(dp[i + c], dp[i] + 1);
        }
    }

    cout << dp[n] << ln;

    time();
    return 0;
}