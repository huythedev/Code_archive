// Author: huythedev
// Problem Link: https://codeforces.com/contest/2111/problem/A
#include <bits/stdc++.h>
using namespace std;

#define NAME "A"
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
    int x; 
    cin >> x;

    int l = 32 - __builtin_clz(x);
    cout << 2 * l + 1 << ln;
}

signed main() {
    docfile();
    fastio();    
    
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    time();
    return 0;
}