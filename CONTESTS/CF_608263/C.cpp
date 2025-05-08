// Author: huythedev
// Problem Link: https://codeforces.com/group/G0iFI97YZN/contest/608263/problem/C
#include <bits/stdc++.h>
using namespace std;

#define NAME "C"
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

const int MAX_N = 4e4;
const int MOD = 1e9 + 7;

vector<int> palin;
int dp[MAX_N + 1];

bool is_palindrome(int n) {
    string s = to_string(n);
    string s2 = s;
    reverse(s2.begin(), s2.end());
    return s == s2;
}

void precompute() {
    for (int i = 1; i <= MAX_N; ++i) {
        if (is_palindrome(i)) {
            palin.push_back(i);
        }
    }

    dp[0] = 1;
    for (int i : palin) {
        for (int j = i; j <= MAX_N; ++j) {
            dp[j] = (dp[j] + dp[j - i]) % MOD;
        }
    }
}

signed main() {
    fastio();
    docfile();
    precompute();

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        cout << dp[n] << ln;
    }

    time();
    return 0;
}