// Author: huythedev (https://huythedev.com)
// Problem Link: https://codeforces.com/problemset/problem/1/A

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

signed main() {
    fastio();
    docfile();

    ll n, m, a;
    cin >> n >> m >> a;

    ll flagstones_needed = ((n + a - 1) / a) * ((m + a - 1) / a);
    cout << flagstones_needed << ln;

    time();
    return 0;
}