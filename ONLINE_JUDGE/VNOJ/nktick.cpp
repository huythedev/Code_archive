// Author: huythedev (https://huythedev.com)
// Problem Link: https://oj.vnoi.info/problem/nktick

#include <bits/stdc++.h>
using namespace std;

#define NAME "nktick"
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

    int n;
    cin >> n;
    vector<int> t1(n), t2(n - 1);
    for (int i = 0; i < n; ++i) cin >> t1[i];
    for (int i = 0; i < n - 1; ++i) cin >> t2[i];

    vector<ll> dp(n);
    dp[0] = t1[0];
    dp[1] = min(t1[0] + t1[1], t2[0]);

    for (int i = 2; i < n; ++i) {
        dp[i] = min(dp[i - 1] + t1[i], dp[i - 2] + t2[i - 1]);
    }

    cout << dp[n - 1] << ln;

    time();
    return 0;
}