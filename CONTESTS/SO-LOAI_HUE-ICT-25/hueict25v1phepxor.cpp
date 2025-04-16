// Author: huythedev (https://huythedev.com)
// Problem Link: https://coder.husc.edu.vn/problem/hueict25v1phepxor
// davul
#include <bits/stdc++.h>
using namespace std;

#define NAME "hueict25v1phepxor"
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

const int MOD = 1e9 + 7;

signed main() {
    fastio();
    docfile();

    ll L, R;
    cin >> L >> R;

    ll res = 0;

    for (ll x = L; x <= R; ++x) {
        for (ll y = L; y <= R; ++y) {
            for (ll z = L; z <= R; ++z) {
                for (ll t = L; t <= R; ++t) {
                    res = (res + ((x ^ y) ^ (z ^ t))) % MOD;
                }
            }
        }
    }

    cout << res << ln;

    time();
    return 0;
}
