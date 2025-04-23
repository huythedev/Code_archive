// Author: huythedev (https://huythedev.com)
// Problem Link: https://oj.vnoi.info/problem/phuccnh_backpack

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

int main() {
    fastio();
    docfile();

    int n, m;
    cin >> m >> n;
    vector<int> C(n);
    for (int i = 0; i < n; ++i) {
        cin >> C[i];
    }

    vector<ll> dp(m + 1, 0);
    dp[0] = 1; 

    for (int i = 0; i < n; ++i) {
        for (int j = C[i]; j <= m; ++j) {
            dp[j] += dp[j - C[i]];
        }
    }

    cout << dp[m];

    time();
    return 0;
}