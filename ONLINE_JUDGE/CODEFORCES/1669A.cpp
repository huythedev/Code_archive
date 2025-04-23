// Author: huythedev (https://huythedev.com)
// Problem Link: https://codeforces.com/problemset/problem/1669/A

#include <bits/stdc++.h>
using namespace std;

#define NAME "NAME"
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
    int rating;
    cin >> rating;
    if (rating >= 1900) {
        cout << "Division 1" << ln;
    } else if (rating >= 1600) {
        cout << "Division 2" << ln;
    } else if (rating >= 1400) {
        cout << "Division 3" << ln;
    } else {
        cout << "Division 4" << ln;
    }
}

signed main() {
    fastio();
    docfile();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    time();
    return 0;
}