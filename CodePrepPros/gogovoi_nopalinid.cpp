// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "gogovoi_nopalinid"
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

int cost(string s) {
    int n = (int)s.size();
    int len = 1;
    for (int i = 1; i < n; ++i) {
        if (s[i] == s[i - 1]) {
            len++;
            if (len >= 2) {
                if (i < n - 1) {
                    if (s[i - 1] == 'a' && s[i ])
                }
                else {

                }
            }
        } 
        else {
            len = 1;
        }
    }
}

void solve() {
    int n, m; cin >> n >> m;
    string s; cin >> s;
    while (m--) {
        int l, r; cin >> l >> r; 
        l--; r--;

        string s2 = s.substr(l, r - l + 1);
        cout << s2 << ln;
        cout << cost(s2) << ln;
    }
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