// Author: huythedev (https://huythedev.com)
// Problem Link: https://codeforces.com/problemset/problem/1335/A

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
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        cout << (n - 1) / 2 << ln;
    }
}

signed main() {
    fastio();
    docfile();
    solve();
    time();
    return 0;
}