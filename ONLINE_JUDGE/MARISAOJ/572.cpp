// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "572"
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

const int LIM = 1e5 + 5;

int n;
vector<int> t(LIM), r(LIM);
vector<int> mem(LIM);

int minTime() {
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    dp[1] = t[0];
    for (int i = 2; i <= n; ++i) {
        dp[i] = min(dp[i], dp[i - 1] + t[i - 1]);
        dp[i] = min(dp[i], dp[i - 2] + r[i - 1]);
    }
    return dp[n];
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> t[i];
    for (int i = 1; i < n; ++i)
        cin >> r[i];

    cout << minTime() << ln;
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