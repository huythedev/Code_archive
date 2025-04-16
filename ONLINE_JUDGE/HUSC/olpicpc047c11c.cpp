// Author: huythedev (https://huythedev.com)
// Problem Link: https://coder.husc.edu.vn/problem/olpicpc047c11c
// davul
#include <bits/stdc++.h>
using namespace std;

#define NAME "olpicpc047c11c"
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

vector<vector<ll>> dp;

ll solve(int n, bool isAlice) {
    if (n == 0) return 0;
    if (n == 1) return isAlice ? 1 : 0;
    
    if (dp[n][isAlice] != -1) return dp[n][isAlice];
    
    // Take 1 coin
    ll result = isAlice ? 1 : 0;
    result += solve(n-1, !isAlice);
    
    if (n % 2 == 0) {
        ll tmp = (isAlice ? n/2 : 0) + solve(n/2, !isAlice);
        if ((isAlice && tmp > result) || (!isAlice && tmp < result))
            result = tmp;
    }
    
    return dp[n][isAlice] = result;
}

int main() {
    fastio();
    docfile();
    
    int n;
    cin >> n;
    dp.assign(n + 1, vector<ll>(2, -1));
    cout << solve(n, true);
    
    time();
    return 0;
}