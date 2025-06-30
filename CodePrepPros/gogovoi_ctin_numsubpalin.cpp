// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "gogovoi_ctin_numsubpalin"
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
    string s; cin >> s;
    int n = (int)s.sz;

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = n - 1; j >= i; --j) {
            int l = i, r = j;
            bool palin = true;
            for (; l <= r; ) {
                if (s[l] != s[r]) {
                    palin = false;
                    break;
                }
                ++l; --r;
            }

            if (palin) ++ans;
        }
    }

    cout << ans << ln;
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