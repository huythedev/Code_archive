// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "EXPRESS"
#define ln "\n"
#define sz size()

typedef long long ll;
typedef long double ld;

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void fileIO() {
    if (ifstream(NAME ".INP")) {
        freopen(NAME ".INP", "r", stdin);
        freopen(NAME ".OUT", "w", stdout);
    }
}

void time() {
    cerr << ln << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." 
         << ln;
}

ll calculate(ll a, ll b, char op) {
    if (op == '+') 
        return a + b;
    if (op == '-') 
        return a - b;
    return a * b;
}

void solve() {
    string s;
    cin >> s;

    vector<ll> numbers;
    vector<char> ops;

    for (int i = 0; i < s.sz; ++i) {
        if (i % 2 == 0)
            numbers.push_back(s[i] - '0');
        else
            ops.push_back(s[i]);
    }

    int n = numbers.size();
    if (n == 0) {
        cout << 0 << ln;
        return;
    }

    vector<vector<ll>> min_dp(n, vector<ll>(n, LLONG_MAX));
    vector<vector<ll>> max_dp(n, vector<ll>(n, LLONG_MIN));

    for (int i = 0; i < n; ++i) {
        min_dp[i][i] = numbers[i];
        max_dp[i][i] = numbers[i];
    }
    
    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i <= n - len; ++i) {
            int j = i + len - 1;
            for (int k = i; k < j; ++k) {
                char op = ops[k];

                ll val1 = calculate(min_dp[i][k], min_dp[k + 1][j], op);
                ll val2 = calculate(min_dp[i][k], max_dp[k + 1][j], op);
                ll val3 = calculate(max_dp[i][k], min_dp[k + 1][j], op);
                ll val4 = calculate(max_dp[i][k], max_dp[k + 1][j], op);
                
                min_dp[i][j] = min({min_dp[i][j], val1, val2, val3, val4});
                max_dp[i][j] = max({max_dp[i][j], val1, val2, val3, val4});
            }
        }
    }

    cout << min_dp[0][n - 1] << ln;
}

signed main() {
    fastIO();
    fileIO();

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    time();
    return 0;
}