// Author: Perry (https://perrythedev.com)
// Problem Link: https://oj.vnoi.info/problem/atcoder_dp_c
// davul
#include <bits/stdc++.h>
using namespace std;

#define NAME "atcoder_dp_c"
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
    vector<vector<int>> happiness(n, vector<int>(3));
    for (int i = 0; i < n; ++i) {
        cin >> happiness[i][0] >> happiness[i][1] >> happiness[i][2];
    }

    vector<vector<int>> dp(n, vector<int>(3, 0));
    dp[0][0] = happiness[0][0];
    dp[0][1] = happiness[0][1];
    dp[0][2] = happiness[0][2];

    for (int i = 1; i < n; ++i) {
        dp[i][0] = happiness[i][0] + max(dp[i-1][1], dp[i-1][2]);
        dp[i][1] = happiness[i][1] + max(dp[i-1][0], dp[i-1][2]);
        dp[i][2] = happiness[i][2] + max(dp[i-1][0], dp[i-1][1]);
    }

    int max_happiness = max({dp[n-1][0], dp[n-1][1], dp[n-1][2]});
    cout << max_happiness << ln;

    time();
    return 0;
}