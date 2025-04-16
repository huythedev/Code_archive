// Author: huythedev (https://huythedev.com)
// Problem Link: https://oj.vnoi.info/problem/atcoder_dp_d
// davul
#include <bits/stdc++.h>
using namespace std;

#define NAME "atcoder_dp_d"
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

    int n, W;
    cin >> n >> W;
    vector<int> weight(n), value(n);
    for (int i = 0; i < n; ++i) {
        cin >> weight[i] >> value[i];
    }

    vector<ll> dp(W + 1, 0);
    for (int i = 0; i < n; ++i) {
        for (int w = W; w >= weight[i]; --w) {
            dp[w] = max(dp[w], dp[w - weight[i]] + value[i]);
        }
    }

    cout << dp[W] << ln;

    time();
    return 0;
}