// Author: huythedev
// Problem Link: https://codeforces.com/contest/2109/problem/E
#include <bits/stdc++.h>
using namespace std;

#define NAME "E"
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

const int MOD = 998244353;

int flip(int s, int n, int i) {
    int mask = (1 << (i + 1)) - 1;
    return s ^ mask;
}

ll dp(int s, int n, int k, vector<vector<ll>>& vec) {
    if (k == 0) return 1;
    if (vec[s][k] != -1) return vec[s][k];

    ll res = 0;
    for (int i = 0; i < n; i++) {
        if (!(s & (1 << i))) {
            int next_s = flip(s, n, i);
            res = (res + dp(next_s, n, k - 1, vec)) % MOD;
        }
    }
    return vec[s][k] = res;
}

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int tmp = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            tmp |= (1 << i);
        }
    }

    vector<vector<ll>> vec(1 << n, vector<ll>(k + 1, -1));
    ll ans = dp(tmp, n, k, vec);
    cout << ans << ln;
}

signed main() {
    fastio();
    docfile();

    int t; cin >> t;
    while (t--) {
        solve();
    }

    time();
    return 0;
}