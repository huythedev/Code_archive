// Author: huythedev
// Problem Link: https://codeforces.com/contest/2110/problem/B
#include <bits/stdc++.h>
using namespace std;

#define NAME "B"
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
    int tmp = 0, cnt = 0;
    for (char c : s) {
        if (c == '(') {
            tmp++;
        } else {
            tmp--;
        }
        if (tmp == 0) {
            cnt++;
        }
    }

    if (cnt > 1) {
        cout << "YES" << ln;
    } else {
        cout << "NO" << ln;
    }
}

signed main() {
    docfile();
    fastio();

    int t; cin >> t;
    while (t--) {
        solve();
    }

    time();
    return 0;
}