// Author: huythedev
// Problem Link: https://codeforces.com/group/G0iFI97YZN/contest/608792/problem/A
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
    int n; cin >> n;
    vector<int> a(n);
    for (int &i : a) cin >> i;

    
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