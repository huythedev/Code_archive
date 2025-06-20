// Author: huythedev
// Problem Link: https://marisaoj.com/problem/523
#include <bits/stdc++.h>
using namespace std;

#define NAME "523"
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

void solve() {
    int n; cin >> n;
    vector<bitset<26>> vec(n);
    for (int i = 0; i < n; ++i) {
        string st; cin >> st;
        for (char c : st) {
            vec[i][c - 'a'] = 1;
        }
        // cout << vec[i] << ln;
    }

    bitset<26> az;
    az.set();
    int res = 0;
    for (int i = 0; i < (1 << n); ++i) {
        bitset<26> bs(0);
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                bs |= vec[j];
            }
        }

        if (bs == az) ++res;
    }

    cout << res << ln;
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